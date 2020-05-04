
// MFCtext13(2)(2)View.cpp : CMFCtext1322View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext13(2)(2).h"
#endif

#include "MFCtext13(2)(2)Doc.h"
#include "MFCtext13(2)(2)View.h"
#include "Dlg.h"
#include "DLG2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext1322View

IMPLEMENT_DYNCREATE(CMFCtext1322View, CView)

BEGIN_MESSAGE_MAP(CMFCtext1322View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POP, &CMFCtext1322View::OnPop)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_CLOR, &CMFCtext1322View::OnClor)
END_MESSAGE_MAP()

// CMFCtext1322View 构造/析构

CMFCtext1322View::CMFCtext1322View()
{
	// TODO: 在此处添加构造代码
	a=0;
	b=0;
	x=0;
	y=0;
	flag = 0;
}

CMFCtext1322View::~CMFCtext1322View()
{
}

BOOL CMFCtext1322View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext1322View 绘制

void CMFCtext1322View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext1322Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext1322View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext1322View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext1322View 诊断

#ifdef _DEBUG
void CMFCtext1322View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext1322View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext1322Doc* CMFCtext1322View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext1322Doc)));
	return (CMFCtext1322Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext1322View 消息处理程序


void CMFCtext1322View::OnPop()
{
	// TODO: 在此添加命令处理程序代码
	Dlg dlg;
	int t = dlg.DoModal();
	if(t = IDOK){
		a = dlg.a;
		b = dlg.b;
		x = dlg.x;
		y = dlg.y;

		
	re.left = x - a;
	re.right = x + a;
	re.bottom = y + b;
	re.top = y - b;
	CClientDC dc(this);
	dc.Ellipse(re);
	}

}




void CMFCtext1322View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(point.x >= re.left && point.x <= re.right && point.y >= re.top && point.y <= re.bottom){
		CPen m_pen;
		m_pen.CreatePen(PS_DASH, 1, RGB(255,0, 0));
		CPen* pOldPen; 
		CClientDC dc(this);
       pOldPen=dc.SelectObject (&m_pen); 
       //HDC hdc;

       dc.MoveTo(re.left, re.top); 
       dc.LineTo(re.right, re.top); 

	   dc.MoveTo(re.left, re.top); 
       dc.LineTo(re.left, re.bottom); 

	    dc.MoveTo(re.left, re.bottom); 
       dc.LineTo(re.right, re.bottom);

	    dc.MoveTo(re.right, re.top); 
       dc.LineTo(re.right, re.bottom);

       dc.SelectObject (&pOldPen); 
		
	}
	flag = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext1322View::OnClor()
{
	// TODO: 在此添加命令处理程序代码
	DLG2 dlg;
	int t = dlg.DoModal();
	if(t == IDOK && flag ==1){
		int r, g, b;
		r = dlg.R;
		g = dlg.G;
		b = dlg.B;

		CClientDC dc(this);
		CBrush m_brush;
		m_brush.CreateSolidBrush(RGB(r,g,b));
		CBrush *oldbrush;
		oldbrush = dc.SelectObject(&m_brush);//选新的画刷
		dc.Ellipse(re);
		dc.SelectObject(oldbrush);
	}
}
