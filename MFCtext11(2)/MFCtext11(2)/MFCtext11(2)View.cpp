
// MFCtext11(2)View.cpp : CMFCtext112View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext11(2).h"
#endif

#include "MFCtext11(2)Doc.h"
#include "MFCtext11(2)View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext112View

IMPLEMENT_DYNCREATE(CMFCtext112View, CView)

BEGIN_MESSAGE_MAP(CMFCtext112View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POP, &CMFCtext112View::OnPop)
END_MESSAGE_MAP()

// CMFCtext112View 构造/析构

CMFCtext112View::CMFCtext112View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext112View::~CMFCtext112View()
{
}

BOOL CMFCtext112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext112View 绘制

void CMFCtext112View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext112Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext112View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext112View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext112View 诊断

#ifdef _DEBUG
void CMFCtext112View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext112Doc* CMFCtext112View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext112Doc)));
	return (CMFCtext112Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext112View 消息处理程序


void CMFCtext112View::OnPop()
{
	// TODO: 在此添加命令处理程序代码
	Dlg dlg;
	int t = dlg.DoModal();

	if(t == IDOK){
		a = dlg.a;
		b = dlg.b;
		c = dlg.c;
	}
}


