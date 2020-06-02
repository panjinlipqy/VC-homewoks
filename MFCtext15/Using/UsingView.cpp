
// UsingView.cpp : CUsingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Using.h"
#endif

#include "UsingDoc.h"
#include "UsingView.h"
#include"w32.h"
#include "Dll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingView

IMPLEMENT_DYNCREATE(CUsingView, CView)

BEGIN_MESSAGE_MAP(CUsingView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CUsingView 构造/析构

CUsingView::CUsingView()
{
	// TODO: 在此处添加构造代码

}

CUsingView::~CUsingView()
{
}

BOOL CUsingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingView 绘制

void CUsingView::OnDraw(CDC* pDC)
{
	CUsingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s;
	int sum;
	sum = factorial(5);
	s.Format(_T("%d"), sum);
	pDC->TextOutW(100, 100, s);

	float d;
	CString s1;
	FAC t=FAC();
	d = t.convert(30.0);
	s1.Format(_T("%f"), d);
	pDC->TextOutW(200, 200, s1);

	CString s2;
	int sum1;
	sum1 = factorial_1(5);
	s2.Format(_T("%d"), sum1);
	pDC->TextOutW(300, 300, s2);

	float d1;
	CString s3;
	FACD R=FACD();
	d1 = R.convert(30.0);
	s3.Format(_T("%f"), d1);
	pDC->TextOutW(400, 400, s3);
}

void CUsingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUsingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CUsingView 诊断

#ifdef _DEBUG
void CUsingView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingDoc* CUsingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingDoc)));
	return (CUsingDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingView 消息处理程序
