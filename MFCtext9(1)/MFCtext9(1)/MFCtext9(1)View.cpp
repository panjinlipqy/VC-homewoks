
// MFCtext9(1)View.cpp : CMFCtext91View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext9(1).h"
#endif

#include "MFCtext9(1)Doc.h"
#include "MFCtext9(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext91View

IMPLEMENT_DYNCREATE(CMFCtext91View, CView)

BEGIN_MESSAGE_MAP(CMFCtext91View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext91View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCtext91View 构造/析构

CMFCtext91View::CMFCtext91View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext91View::~CMFCtext91View()
{
}

BOOL CMFCtext91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext91View 绘制

void CMFCtext91View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext91View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext91View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext91View 诊断

#ifdef _DEBUG
void CMFCtext91View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext91Doc* CMFCtext91View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext91Doc)));
	return (CMFCtext91Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext91View 消息处理程序


void CMFCtext91View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CString filename = cfd.GetPathName();
	CImage img;    
		img.Load(filename);
		int sx, sy; //w,h宽高，sx,sy,图片位置，左上角那个点
		CRect rect;
		GetClientRect(&rect);  //获取当前客户区大小

		sx = (rect.Width() - img.GetWidth()) / 2;
		sy = (rect.Height() - img.GetHeight()) /2;
		img.Draw(dc.m_hDC, sx, sy, img.GetWidth(), img.GetHeight());

	if (r == IDOK)
		dc.TextOutW(0, 0, filename); //在对话框输出打开的文件名
		

	
}
