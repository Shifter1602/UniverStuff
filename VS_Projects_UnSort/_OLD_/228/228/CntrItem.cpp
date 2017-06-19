
// CntrItem.cpp : ���������� ������ CMy228CntrItem
//

#include "stdafx.h"
#include "228.h"

#include "228Doc.h"
#include "228View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CMy228CntrItem

IMPLEMENT_SERIAL(CMy228CntrItem, COleClientItem, 0)

CMy228CntrItem::CMy228CntrItem(CMy228Doc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: �������� ��� ��� ������������ ������ ������������
}

CMy228CntrItem::~CMy228CntrItem()
{
	// TODO: �������� ��� �������
}

void CMy228CntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
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

BOOL CMy228CntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// �� ����� ��������� �� ����� CMy228CntrItem::OnChangeItemPosition
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

	return TRUE;
}

BOOL CMy228CntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}

void CMy228CntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// �� ����� ��������� �� ����� CMy228CntrItem::OnGetItemPosition
	//  ����� ������ ��� ����������� ������������ ����� ��������. ������ ���� 
	//  ������������� ���������� ������� ��������� �������� �� ��������� � 
	//  �������������, ������������� ��� ���������. ����� �������� ��� �������������, �������� 
	//  CMy228CntrItem::GetActiveView.

	// TODO: ���������� ���������� ������������� (� ��������) � rPosition

	CSize size;
	rPosition.SetRectEmpty();
	if (GetExtent(&size, m_nDrawAspect))
	{
		CMy228View* pView = GetActiveView();
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
		rPosition.SetRect(10, 10, 210, 210);
}

void CMy228CntrItem::OnActivate()
{
    // ��������� ������ ���� ������� ��������� �� ����� ��� ����� �����
    CMy228View* pView = GetActiveView();
    ASSERT_VALID(pView);
	if (!pView)
		return;
    COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
    if (pItem != NULL && pItem != this)
        pItem->Close();
    
    COleClientItem::OnActivate();
}

void CMy228CntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

    DWORD dwMisc = 0;
    m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
    if (dwMisc & OLEMISC_INSIDEOUT)
        DoVerb(OLEIVERB_HIDE, NULL);
}

void CMy228CntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// �������� ������� ������� ����� ��� ������ ������ COleClientItem.
	// ��������� ��� ���� ������������� ��������� ��������� m_pDocument, ������������� ��
	//  CMy228CntrItem::GetDocument, ������������� ������� �������
	//  ������� ����� Serialize.
	COleClientItem::Serialize(ar);

	// ��� �������� ��� ���������� ������, ����������� � CMy228CntrItem
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
	}
	else
	{
		// TODO: �������� ��� ��������
	}
}


// ����������� CMy228CntrItem

#ifdef _DEBUG
void CMy228CntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CMy228CntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

