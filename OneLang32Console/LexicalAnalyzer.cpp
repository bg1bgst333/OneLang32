// ヘッダのインクルード
// 既定のヘッダ
#include <iostream>	// C++標準入出力
// 独自のヘッダ
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer

// 解析を実行するメンバ関数Analyze.
BOOL CLexicalAnalyzer::Analyze(tstring tstrSourceFileName){

	// メンバのセット.
	m_tstrSourceFileName = tstrSourceFileName;	// tstrSourceFileNameをm_tstrSourceFileNameにセット.

	// トークンリストのクリア.
	m_vectstrTokenList.clear();	// m_vectstrTokenListをクリア.

	// "CLexicalAnalyzer::Analyze!"と表示.
	std::wcout << _T("CLexicalAnalyzer::Analyze!") << std::endl;	// "CLexicalAnalyzer::Analyze!"を出力.

	// 戻り値を返す.
	return TRUE;	// TRUEを返す.

}