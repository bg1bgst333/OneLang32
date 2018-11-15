// ヘッダのインクルード
// 既定のヘッダ
#include <iostream>	// C++標準入出力
// 独自のヘッダ
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer
#include "TextFile.h"	// CTextFile

// 解析を実行するメンバ関数Analyze.
BOOL CLexicalAnalyzer::Analyze(tstring tstrSourceFileName){

	// メンバのセット.
	m_tstrSourceFileName = tstrSourceFileName;	// tstrSourceFileNameをm_tstrSourceFileNameにセット.

	// トークンリストのクリア.
	m_vectstrTokenList.clear();	// m_vectstrTokenListをクリア.

	// "CLexicalAnalyzer::Analyze!"と表示.
	std::wcout << _T("CLexicalAnalyzer::Analyze!") << std::endl;	// "CLexicalAnalyzer::Analyze!"を出力.

	// ソースコードファイルを読み込み, 出力.
	CTextFile *pTextFile = new CTextFile();	// CTextFileオブジェクトを作成し,  ポインタをpTextFileに格納.
	if (pTextFile->Read(m_tstrSourceFileName.c_str())){	// pTextFile->Readで読み込み.
		std::wcout << _T("----- start -----") << std::endl;	// "----- start -----"と出力.
		std::wcout << pTextFile->m_tstrText << std::endl;	// pTextFile->m_tstrTextの内容を出力.
		std::wcout << _T("----- end -----") << std::endl;	// "----- start -----"と出力.
	}
	else{	// 読み込み失敗.
		std::wcout << _T("Read Failure!") << std::endl;	// "Read Failure!"と出力.
	}
	delete pTextFile;	// pTextFileを解放.

	// 戻り値を返す.
	return TRUE;	// TRUEを返す.

}