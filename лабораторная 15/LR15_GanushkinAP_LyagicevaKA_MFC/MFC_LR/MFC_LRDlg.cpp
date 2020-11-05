
// MFC_LRDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_LR.h"
#include "MFC_LRDlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CAboutDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Диалоговое окно CMFCLRDlg



CMFCLRDlg::CMFCLRDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_LR_DIALOG, pParent)
	, m_cost(0)
	, m_consumption(0)
	, m_km(0)
	, m_res(0)
	, m_textPoezd(0)
	, m_fullPrice(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCLRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_cost);
	DDX_Text(pDX, IDC_EDIT2, m_consumption);
	DDX_Text(pDX, IDC_EDIT3, m_km);
	DDX_Text(pDX, IDC_EDIT4, m_res);
	DDX_Control(pDX, IDC_EDIT1, m_costControl);
	DDX_Control(pDX, IDC_EDIT2, m_consControl);
	DDX_Text(pDX, IDC_EDIT5, m_textPoezd);
	DDX_Text(pDX, IDC_EDIT6, m_fullPrice);
	DDX_Control(pDX, IDC_EDIT3, m_kmControl);
}

BEGIN_MESSAGE_MAP(CMFCLRDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCLRDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCLRDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCLRDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCLRDlg

BOOL CMFCLRDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	m_textPoezd = 1;
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCLRDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCLRDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCLRDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedButton1()
{
}

void CMFCLRDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	double cost, cons, km, res;
	cost = m_cost;
	cons = m_consumption;
	km = m_km;
	if (cost <= 0 || cons <= 0 || km <= 0) { MessageBox(L"Поля заполнены неправильно", L"Ошибка", MB_OK | MB_ICONERROR); }
	else {
		res = km / 100 * cons * cost;
		m_res = ceil(res);
	}
	m_costControl.SetReadOnly(TRUE);
	m_consControl.SetReadOnly(TRUE);
	m_kmControl.SetReadOnly(TRUE);
	UpdateData(FALSE);
}


void CMFCLRDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	CMFCLRDlg::OnBnClickedButton1(); 
	m_kmControl.SetReadOnly(FALSE);
	int poezd = m_textPoezd;
	double fullPrice = m_fullPrice;
	if (m_cost <= 0 || m_consumption <= 0 || m_km <= 0) { MessageBox(L"Поля введены неправильно", L"Ошибка", MB_OK | MB_ICONERROR); }
	else {
		poezd++;
		m_textPoezd = poezd;
		m_costControl.SetReadOnly(TRUE);
		m_consControl.SetReadOnly(TRUE);
		fullPrice += m_res;
		m_fullPrice = fullPrice;
	}
	UpdateData(FALSE);
}


void CAboutDlg::OnBnClickedButton3()
{
}


void CMFCLRDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	m_kmControl.SetReadOnly(TRUE);
	m_costControl.SetReadOnly(TRUE);
	m_consControl.SetReadOnly(TRUE);
	m_km = 240;
	m_consumption = 8.4;
	m_cost = 16.5;
	m_res = m_km / 100 * m_consumption * m_cost;
	UpdateData(FALSE);
}
