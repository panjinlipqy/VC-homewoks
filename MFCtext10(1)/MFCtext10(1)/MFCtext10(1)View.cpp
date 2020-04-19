
// MFCtext10(1)View.cpp : CMFCtext101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext10(1).h"
#endif

#include "MFCtext10(1)Doc.h"
#include "MFCtext10(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext101View

IMPLEMENT_DYNCREATE(CMFCtext101View, CView)

BEGIN_MESSAGE_MAP(CMFCtext101View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCtext101View 构造/析构

CMFCtext101View::CMFCtext101View()
{
	// TODO: 在此处添加构造代码
	r.top = 10;
	r.left = 10;
	r.bottom = 100;
	r.right = 1010;
   p.x = r.left + 5;
	p.y = r.top + 5;
}

CMFCtext101View::~CMFCtext101View()
{
}

BOOL CMFCtext101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext101View 绘制

void CMFCtext101View::OnDraw(CDC* pDC)
{
	CMFCtext101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(r);

	
}

void CMFCtext101View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext101View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext101View 诊断

#ifdef _DEBUG
void CMFCtext101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext101Doc* CMFCtext101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext101Doc)));
	return (CMFCtext101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext101View 消息处理程序


void CMFCtext101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CClientDC dc(this);
	if(p.x >= r.right -5){
		p.x = r.left + 5;
		p.y = p.y+25;
	}else if(p.y + 25 >= r.bottom -5){
		dc.TextOutW(p.x+100,p.y,_T("输入内容已满！！尚未完善，需重启程序才可继续输入"));
	}else{
		dc.TextOutW(p.x, p.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		p.x = p.x+textsize.cx;
	}
	//Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
