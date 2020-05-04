
// MFCtext12(1)View.cpp : CMFCtext121View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext12(1).h"
#endif

#include "MFCtext12(1)Doc.h"
#include "MFCtext12(1)View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext121View

IMPLEMENT_DYNCREATE(CMFCtext121View, CView)

BEGIN_MESSAGE_MAP(CMFCtext121View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext121View::OnFileOpen)
	ON_COMMAND(ID_POP, &CMFCtext121View::OnPop)
END_MESSAGE_MAP()

// CMFCtext121View 构造/析构

CMFCtext121View::CMFCtext121View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext121View::~CMFCtext121View()
{
}

BOOL CMFCtext121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext121View 绘制

void CMFCtext121View::OnDraw(CDC* pDC)
{
	CMFCtext121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext121View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext121View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext121View 诊断

#ifdef _DEBUG
void CMFCtext121View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext121Doc* CMFCtext121View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext121Doc)));
	return (CMFCtext121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext121View 消息处理程序


void CMFCtext121View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CFileDialog dlg(true);
	int r = dlg.DoModal(); //模式对话框,已弹出
	if(r == IDOK){
		CClientDC dc(this);
		 s1 = dlg.GetFileName();
		GetDC()->TextOutW(100, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCtext121View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	
}


void CMFCtext121View::OnPop()
{
	// TODO: 在此添加命令处理程序代码
	
	Dlg dlg;
	int t = dlg.DoModal();
	CClientDC dc(this);
	CString s;
	s = s1;
	//GetDC()->TextOutW(500, 100, dlg.name);
	if(t = IDOK){
		//s1 = dlg.name;
		pD->UpdateData(true);
		dlg.name= s1;
		//s1 = dlg.s;
		UpdateData(false);
	}
	
}
