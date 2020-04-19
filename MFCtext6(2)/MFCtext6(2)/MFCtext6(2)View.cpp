
// MFCtext6(2)View.cpp : CMFCtext62View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext6(2).h"
#endif

#include "MFCtext6(2)Doc.h"
#include "MFCtext6(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext62View

IMPLEMENT_DYNCREATE(CMFCtext62View, CView)

BEGIN_MESSAGE_MAP(CMFCtext62View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCtext62View 构造/析构

CMFCtext62View::CMFCtext62View()
{
	// TODO: 在此处添加构造代码
	r.left = 100;
	r.right = 400;
	r.top = 100;
	r.bottom = 300;
}

CMFCtext62View::~CMFCtext62View()
{
}

BOOL CMFCtext62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext62View 绘制

void CMFCtext62View::OnDraw(CDC* pDC)
{
	CMFCtext62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(r);
}

void CMFCtext62View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext62View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext62View 诊断

#ifdef _DEBUG
void CMFCtext62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext62Doc* CMFCtext62View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext62Doc)));
	return (CMFCtext62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext62View 消息处理程序


void CMFCtext62View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	GetClientRect(&R);
	switch(nChar)
	{
	  case VK_LEFT:
		if(r.left > 0)
		{
			r.left -= 10;
			r.right -= 10;
		}
		break;
		case VK_RIGHT:
			if(r.right < R.right)
		{
			r.left += 10;
			r.right += 10;
		}
			break;
		case VK_UP:
			if(r.top > 0)
			{
				r.top -= 10;
				r.bottom -= 10;
			}
			break;
		case VK_DOWN:
			if(r.bottom < R.bottom)
			{
				r.bottom += 10;
				r.top += 10;
			}
			break;
		case VK_HOME:
			if(r.right < R.right && r.top > 0)
			{
				r.right += 10;
				r.top -= 10;
			}
			break;
		case VK_END:
			if(r.bottom < R.bottom && r.left > 0)
			{
				r.bottom += 10;
				r.left  -= 10;
			}
	
	}
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
