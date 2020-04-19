
// MFCtext2(2)View.cpp : CMFCtext22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext2(2).h"
#endif

#include "MFCtext2(2)Doc.h"
#include "MFCtext2(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext22View

IMPLEMENT_DYNCREATE(CMFCtext22View, CView)

BEGIN_MESSAGE_MAP(CMFCtext22View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext22View 构造/析构

CMFCtext22View::CMFCtext22View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext22View::~CMFCtext22View()
{
}

BOOL CMFCtext22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext22View 绘制

void CMFCtext22View::OnDraw(CDC* pDC)
{
	CMFCtext22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	pDC->TextOutW(100,100,pDoc->s);//(2)
	pDC->TextOutW(100,200,pDoc->s2);
}

void CMFCtext22View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext22View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext22View 诊断

#ifdef _DEBUG
void CMFCtext22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext22Doc* CMFCtext22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext22Doc)));
	return (CMFCtext22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext22View 消息处理程序
