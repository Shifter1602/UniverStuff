
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
#include "OptionsDlg.h"


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
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDBLCLK()

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
	/*
	if (m_pSelection != NULL)
	{
		CSize size;
		CRect rect(10,10,210,210);
		
		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		*/
	    
	    CRect rect;
	    GetClientRect(&rect);
		COLORREF oldcolor;
	    switch(pDoc->m_colour)
	    {
		case 0:
			oldcolor = pDC->SetTextColor(RGB(0,0,0));
			break;
		case 1:
			oldcolor = pDC->SetTextColor(RGB(0,255,0));
			break;
		case 2:
			oldcolor = pDC->SetTextColor(RGB(255,0,0));
			break;
		case 3:
			oldcolor = pDC->SetTextColor(RGB(0,0,255));
			break;
        }

		int DTFlags = 0;
		if (pDoc->m_hcentre)
		DTFlags = DT_CENTER;
	    if (pDoc->m_vcentre)
		DTFlags |= DT_VCENTER|DT_SINGLELINE;
		pDC->DrawText(pDoc->GetString(),&rect,DTFlags);
		pDC->SetTextColor(oldcolor);


	    POSITION pos = pDoc->GetStartPosition();
		while (pos)
		{
		COLECntrItem* pCurrentItem = (COLECntrItem*) pDoc->GetNextClientItem(pos);
		pCurrentItem->Draw(pDC, pCurrentItem->m_rect); // ���������� ��������� ������ � ���������
		// ���� ������ �������� ����������, ������ ������������ �����
		if (pCurrentItem == m_pSelection)
		{
		CRectTracker tracker; // ��������� �������� ������������ �����
		SetupTracker(m_pSelection, &tracker); // �������� ���� ������� ��� ���������� ���� ������������ �����
		tracker.Draw(pDC); // ���������� ������������ �����
		}
	}
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
	pTracker->m_rect = pItem->m_rect; // ���������� ������� ������������ ����� ������ ��,
	// ��� � � ����������� �������

	// ���� ������� ������ �������� ��������,
	// ������������ ����� ���������� � ��������� ������
	if (pItem == m_pSelection)
		pTracker->m_nStyle |= CRectTracker::resizeInside;
	
	// ���� ������� ������ �������� ���������
	// ������������ ����� ���������� �������� ������
	if (pItem->GetType() == OT_LINK)
		pTracker->m_nStyle |= CRectTracker::dottedLine;
	else 
	// � ��������� ������� ������������ ����� �������� ������� ������
	pTracker->m_nStyle |= CRectTracker::solidLine;

	// ���� ������ ������ � ������ �������������� "� ��������� ����" 
	// ������������ ����� ������������ ����� ����������
	if (pItem->GetItemState() == COleClientItem::openState || 
		pItem->GetItemState() == COleClientItem::activeUIState)
		pTracker->m_nStyle |= CRectTracker::hatchInside;	
}

COLECntrItem* COLEView::HitTest(CPoint point)
{
	COLEDoc* pDoc = GetDocument(); // �������� ��������� �� ��������
	COLECntrItem* pHitItem = NULL; // ��������� ��������� �� ������� ������ � ����� ������
	
	// ���������� ��������� ��������� �������� � ����������, ����� �� ��� ������������
	// � ����� ������.��������� ������ ���������, �������� � ����� ������, ���� �������.
	POSITION pos = pDoc->GetStartPosition(); // �������� ������� ������� ������� � ���������
	while (pos)
	{
	  //�������� ��������� �� ������� ������ ���������, ������� � ���������� �������
	  COLECntrItem* pCurrentItem = (COLECntrItem*) pDoc->GetNextClientItem(pos);
	  
	  // ���� ������� ������ ����� � ����� ������, ��������� ���
	  if (pCurrentItem->m_rect.PtInRect(point))
		  pHitItem = pCurrentItem;
	  return pHitItem; // ������� ��������� �� ������� ������ � ����� ������
	}
}

	void COLEView::SetSelection(COLECntrItem* pItem)
	{
	    // ���� ������ ������������� � ������ "�� �����", ��������� ���
		if (pItem == NULL || pItem != m_pSelection)
		{
			// �������� ��������� �� �������� ������������� �� ����� ������
		    COleClientItem* pActive = GetDocument()->GetInPlaceActiveItem(this);
			if (pActive != NULL && pActive != pItem)
				pActive->Close(); // ������� �������� ������	
		}
		Invalidate(); // ������������ ����
		m_pSelection = pItem; // ������� ������ ������ �������
	
	}


void COLEView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	// ���������� ������� ������ � ����� ������
	COLECntrItem* pHitItem = HitTest(point);
	// ������ ��� ������� � ��������
	SetSelection(pHitItem); 
	// ���� � ����� ������ ��� �������, �������� �������
	if (pHitItem == NULL)
		return;
	// ������ ������������ ������ �������� �������
	CRectTracker tracker;
	SetupTracker(pHitItem, &tracker);
	UpdateWindow();
	if (tracker.Track(this, point)) // ���� ���������� ������ ������������ �����
	{
		Invalidate(); // ��������� �������������� ������ ������ � ������
		pHitItem->m_rect=tracker.m_rect; // �������� ������ ������� ��� ������
		GetDocument()->SetModifiedFlag(); // ������������� ������� ��������� ���������
	}
	CView::OnLButtonDown(nFlags, point);
}


BOOL COLEView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	// ���� ������ ��������� ��� ����� �������������, � � ���� ���� ���������� ��������� ������
	if (pWnd==this && m_pSelection!=NULL) 
	{
	 CRectTracker tracker; // ��������� ������ ������������ �����
	 SetupTracker(m_pSelection, &tracker); // �������������� ������� ��� ������������ �����
	 // ���� ��������� ��������� ���� ��� ��������� ��� �� ������������ �����
	 // ����������� �������, �������� ����� �� �������
	 if (tracker.SetCursor(pWnd, nHitTest))
	 {
	   return TRUE;
	 }
	}
	 // � ��������� ������� ���������� ����������� ��������� ����,
	 // ������������ ����������� ��
	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void COLEView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	// �������� ��� ����������� ���������� ������ �����
	OnLButtonDown(nFlags, point);

	// ���� ���� ��������� ������ � ����� �������� ������
	if (m_pSelection!=NULL)
	{
	  // ���� � ������ �������� ������ ������������ ������� Ctrl
		if (GetKeyState(VK_CONTROL)<0)
			m_pSelection->DoVerb(OLEIVERB_OPEN, this); // ��������� ������� "�������"
        else 
			m_pSelection->DoVerb(OLEIVERB_PRIMARY, this); // ��������� ������� ������� ��� �������
	}
	CView::OnLButtonDblClk(nFlags, point);
}


