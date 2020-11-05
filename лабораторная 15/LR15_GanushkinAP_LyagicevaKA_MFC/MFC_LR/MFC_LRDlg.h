
// MFC_LRDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCLRDlg
class CMFCLRDlg : public CDialogEx
{
// Создание
public:
	CMFCLRDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_LR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	double m_cost;
	double m_consumption;
	double m_km;
	double m_res;
	CEdit m_text;
	CEdit m_costControl;
	CEdit m_consControl;
	int m_textPoezd;
	double fullKm = 0;
	double fullPrice = 0;
	afx_msg void OnBnClickedButton2();
	double m_fullPrice;
	CEdit m_kmControl;
	afx_msg void OnBnClickedButton3();
};
