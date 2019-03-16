// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <iostream>	// C++�W�����o��
// �Ǝ��̃w�b�_
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer
#include "TextFile.h"	// CTextFile

// ��͂����s���郁���o�֐�Analyze.
BOOL CLexicalAnalyzer::Analyze(tstring tstrSourceFileName){

	// �����o�̃Z�b�g.
	m_tstrSourceFileName = tstrSourceFileName;	// tstrSourceFileName��m_tstrSourceFileName�ɃZ�b�g.

	// �g�[�N�����X�g�̃N���A.
	m_vectstrTokenList.clear();	// m_vectstrTokenList���N���A.

	// "CLexicalAnalyzer::Analyze!"�ƕ\��.
	std::wcout << _T("CLexicalAnalyzer::Analyze!") << std::endl;	// "CLexicalAnalyzer::Analyze!"���o��.

	// �\�[�X�R�[�h�t�@�C����ǂݍ���, �o��.
	CTextFile *pTextFile = new CTextFile();	// CTextFile�I�u�W�F�N�g���쐬��,  �|�C���^��pTextFile�Ɋi�[.
	if (pTextFile->Read(m_tstrSourceFileName.c_str())){	// pTextFile->Read�œǂݍ���.
		
		// �ǂݍ��񂾃e�L�X�g���o��.
		std::wcout << _T("----- start -----") << std::endl;	// "----- start -----"�Əo��.
		//std::wcout << pTextFile->m_tstrText << std::endl;	// pTextFile->m_tstrText�̓��e���o��.
		std::wcout << _T("----- end -----") << std::endl;	// "----- end -----"�Əo��.
		
		// 1�������`�F�b�N.
		tstring tstrToken = _T("");	// ������g�[�N����""�ŏ�����.
		// ����.
		for (unsigned int i = 0; i < pTextFile->m_tstrText.length(); i++){	// �����񒷌J��Ԃ�.
			unsigned int ch = pTextFile->m_tstrText.c_str()[i];	// i�Ԗڂ�ch�Ɋi�[.
			if ((ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A)){	// �A���t�@�x�b�g�̏ꍇ.
				tstrToken = tstrToken + pTextFile->m_tstrText.at(i);	// i�Ԗڂ�A��.
			}
			else if (ch > 0xff){	// 2�o�C�g�����̏ꍇ���A���t�@�x�b�g�Ɠ���.(�\�[�X�R�[�h�̕����R�[�h�֌W�Ȃ����C�h����(UTF16)�Ƃ��ēǂݍ��܂�邽�ߓ��{��̔��肪��r�I�e��.)
				// �擪��"<WCS>"�ƕt����ꍇ������.
				if (tstrToken  == _T("")){	// tstrToken����.
					tstrToken = _T("<WCS>");	// "<WCS>"����.
				}
				else{	// �����łȂ��ꍇ�ł����肦��.
					unsigned int top = tstrToken.c_str()[0];	// �g�[�N���̃��C�h�����̐擪��ASCII�R�[�h���擾.
					if ((top >= 0x41 && top <= 0x5A) || (top >= 0x61 && top <= 0x7A)){	// �A���t�@�x�b�g�̏ꍇ.
						tstrToken = _T("<WCS>") + tstrToken;	// �擪��"<WCS>"��t����.
					}
					// ����ȊO�ŗႦ��"a��a��"�̏ꍇ, "a��"�̎��_��"<WCS>a��"�Ńg�[�N�����ێ�����Ă���̂�, ���̂��Ƃ�"a"�͂��̂܂ܘA��, ���̂��Ƃ�"��"�̓g�[�N���擪��"<"�Ȃ̂�, ���ʓI�ɐ擪��"<WCS>"�t�������ꂸ"��"���A�������.
				}
				tstrToken = tstrToken + pTextFile->m_tstrText.at(i);	// i�Ԗڂ�A��.
			}
			else if (ch == 0x20){	// �X�y�[�X.
				if (tstrToken != _T("")){	// �����񂪓����Ă���.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenList�ɒǉ�.
				}
				m_vectstrTokenList.push_back(_T("<Space>"));	// "<Space>"��ǉ�.
				tstrToken = _T("");	// ""�Ń��Z�b�g.
			}
			else if (ch == 0x0d){	// CR.
				if (tstrToken != _T("")){	// �����񂪓����Ă���.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenList�ɒǉ�.
				}
				m_vectstrTokenList.push_back(_T("<CR>"));	// "<CR>"��ǉ�.
				tstrToken = _T("");	// ""�Ń��Z�b�g.
			}
			else if (ch == 0x0a){	// LF.
				if (tstrToken != _T("")){	// �����񂪓����Ă���.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenList�ɒǉ�.
				}
				m_vectstrTokenList.push_back(_T("<LF>"));	// "<LF>"��ǉ�.
				tstrToken = _T("");	// ""�Ń��Z�b�g.
			}
			else{	// �L�����̑�.
				if (tstrToken != _T("")){	// �����񂪓����Ă���.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenList�ɒǉ�.
				}
				TCHAR tch[2] = {0};	// tch�̏�����.
				tch[0] = pTextFile->m_tstrText.at(i);	// i�Ԗڂ�tch�Ɋi�[.
				tstring ts = tch;	// ts��tch���i�[.
				m_vectstrTokenList.push_back(ts);	// ts��ǉ�.
				tstrToken = _T("");	// ""�Ń��Z�b�g.
			}
		}
		// �Ō�̕����o��.
		if (tstrToken != _T("")){	// �����񂪓����Ă���.
			m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenList�ɒǉ�.
		}
		// �g�[�N���ꗗ���o��.
		for (unsigned int i = 0; i < m_vectstrTokenList.size(); i++){ // �g�[�N�����X�g���J��Ԃ�.
			// ���C�h�����̓R���\�[���o�͂��������̂�, �o�͂��ȒP�ȃ��m��㗝�ŏo��.
			if (m_vectstrTokenList[i].find(_T("<WCS>")) != std::string::npos){	// "<WCS>"���������ꍇ.
				//std::wcout << _T("<WCS>") << std::endl;	// "<WCS>"���o��.
			}
			else{	// ����ȊO.
				//std::wcout << m_vectstrTokenList[i] << std::endl;	// i�Ԗڂ��o��.
			}
		}

	}
	else{	// �ǂݍ��ݎ��s.
		std::wcout << _T("Read Failure!") << std::endl;	// "Read Failure!"�Əo��.
	}
	delete pTextFile;	// pTextFile�����.

	// �߂�l��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}

// �w�肳�ꂽ�ԍ��̃g�[�N�����擾���郁���o�֐�GetToken.
tstring CLexicalAnalyzer::GetToken(unsigned int uiNo){

	// uiNo�Ԗڂ�Ԃ�.
	return m_vectstrTokenList[uiNo];	// m_vectstrTokenList[uiNo]��Ԃ�.

}