
// MFCtext8(2)View.cpp : CMFCtext82View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext8(2).h"
#endif

#include "MFCtext8(2)Doc.h"
#include "MFCtext8(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext82View

IMPLEMENT_DYNCREATE(CMFCtext82View, CView)

BEGIN_MESSAGE_MAP(CMFCtext82View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW_IMG, &CMFCtext82View::OnShowImg)
END_MESSAGE_MAP()

// CMFCtext82View 构造/析构

CMFCtext82View::CMFCtext82View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFCtext82View::~CMFCtext82View()
{
}

BOOL CMFCtext82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext82View 绘制

void CMFCtext82View::OnDraw(CDC* pDC)
{
	CMFCtext82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}

void CMFCtext82View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext82View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext82View 诊断

#ifdef _DEBUG
void CMFCtext82View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext82Doc* CMFCtext82View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext82Doc)));
	return (CMFCtext82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext82View 消息处理程序


void CMFCtext82View::OnShowImg()
{
	// TODO: 在此添加命令处理程序代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	CClientDC dc(this);
	dc.BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	
}
