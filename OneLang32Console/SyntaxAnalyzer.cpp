// ヘッダのインクルード
// 独自のヘッダ
#include "SyntaxAnalyzer.h"	// CSyntaxAnalyzer

// 解析を実行するメンバ関数Analyze.
BOOL CSyntaxAnalyzer::Analyze(CLexicalAnalyzer *pLA){

	// 開始
	_tprintf(_T("CSyntaxAnalyzer::Analyze Start\n"));	// "CSyntaxAnalyzer::Analyze Start"を出力.

	// 0番目を出力.
	_tprintf(_T("GetToken(0) = %s\n"), pLA->GetToken(0).c_str());	// pLA->GetToken(0)を出力.

	// 終了
	_tprintf(_T("CSyntaxAnalyzer::Analyze End\n"));	// "CSyntaxAnalyzer::Analyze End"を出力.

	// 戻り値を返す.
	return TRUE;	// TRUEを返す.

}