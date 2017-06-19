
// CntrItem.cpp : ���������� ������ COLECntrItem
//

#include "stdafx.h"
#include "OLE.h"

#include "OLEDoc.h"
#include "OLEView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� COLECntrItem

IMPLEMENT_SERIAL(COLECntrItem, COleClientItem, 0)

COLECntrItem::COLECntrItem(COLEDoc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: �������� ��� ��� ������������ ������ ������������
	m_rect = CRect(10,10,210,210);
}

COLECntrItem::~COLECntrItem()
{
	// TODO: �������� ��� �������
}

void COLECntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// �� ����� �������������� �������� (���� �� �����, ���� ����� �� ��������� ������),
	//  ������������ ����������� OnChange �� ��������� ���������
	//  ����� �������� ��� ����������� ����������� ��� �����������.

	// TODO: �������� ������� ������������ ����������� ������ UpdateAllViews
	//  (� ����������, ����������� ��� ������ ����������)

	GetDocument()->UpdateAllViews(NULL);
		// �������� ��� ������������� ��� ��������
}

BOOL COLECntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// �� ����� ��������� �� ����� COLECntrItem::OnChangeItemPosition
	//  ���������� �������� ��� ��������� ��������� ����
	//  �� �����. ������ ��� ��������� � ������, ����� ������ ���������
	//  �� ������� �������� ����� �������, ��� ���������� ��� ��������, ���� � ������
	//  ��������� �������� �� �����.
	//
	// �� ��������� ���������� ������� �����, ������� ��������
	//  COleClientItem::SetItemRects ��� ����������� ��������
	//  � ����� ���������.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: �������� ��������� ��� �������������� ��� ��������
	m_rect= rectPos;
	GetDocument()->SetModifiedFlag();
	GetDocument()->UpdateAllViews(NULL);
	return TRUE;
}

BOOL COLECntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}

void COLECntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// �� ����� ��������� �� ����� COLECntrItem::OnGetItemPosition
	//  ����� ������ ��� ����������� ������������ ����� ��������. ������ ���� 
	//  ������������� ���������� ������� ��������� �������� �� ��������� � 
	//  �������������, ������������� ��� ���������. ����� �������� ��� �������������, �������� 
	//  COLECntrItem::GetActiveView.

	// TODO: ���������� ���������� ������������� (� ��������) � rPosition

	/*CSize size;
	rPosition.SetRectEmpty();
	if (GetExtent(&size, m_nDrawAspect))
	{
		COLEView* pView = GetActiveView();
		ASSERT_VALID(pView);
		if (!pView)
			return;
		CDC *pDC = pView->GetDC();
		ASSERT(pDC);
		if (!pDC)
			return;
		pDC->HIMETRICtoLP(&size);
		rPosition.SetRect(10, 10, size.cx + 10, size.cy + 10);
	}
	else
		rPosition.SetRect(10, 10, 210, 210);*/
	rPosition=m_rect;
}

void COLECntrItem::OnActivate()
{
    // ��������� ������ ���� ������� ��������� �� ����� ��� ����� �����
    COLEView* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void COLECntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void COLECntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// �������� ������� ������� ����� ��� ������ ������ COleClientItem.
	// ��������� ��� ���� ������������� ��������� ��������� m_pDocument, ������������� ��
	//  COLECntrItem::GetDocument, ������������� ������� �������
	//  ������� ����� Serialize.
	COleClientItem::Serialize(ar);

	// ��� �������� ��� ���������� ������, ����������� � COLECntrItem
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
		ar << m_rect;
	}
	else
	{
		// TODO: �������� ��� ��������
		ar >> m_rect;
	}
}


// ����������� COLECntrItem

#ifdef _DEBUG
void COLECntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void COLECntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

