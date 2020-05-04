
// MFCtext13（1）Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCtext13（1）.h"
#include "MFCtext13（1）Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCtext13（1）Dlg 对话框




CMFCtext13（1）Dlg::CMFCtext13（1）Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCtext13（1）Dlg::IDD, pParent)
	, mstr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCtext13（1）Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mstr);
}

BEGIN_MESSAGE_MAP(CMFCtext13（1）Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_1, &CMFCtext13（1）Dlg::OnBnClicked1)
	ON_BN_CLICKED(ID_2, &CMFCtext13（1）Dlg::OnBnClicked2)
	ON_BN_CLICKED(ID_3, &CMFCtext13（1）Dlg::OnBnClicked3)
	ON_BN_CLICKED(ID_4, &CMFCtext13（1）Dlg::OnBnClicked4)
	ON_BN_CLICKED(ID_5, &CMFCtext13（1）Dlg::OnBnClicked5)
	ON_BN_CLICKED(ID_6, &CMFCtext13（1）Dlg::OnBnClicked6)
	ON_BN_CLICKED(ID_7, &CMFCtext13（1）Dlg::OnBnClicked7)
	ON_BN_CLICKED(ID_8, &CMFCtext13（1）Dlg::OnBnClicked8)
	ON_BN_CLICKED(ID_9, &CMFCtext13（1）Dlg::OnBnClicked9)
	ON_BN_CLICKED(ID_0, &CMFCtext13（1）Dlg::OnBnClicked0)
	ON_BN_CLICKED(ID_point, &CMFCtext13（1）Dlg::OnBnClickedpoint)
	ON_BN_CLICKED(ID_equal, &CMFCtext13（1）Dlg::OnBnClickedequal)
	ON_BN_CLICKED(ID_add, &CMFCtext13（1）Dlg::OnBnClickedadd)
	ON_BN_CLICKED(IDC_minus, &CMFCtext13（1）Dlg::OnBnClickedminus)
	ON_BN_CLICKED(ID_times, &CMFCtext13（1）Dlg::OnBnClickedtimes)
	ON_BN_CLICKED(ID_divide, &CMFCtext13（1）Dlg::OnBnClickeddivide)
	ON_BN_CLICKED(IDC_square, &CMFCtext13（1）Dlg::OnBnClickedsquare)
	ON_BN_CLICKED(IDC_reci, &CMFCtext13（1）Dlg::OnBnClickedreci)
	ON_BN_CLICKED(ID_empty, &CMFCtext13（1）Dlg::OnBnClickedempty)
	ON_BN_CLICKED(ID_del, &CMFCtext13（1）Dlg::OnBnClickeddel)
END_MESSAGE_MAP()


// CMFCtext13（1）Dlg 消息处理程序

BOOL CMFCtext13（1）Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCtext13（1）Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCtext13（1）Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCtext13（1）Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCtext13（1）Dlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"1";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"2";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"3";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"4";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"5";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"6";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"7";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"8";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"9";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L"0";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClickedpoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	mstr += L".";
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClickedequal()
{
	// TODO: 在此添加控件通知处理程序代码
	//=
	Calculator();
}


void CMFCtext13（1）Dlg::OnBnClickedadd()
{
	// TODO: 在此添加控件通知处理程序代码
	//+   
	SaveFirstValue();   //保存第一个数值， 并在按下操作符按钮后，第二个数值输出之前使编辑框空白
	mFlag = 20;     //“+”的标志，用于Calculator()函数中case的跳转判断
}


void CMFCtext13（1）Dlg::OnBnClickedminus()
{
	// TODO: 在此添加控件通知处理程序代码
	//-
	SaveFirstValue();
	mFlag = 21;
}


void CMFCtext13（1）Dlg::OnBnClickedtimes()
{
	// TODO: 在此添加控件通知处理程序代码
	//*
	SaveFirstValue();
	mFlag = 22;
}


void CMFCtext13（1）Dlg::OnBnClickeddivide()
{
	// TODO: 在此添加控件通知处理程序代码
	//  /
	SaveFirstValue(); 
	mFlag = 23;     
}


void CMFCtext13（1）Dlg::OnBnClickedsquare()
{
	// TODO: 在此添加控件通知处理程序代码
	//平方
	UpdateData(TRUE);
	mNum1 = _wtof(mstr);  //把字符串类型转化成double
	double f = mNum1 * mNum1;

	//如果浮点数是整数则显示整数
	if(f - int(f) <= 1e-5) mstr.Format(L"%d", (int)f);
	else  mstr.Format(L"%f", f);
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = 24;

}


void CMFCtext13（1）Dlg::OnBnClickedreci()
{
	// TODO: 在此添加控件通知处理程序代码
	//倒数
	UpdateData(TRUE);
	mNum1 = _wtof(mstr);  //把字符串类型转化成double
	double f =1 / mNum1;

	//如果浮点数是整数则显示整数
	if(f - int(f) <= 1e-5) mstr.Format(L"%d", (int)f);
	else  mstr.Format(L"%f", f);
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = 25;

}


void CMFCtext13（1）Dlg::OnBnClickedempty()
{
	// TODO: 在此添加控件通知处理程序代码
	//清空
	UpdateData(TRUE);
	mstr = L"";  //将对话框设为空
	mNum1 = 0.0f;
	mNum2 = 0.0f;
	mFlag = 26;
	UpdateData(FALSE);
}


void CMFCtext13（1）Dlg::OnBnClickeddel()
{
	// TODO: 在此添加控件通知处理程序代码
	//删除
	UpdateData(TRUE);  //将控件数传给变量

	if(!mstr.IsEmpty()){ //移除最右边一个字符
		mstr = mstr.Left(mstr.GetLength() - 1);
	}

	UpdateData(FALSE);  //将变量的数传给控件
}

void CMFCtext13（1）Dlg::SaveFirstValue()
{
	UpdateData(TRUE);  
	mNum1 = _wtof(mstr);  //编辑框显示第一操作数，并转换成double型
	mstr = L"";       //做完上步操作后将编辑框设置为空
	UpdateData(FALSE);
}

void CMFCtext13（1）Dlg::Calculator()
{
	UpdateData(TRUE);  
	mNum2 = _wtof(mstr);  //获得第二个操作数并显示在编辑框中
	double result = 0.0f;

	switch(mFlag)
	{
	     case 20:   //加
			 result = mNum1 + mNum2;
			  break;
		 case 21:  //减
			 result = mNum1 - mNum2;
			  break;
		 case 22:  //乘
			 result = mNum1 * mNum2;
			  break;
		 case 23: //除
			 result = mNum1 / mNum2;
		 break;
	}

	 if(result - int(result) <= 1e-5) mstr.Format(L"%d", (int)result);
	         else  mstr.Format(L"%f", result);
	
	UpdateData(FALSE);
}