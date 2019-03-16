// 二重インクルード防止
#ifndef __SYNTAX_INFO_H__
#define __SYNTAX_INFO_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>		// TCHAR型
#include <windows.h>	// 標準WindowsAPI

// 構文情報を格納する構造体SyntaxInfo
struct SyntaxInfo{
	unsigned int m_iID;	// ID
};

#endif