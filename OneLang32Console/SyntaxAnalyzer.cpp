// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "SyntaxAnalyzer.h"	// CSyntaxAnalyzer

// ��͂����s���郁���o�֐�Analyze.
BOOL CSyntaxAnalyzer::Analyze(CLexicalAnalyzer *pLA){

	// �J�n
	_tprintf(_T("CSyntaxAnalyzer::Analyze Start\n"));	// "CSyntaxAnalyzer::Analyze Start"���o��.

	// 0�Ԗڂ��o��.
	_tprintf(_T("GetToken(0) = %s\n"), pLA->GetToken(0).c_str());	// pLA->GetToken(0)���o��.

	// �I��
	_tprintf(_T("CSyntaxAnalyzer::Analyze End\n"));	// "CSyntaxAnalyzer::Analyze End"���o��.

	// �߂�l��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}