// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR�^
#include <stdio.h>	// �W�����o��
// �Ǝ��̃w�b�_
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer
#include "SyntaxAnalyzer.h"		// CSyntaxAnalyzer

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �R�}���h�����̏���.
	if (argc == 1){	// argc��1�̎�.

		// "Hello, OneLang!"�Əo��.
		_tprintf(_T("Hello, OneLang!\n"));	// "Hello, OneLang!"�Əo��.

	}
	else{	// argc��2�ȏ�̎�.(Win32Console��argc��0�ɂȂ�Ȃ�����.)

		// �R���p�C���Ώۂ̃\�[�X�R�[�h�t�@�C�������o��.
		_tprintf(_T("argv[1] = %s\n"), argv[1]);	// _tprintf��argv[1]���o��.

		// �����̓I�u�W�F�N�g�̍쐬.
		CLexicalAnalyzer *pLexicalAnalyzer = new CLexicalAnalyzer();	// CLexicalAnalyzer�I�u�W�F�N�g���쐬��, �|�C���^pLexicalAnalyzer�Ɋi�[.
		
		// ������.
		pLexicalAnalyzer->Analyze(argv[1]);	// pLexicalAnalyzer->Analyze��argv[1]�ɂ���\�[�X�����.

		// �\����̓I�u�W�F�N�g�̍쐬.
		CSyntaxAnalyzer *pSyntaxAnalyzer = new CSyntaxAnalyzer();	// CSyntaxAnalyzer�I�u�W�F�N�g���쐬��, �|�C���^pSyntaxAnalyzer�Ɋi�[.

		// �\�����.
		pSyntaxAnalyzer->Analyze(pLexicalAnalyzer);	// pSyntaxAnalyzer->Analyze��pLexicalAnalyzer�ɂ���g�[�N�����\�����.

		// �\����̓I�u�W�F�N�g�̉��.
		delete pSyntaxAnalyzer;	// pSyntaxAnalyzer�����.

		// �����̓I�u�W�F�N�g�̉��.
		delete pLexicalAnalyzer;	// pLexicalAnalyzer�����.

	}

	// �v���O�����̏I��
	return 0;	// return��0��Ԃ��Đ���I��.

}