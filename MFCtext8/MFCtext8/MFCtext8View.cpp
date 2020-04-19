
// MFCtext8View.cpp : CMFCtext8View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext8.h"
#endif

#include "MFCtext8Doc.h"
#include "MFCtext8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext8View

IMPLEMENT_DYNCREATE(CMFCtext8View, CView)

BEGIN_MESSAGE_MAP(CMFCtext8View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW, &CMFCtext8View::OnShow)
END_MESSAGE_MAP()

// CMFCtext8View 构造/析构

CMFCtext8View::CMFCtext8View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext8View::~CMFCtext8View()
{
}

BOOL CMFCtext8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext8View 绘制

void CMFCtext8View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext8View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext8View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext8View 诊断

#ifdef _DEBUG
void CMFCtext8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext8Doc* CMFCtext8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext8Doc)));
	return (CMFCtext8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext8View 消息处理程序


void CMFCtext8View::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("手抓饼代言人"); 
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
}
