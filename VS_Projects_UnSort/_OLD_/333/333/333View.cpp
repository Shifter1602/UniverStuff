
// 333View.cpp : ���������� ������ CMy333View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "333.h"
#endif

#include "333Doc.h"
#include "CntrItem.h"
#include "resource.h"
#include "333View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy333View

IMPLEMENT_DYNCREATE(CMy333View, CRichEditView)

BEGIN_MESSAGE_MAP(CMy333View, CRichEditView)
	ON_WM_DESTROY()
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy333View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� CMy333View

CMy333View::CMy333View()
{
	// TODO: �������� ��� ��������

}

CMy333View::~CMy333View()
{
}

BOOL CMy333View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CMy333View::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// ������� ������� ������ (720 ���� = 1/2 �����)
	SetMargins(CRect(720, 720, 720, 720));
}


// ������ CMy333View


void CMy333View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy333View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}


void CMy333View::OnDestroy()
{
	// ������������� ������� ��� ��������; ��� �����
	// � ������ ������������� ������������� �����������
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CMy333View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy333View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CMy333View

#ifdef _DEBUG
void CMy333View::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CMy333View::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CMy333Doc* CMy333View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy333Doc)));
	return (CMy333Doc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CMy333View
