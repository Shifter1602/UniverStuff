// ���� �������� ��� MFC Samples ������������� ���������������� ����������������� ���������� Fluent �� ������ MFC � Microsoft Office
// ("Fluent UI") � ��������������� ������������� ��� ���������� �������� � �������� ���������� �
// ����������� �� ������ Microsoft Foundation Classes � ��������� ����������� ������������,
// ���������� � ����������� ����������� ���������� MFC C++. 
// ������� ������������� ���������� �� �����������, ������������� ��� ��������������� Fluent UI �������� ��������. 
// ��� ��������� �������������� �������� � ����� ������������ ��������� Fluent UI �������� ���-����
// http://msdn.microsoft.com/officeui.
//
// (C) ���������� ���������� (Microsoft Corp.)
// ��� ����� ��������.

// WordView.cpp : ���������� ������ CWordView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "Word.h"
#endif

#include "WordDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "WordView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWordView

IMPLEMENT_DYNCREATE(CWordView, CRichEditView)

BEGIN_MESSAGE_MAP(CWordView, CRichEditView)
	ON_WM_DESTROY()
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWordView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ��������/����������� CWordView

CWordView::CWordView()
{
	// TODO: �������� ��� ��������

}

CWordView::~CWordView()
{
}

BOOL CWordView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CWordView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// ������� ������� ������ (720 ���� = 1/2 �����)
	SetMargins(CRect(720, 720, 720, 720));
}


// ������ CWordView


void CWordView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWordView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}


void CWordView::OnDestroy()
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


void CWordView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWordView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CWordView

#ifdef _DEBUG
void CWordView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CWordView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CWordDoc* CWordView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWordDoc)));
	return (CWordDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CWordView
