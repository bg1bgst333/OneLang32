// ヘッダファイルのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR型
#include <stdio.h>	// 標準入出力
// 独自のヘッダ
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer
#include "SyntaxAnalyzer.h"		// CSyntaxAnalyzer

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// コマンド引数の処理.
	if (argc == 1){	// argcが1の時.

		// "Hello, OneLang!"と出力.
		_tprintf(_T("Hello, OneLang!\n"));	// "Hello, OneLang!"と出力.

	}
	else{	// argcが2以上の時.(Win32Consoleのargcは0にならないため.)

		// コンパイル対象のソースコードファイル名を出力.
		_tprintf(_T("argv[1] = %s\n"), argv[1]);	// _tprintfでargv[1]を出力.

		// 字句解析オブジェクトの作成.
		CLexicalAnalyzer *pLexicalAnalyzer = new CLexicalAnalyzer();	// CLexicalAnalyzerオブジェクトを作成し, ポインタpLexicalAnalyzerに格納.
		
		// 字句解析.
		pLexicalAnalyzer->Analyze(argv[1]);	// pLexicalAnalyzer->Analyzeでargv[1]にあるソースを解析.

		// 構文解析オブジェクトの作成.
		CSyntaxAnalyzer *pSyntaxAnalyzer = new CSyntaxAnalyzer();	// CSyntaxAnalyzerオブジェクトを作成し, ポインタpSyntaxAnalyzerに格納.

		// 構文解析.
		pSyntaxAnalyzer->Analyze(pLexicalAnalyzer);	// pSyntaxAnalyzer->AnalyzeでpLexicalAnalyzerにあるトークンを構文解析.

		// 構文解析オブジェクトの解放.
		delete pSyntaxAnalyzer;	// pSyntaxAnalyzerを解放.

		// 字句解析オブジェクトの解放.
		delete pLexicalAnalyzer;	// pLexicalAnalyzerを解放.

	}

	// プログラムの終了
	return 0;	// returnで0を返して正常終了.

}