
// MFCtext2(1)View.cpp : CMFCtext21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext2(1).h"
#endif

#include "MFCtext2(1)Doc.h"
#include "MFCtext2(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext21View

IMPLEMENT_DYNCREATE(CMFCtext21View, CView)

BEGIN_MESSAGE_MAP(CMFCtext21View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext21View 构造/析构

CMFCtext21View::CMFCtext21View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext21View::~CMFCtext21View()
{
}

BOOL CMFCtext21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext21View 绘制

void CMFCtext21View::OnDraw(CDC* pDC)
{
	CMFCtext21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;   //(1)
	s = "我是手抓饼代言人pjl";
	int A = 8888;
	CString s2;
	s2.Format(_T("%d"), A);
	pDC->TextOutW(100,100,s);
	pDC->TextOutW(100,200,s2);
}

void CMFCtext21View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext21View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext21View 诊断

#ifdef _DEBUG
void CMFCtext21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext21Doc* CMFCtext21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext21Doc)));
	return (CMFCtext21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext21View 消息处理程序
