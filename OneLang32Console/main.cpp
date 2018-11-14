// ヘッダファイルのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR型
#include <stdio.h>	// 標準入出力

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// "Hello, OneLang!"と出力.
	_tprintf(_T("Hello, OneLang!\n"));	// "Hello, OneLang!"と出力.

	// プログラムの終了
	return 0;	// returnで0を返して正常終了.

}