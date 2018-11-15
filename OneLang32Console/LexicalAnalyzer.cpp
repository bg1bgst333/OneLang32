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
		std::wcout << _T("----- start -----") << std::endl;	// "----- start -----"�Əo��.
		std::wcout << pTextFile->m_tstrText << std::endl;	// pTextFile->m_tstrText�̓��e���o��.
		std::wcout << _T("----- end -----") << std::endl;	// "----- start -----"�Əo��.
	}
	else{	// �ǂݍ��ݎ��s.
		std::wcout << _T("Read Failure!") << std::endl;	// "Read Failure!"�Əo��.
	}
	delete pTextFile;	// pTextFile�����.

	// �߂�l��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}