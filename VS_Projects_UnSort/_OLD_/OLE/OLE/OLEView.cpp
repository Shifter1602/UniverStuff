
// OLEView.cpp : ���������� ������ COLEView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "OLE.h"
#endif

#include "OLEDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "OLEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COLEView

IMPLEMENT_DYNCREATE(COLEView, CView)

BEGIN_MESSAGE_MAP(COLEView, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &COLEView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &COLEView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &COLEView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// ��������/����������� COLEView

COLEView::COLEView()
{
	m_pSelection = NULL;
	// TODO: �������� ��� ��������

}

COLEView::~COLEView()
{
}

BOOL COLEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� COLEView

void COLEView::OnDraw(CDC* pDC)
{
	if (!pDC)
		return;

	COLEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �������� ����� ��� ��������� ��� ����������� ������
	// TODO: ����� ��������� ��� �������� OLE � ���������

	// ��������� ���������� �������� � ������������ �����. ���� ��� ������ ����
	//  ������, ��������� ���������� ��� ���������. ��� ���������
	//  ����� ������������� ��������������, ������������� COLECntrItem,
	//  ��� �������������� ����������� �������������� �� �����.

	// TODO: ������� ���� ��� ����� ���������� ������ ���� ���������.
	
	/*if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);
		
		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}*/
		
	//	
		POSITION pos = pDoc->GetStartPosition();
		while (pos)
		{
			COLECntrItem* pCurrentitem= (COLECntrItem*) pDoc->GetNextClientItem(pos);
			pCurrentitem->Draw(pDC,pCurrentitem->m_rect);

		}
		//m_pSelection->Draw(pDC,m_pSelection->m_rect);

		CRectTracker tracker;
		SetupTracker(m_pSelection,&tracker);
		tracker.Draw(pDC);
	}


void COLEView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: ������� ���� ���, ����� ��������� ��� ������ ������ ����� �������
	m_pSelection = NULL;    // ������������� ���������

}


// ������ COLEView

BOOL COLEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void COLEView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void COLEView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void COLEView::OnDestroy()
{
	// ������������� ������� ��� ��������; ��� �����
	// � ������ ������������� ������������� �����������
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CView::OnDestroy();
}



// ������� � ��������� ������� OLE

BOOL COLEView::IsSelected(const CObject* pDocItem) const
{
	// ���������� ���� �����������, ���� ���������� �������� �������
	//  ������ �� �������� COLECntrItem. ����� ��������� ����������
	//  ����������� ������ ������� �������� ����� ����������

	// TODO: ���������� ��� �������, ������� ��������� ��������� ������� ������� OLE

	return pDocItem == m_pSelection;
}

void COLEView::OnInsertObject()
{
	// �������� ����������� ���������� ���� "������� �������" ��� ��������� ����������
	//  ��� ������ ������� COLECntrItem
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	COLECntrItem* pItem = NULL;
	TRY
	{
		// ������� ����� �������, ��������� � ���� ����������
		COLEDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new COLECntrItem(pDoc);
		ASSERT_VALID(pItem);

		// ��������������� ������� �� ������ ����������� ����
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // ����� ���������� ��������
		ASSERT_VALID(pItem);
		
        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// ��������� ������ ���������� ������������ ������������, ��� ������ ������� �����������
		//  ��������� � ��������� �������

		// TODO: ��������� ���������� ���������, ��� ��� ��������� � ����������
		m_pSelection = pItem;   // ��������� ���������� ������������ ��������
		pDoc->UpdateAllViews(NULL);
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// ��������� ���������� ������ ������������� ����������� ������������
//  ��������� ������������ ��� ������ ������ �������������� �� �����. �����
//  ��������� (�� ������) �������� �����������
void COLEView::OnCancelEditCntr()
{
	// �������� � ���� ������������� ��� �������� ������� �������������� �� �����
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// ��� ���������� ��������� ����������� ��������� OnSetFocus � OnSize,
//  ���� ������ ������������� �� �����
void COLEView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// ���������� ���������� ����� �� ���� ������, ���� �� ��������� � ��� �� �������������
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // �� ��������� ������� �����
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void COLEView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}

void COLEView::OnFilePrint()
{
	//�� ��������� ������ ��������� ��������� �������������
	//� ������� IOleCommandTarget. ���� ����� ��������� �� ���������,
	//������� ����� COleDocObjectItem::DoDefaultPrinting.
	//���� ����� ����� ��������� �� �����-���� �������, �� ��������� ����������
	//docobject � ������� ���������� IPrint.
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != NULL); 
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;
	
	CView::OnFilePrint();

}



// ����������� COLEView

#ifdef _DEBUG
void COLEView::AssertValid() const
{
	CView::AssertValid();
}

void COLEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COLEDoc* COLEView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COLEDoc)));
	return (COLEDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� COLEView


void COLEView::SetupTracker(COLECntrItem* pItem, CRectTracker* pTracker)
{
	pTracker->m_rect = pItem->m_rect;
	if (pItem==m_pSelection)
		pTracker->m_nStyle |=CRectTracker::resizeInside;
	if(pItem->GetType()==OT_LINK)
		pTracker->m_nStyle |=CRectTracker::dottedLine;
	else 
		pTracker->m_nStyle |=CRectTracker::solidLine;
	if (pItem->GetItemState()==COleClientItem::openState ||pItem->GetItemState()==COleClientItem::activeUIState )
		pTracker->m_nStyle |=CRectTracker::hatchInside;
}
COLECntrItem* COLEView::accHitTest(CPoint point)
{
	COLEDoc* pDoc = GetDocument();
	COLECntrItem* pHitItem= NULL;
	POSITION pos = pDoc->GetStartPosition();
	while (pos)
	{
		COLECntrItem* pCurrentItem = (COLECntrItem*)pDoc->GetNextClientItem(pos);
		if (pCurrentItem->m_rect.PtInRect(point))
		{
			pHitItem=pCurrentItem;
		}
	}
	return pHitItem;
}
void COLEView::SetSelection(COLECntrItem* pItem)
{
	if (pItem == NULL ||)
	{
	}
}