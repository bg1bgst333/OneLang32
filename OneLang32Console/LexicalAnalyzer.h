// ��d�C���N���[�h�h�~
#ifndef __LEXICAL_ANALYZER_H__
#define __LEXICAL_ANALYZER_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR�^
#include <string>	// std::string
#include <vector>	// std::vector
#include <windows.h>	// �W��WindowsAPI

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �����̓N���XCLexicalAnalyzer
class CLexicalAnalyzer{

	// private�����o
	private:

		// private�����o�ϐ�
		tstring m_tstrSourceFileName;	// �\�[�X�t�@�C����
		std::vector<tstring> m_vectstrTokenList;	// �g�[�N�����X�g

	// public�����o
	public:

		// �R���X�g���N�^�ƃf�X�g���N�^
		CLexicalAnalyzer(){};	// �R���X�g���N�^CLexicalAnalyzer
		virtual ~CLexicalAnalyzer(){};	// �f�X�g���N�^~CLexicalAnalyzer
		// public�����o�֐�
		BOOL Analyze(tstring tstrSourceFileName);	// ��͂����s���郁���o�֐�Analyze.

};

#endif
