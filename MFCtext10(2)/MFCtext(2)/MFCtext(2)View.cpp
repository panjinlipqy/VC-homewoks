
// MFCtext(2)View.cpp : CMFCtext2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext(2).h"
#endif

#include "MFCtext(2)Doc.h"
#include "MFCtext(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext2View

IMPLEMENT_DYNCREATE(CMFCtext2View, CView)

BEGIN_MESSAGE_MAP(CMFCtext2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CMFCtext2View 构造/析构

CMFCtext2View::CMFCtext2View()
{
	// TODO: 在此处添加构造代码
	r.top = 10;
	r.left = 10;
	r.bottom = 100;
	r.right = 1010;
   p.x = r.left + 5;
	p.y = r.top + 5;
	flag = false;
}

CMFCtext2View::~CMFCtext2View()
{
}

BOOL CMFCtext2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext2View 绘制

void CMFCtext2View::OnDraw(CDC* pDC)
{
	CMFCtext2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(r);
}

void CMFCtext2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext2View 诊断

#ifdef _DEBUG
void CMFCtext2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext2Doc* CMFCtext2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext2Doc)));
	return (CMFCtext2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext2View 消息处理程序


void CMFCtext2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	
	if(p.x >= r.right -5){
		p.x = r.left + 5;
		p.y = p.y+25;
		 SetCaretPos(p);
         ShowCaret();
	}else if(p.y + 25 >= r.bottom -5 ){
		dc.TextOutW(p.x+100,p.y,_T("输入内容已满！！尚未完善，需重启程序才可继续输入"));
	}else if(flag == false){
		HideCaret();
		dc.TextOutW(p.x, p.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		p.x = p.x+textsize.cx;
		  SetCaretPos(p);
         ShowCaret();
	}
	//Invalidate();
	if(flag == true){
		HideCaret();
		dc.TextOutW(ps.x, ps.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		p.x = p.x+textsize.cx;
		ps.x = ps.x + textsize.cx;
		  SetCaretPos(ps);
         ShowCaret();
	}
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCtext2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ps.x = point.x;
	ps.y = p.y;
	 SetCaretPos(ps);
         ShowCaret();
		 flag = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext2View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: 在此处添加消息处理程序代码
	CreateSolidCaret(3, 18);
    SetCaretPos(p);
     ShowCaret();
}
