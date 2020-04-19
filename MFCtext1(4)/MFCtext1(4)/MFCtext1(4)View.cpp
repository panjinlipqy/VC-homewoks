
// MFCtext1(4)View.cpp : CMFCtext14View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext1(4).h"
#endif

#include "MFCtext1(4)Doc.h"
#include "MFCtext1(4)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext14View

IMPLEMENT_DYNCREATE(CMFCtext14View, CView)

BEGIN_MESSAGE_MAP(CMFCtext14View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext14View 构造/析构

CMFCtext14View::CMFCtext14View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext14View::~CMFCtext14View()
{
}

BOOL CMFCtext14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext14View 绘制

void CMFCtext14View::OnDraw(CDC* pDC)
{
	CMFCtext14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	GetClientRect(&cr);
	CBrush m_brush;
	m_brush.CreateSolidBrush(RGB(20,50,50));
	CBrush *oldbrush;
    oldbrush = pDC->SelectObject(&m_brush);
	pDC->Ellipse(cr);
	pDC->SelectObject(oldbrush);
}

void CMFCtext14View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext14View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext14View 诊断

#ifdef _DEBUG
void CMFCtext14View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext14Doc* CMFCtext14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext14Doc)));
	return (CMFCtext14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext14View 消息处理程序
