
// MFCtext9(2)View.cpp : CMFCtext92View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext9(2).h"
#endif

#include "MFCtext9(2)Doc.h"
#include "MFCtext9(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext92View

IMPLEMENT_DYNCREATE(CMFCtext92View, CView)

BEGIN_MESSAGE_MAP(CMFCtext92View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext92View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCtext92View 构造/析构

CMFCtext92View::CMFCtext92View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext92View::~CMFCtext92View()
{
}

BOOL CMFCtext92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext92View 绘制

void CMFCtext92View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext92View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext92View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext92View 诊断

#ifdef _DEBUG
void CMFCtext92View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext92Doc* CMFCtext92View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext92Doc)));
	return (CMFCtext92Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext92View 消息处理程序


void CMFCtext92View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CString filename = cfd.GetPathName();
	CImage img;    
	img.Load(filename);
	if (r == IDOK){
		int w, h, sx, sy; //w,h宽高，sx,sy,图片位置，左上角那个点
		CRect rect;
		GetClientRect(&rect);  //获取当前客户区大小

		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();  //获取客户区和图片的宽高比

		if(rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) /2;
			sy = 0;
		}
		else{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h)/2;
		}
		img.Draw(dc.m_hDC, sx, sy, w, h);
		dc.TextOutW(0, 0, filename);
	}
}
