
// MFC_LR.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLRApp:
// Сведения о реализации этого класса: MFC_LR.cpp
//

class CMFCLRApp : public CWinApp
{
public:
	CMFCLRApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCLRApp theApp;
