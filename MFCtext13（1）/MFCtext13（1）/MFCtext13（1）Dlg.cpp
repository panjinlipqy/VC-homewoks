
// MFCtext13��1��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCtext13��1��.h"
#include "MFCtext13��1��Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCtext13��1��Dlg �Ի���




CMFCtext13��1��Dlg::CMFCtext13��1��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCtext13��1��Dlg::IDD, pParent)
	, mstr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCtext13��1��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mstr);
}

BEGIN_MESSAGE_MAP(CMFCtext13��1��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_1, &CMFCtext13��1��Dlg::OnBnClicked1)
	ON_BN_CLICKED(ID_2, &CMFCtext13��1��Dlg::OnBnClicked2)
	ON_BN_CLICKED(ID_3, &CMFCtext13��1��Dlg::OnBnClicked3)
	ON_BN_CLICKED(ID_4, &CMFCtext13��1��Dlg::OnBnClicked4)
	ON_BN_CLICKED(ID_5, &CMFCtext13��1��Dlg::OnBnClicked5)
	ON_BN_CLICKED(ID_6, &CMFCtext13��1��Dlg::OnBnClicked6)
	ON_BN_CLICKED(ID_7, &CMFCtext13��1��Dlg::OnBnClicked7)
	ON_BN_CLICKED(ID_8, &CMFCtext13��1��Dlg::OnBnClicked8)
	ON_BN_CLICKED(ID_9, &CMFCtext13��1��Dlg::OnBnClicked9)
	ON_BN_CLICKED(ID_0, &CMFCtext13��1��Dlg::OnBnClicked0)
	ON_BN_CLICKED(ID_point, &CMFCtext13��1��Dlg::OnBnClickedpoint)
	ON_BN_CLICKED(ID_equal, &CMFCtext13��1��Dlg::OnBnClickedequal)
	ON_BN_CLICKED(ID_add, &CMFCtext13��1��Dlg::OnBnClickedadd)
	ON_BN_CLICKED(IDC_minus, &CMFCtext13��1��Dlg::OnBnClickedminus)
	ON_BN_CLICKED(ID_times, &CMFCtext13��1��Dlg::OnBnClickedtimes)
	ON_BN_CLICKED(ID_divide, &CMFCtext13��1��Dlg::OnBnClickeddivide)
	ON_BN_CLICKED(IDC_square, &CMFCtext13��1��Dlg::OnBnClickedsquare)
	ON_BN_CLICKED(IDC_reci, &CMFCtext13��1��Dlg::OnBnClickedreci)
	ON_BN_CLICKED(ID_empty, &CMFCtext13��1��Dlg::OnBnClickedempty)
	ON_BN_CLICKED(ID_del, &CMFCtext13��1��Dlg::OnBnClickeddel)
END_MESSAGE_MAP()


// CMFCtext13��1��Dlg ��Ϣ�������

BOOL CMFCtext13��1��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCtext13��1��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCtext13��1��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCtext13��1��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCtext13��1��Dlg::OnBnClicked1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"1";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"2";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"3";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"4";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"5";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"6";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"7";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"8";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"9";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClicked0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L"0";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClickedpoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	mstr += L".";
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClickedequal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//=
	Calculator();
}


void CMFCtext13��1��Dlg::OnBnClickedadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//+   
	SaveFirstValue();   //�����һ����ֵ�� ���ڰ��²�������ť�󣬵ڶ�����ֵ���֮ǰʹ�༭��հ�
	mFlag = 20;     //��+���ı�־������Calculator()������case����ת�ж�
}


void CMFCtext13��1��Dlg::OnBnClickedminus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//-
	SaveFirstValue();
	mFlag = 21;
}


void CMFCtext13��1��Dlg::OnBnClickedtimes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//*
	SaveFirstValue();
	mFlag = 22;
}


void CMFCtext13��1��Dlg::OnBnClickeddivide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//  /
	SaveFirstValue(); 
	mFlag = 23;     
}


void CMFCtext13��1��Dlg::OnBnClickedsquare()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ƽ��
	UpdateData(TRUE);
	mNum1 = _wtof(mstr);  //���ַ�������ת����double
	double f = mNum1 * mNum1;

	//�������������������ʾ����
	if(f - int(f) <= 1e-5) mstr.Format(L"%d", (int)f);
	else  mstr.Format(L"%f", f);
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = 24;

}


void CMFCtext13��1��Dlg::OnBnClickedreci()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����
	UpdateData(TRUE);
	mNum1 = _wtof(mstr);  //���ַ�������ת����double
	double f =1 / mNum1;

	//�������������������ʾ����
	if(f - int(f) <= 1e-5) mstr.Format(L"%d", (int)f);
	else  mstr.Format(L"%f", f);
	UpdateData(FALSE);

	mNum1 = f;
	mNum2 = 0.0f;
	mFlag = 25;

}


void CMFCtext13��1��Dlg::OnBnClickedempty()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���
	UpdateData(TRUE);
	mstr = L"";  //���Ի�����Ϊ��
	mNum1 = 0.0f;
	mNum2 = 0.0f;
	mFlag = 26;
	UpdateData(FALSE);
}


void CMFCtext13��1��Dlg::OnBnClickeddel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ɾ��
	UpdateData(TRUE);  //���ؼ�����������

	if(!mstr.IsEmpty()){ //�Ƴ����ұ�һ���ַ�
		mstr = mstr.Left(mstr.GetLength() - 1);
	}

	UpdateData(FALSE);  //���������������ؼ�
}

void CMFCtext13��1��Dlg::SaveFirstValue()
{
	UpdateData(TRUE);  
	mNum1 = _wtof(mstr);  //�༭����ʾ��һ����������ת����double��
	mstr = L"";       //�����ϲ������󽫱༭������Ϊ��
	UpdateData(FALSE);
}

void CMFCtext13��1��Dlg::Calculator()
{
	UpdateData(TRUE);  
	mNum2 = _wtof(mstr);  //��õڶ�������������ʾ�ڱ༭����
	double result = 0.0f;

	switch(mFlag)
	{
	     case 20:   //��
			 result = mNum1 + mNum2;
			  break;
		 case 21:  //��
			 result = mNum1 - mNum2;
			  break;
		 case 22:  //��
			 result = mNum1 * mNum2;
			  break;
		 case 23: //��
			 result = mNum1 / mNum2;
		 break;
	}

	 if(result - int(result) <= 1e-5) mstr.Format(L"%d", (int)result);
	         else  mstr.Format(L"%f", result);
	
	UpdateData(FALSE);
}