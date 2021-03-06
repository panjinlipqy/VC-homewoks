
// MFCtext6View.cpp : CMFCtext6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext6.h"
#endif

#include "MFCtext6Doc.h"
#include "MFCtext6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext6View

IMPLEMENT_DYNCREATE(CMFCtext6View, CView)

BEGIN_MESSAGE_MAP(CMFCtext6View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext6View 构造/析构

CMFCtext6View::CMFCtext6View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext6View::~CMFCtext6View()
{
}

BOOL CMFCtext6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext6View 绘制

void CMFCtext6View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext6View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext6View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext6View 诊断

#ifdef _DEBUG
void CMFCtext6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext6Doc* CMFCtext6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext6Doc)));
	return (CMFCtext6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext6View 消息处理程序
