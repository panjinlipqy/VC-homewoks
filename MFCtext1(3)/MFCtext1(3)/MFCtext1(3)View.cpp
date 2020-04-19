
// MFCtext1(3)View.cpp : CMFCtext13View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext1(3).h"
#endif

#include "MFCtext1(3)Doc.h"
#include "MFCtext1(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext13View

IMPLEMENT_DYNCREATE(CMFCtext13View, CView)

BEGIN_MESSAGE_MAP(CMFCtext13View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext13View 构造/析构

CMFCtext13View::CMFCtext13View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext13View::~CMFCtext13View()
{
}

BOOL CMFCtext13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext13View 绘制

void CMFCtext13View::OnDraw(CDC* pDC)
{
	CMFCtext13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	GetClientRect(&cr);
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext13View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext13View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext13View 诊断

#ifdef _DEBUG
void CMFCtext13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext13Doc* CMFCtext13View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext13Doc)));
	return (CMFCtext13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext13View 消息处理程序
