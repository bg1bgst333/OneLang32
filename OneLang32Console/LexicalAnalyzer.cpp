// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <iostream>	// C++�W�����o��
// �Ǝ��̃w�b�_
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer

// ��͂����s���郁���o�֐�Analyze.
BOOL CLexicalAnalyzer::Analyze(tstring tstrSourceFileName){

	// �����o�̃Z�b�g.
	m_tstrSourceFileName = tstrSourceFileName;	// tstrSourceFileName��m_tstrSourceFileName�ɃZ�b�g.

	// �g�[�N�����X�g�̃N���A.
	m_vectstrTokenList.clear();	// m_vectstrTokenList���N���A.

	// "CLexicalAnalyzer::Analyze!"�ƕ\��.
	std::wcout << _T("CLexicalAnalyzer::Analyze!") << std::endl;	// "CLexicalAnalyzer::Analyze!"���o��.

	// �߂�l��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}