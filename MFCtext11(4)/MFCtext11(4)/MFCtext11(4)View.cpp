
// MFCtext11(4)View.cpp : CMFCtext114View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext11(4).h"
#endif

#include "MFCtext11(4)Doc.h"
#include "MFCtext11(4)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext114View

IMPLEMENT_DYNCREATE(CMFCtext114View, CView)

BEGIN_MESSAGE_MAP(CMFCtext114View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POP, &CMFCtext114View::OnPop)
END_MESSAGE_MAP()

// CMFCtext114View 构造/析构

CMFCtext114View::CMFCtext114View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext114View::~CMFCtext114View()
{
}

BOOL CMFCtext114View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext114View 绘制

void CMFCtext114View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext114Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext114View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext114View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext114View 诊断

#ifdef _DEBUG
void CMFCtext114View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext114View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext114Doc* CMFCtext114View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext114Doc)));
	return (CMFCtext114Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext114View 消息处理程序





void CMFCtext114View::OnPop()
{
	// TODO: 在此添加命令处理程序代码

	MyDlg dlg;
	t = dlg.DoModal();

	if(t == IDOK){
		a = dlg.x1;
		b = dlg.x2;
		c = dlg.x3;
	}
	
}
