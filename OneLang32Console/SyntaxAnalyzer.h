// ��d�C���N���[�h�h�~
#ifndef __SYNTAX_ANALYZER_H__
#define __SYNTAX_ANALYZER_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR�^
#include <string>	// std::string
#include <vector>	// std::vector
#include <windows.h>	// �W��WindowsAPI
// �Ǝ��̃w�b�_
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer
#include "SyntaxInfo.h"	// �\����SyntaxInfo

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �\����̓N���XCSyntaxAnalyzer
class CSyntaxAnalyzer{

	// private�����o
	private:

		// private�����o�ϐ�
		std::vector<SyntaxInfo> m_vecsiSyntaxTable;	// �\���e�[�u��

	// public�����o
	public:

		// �R���X�g���N�^�ƃf�X�g���N�^
		CSyntaxAnalyzer(){};	// �R���X�g���N�^CSyntaxAnalyzer
		virtual ~CSyntaxAnalyzer(){};	// �f�X�g���N�^~CSyntaxAnalyzer
		// public�����o�֐�
		BOOL Analyze(CLexicalAnalyzer *pLA);	// ��͂����s���郁���o�֐�Analyze.

};

#endif