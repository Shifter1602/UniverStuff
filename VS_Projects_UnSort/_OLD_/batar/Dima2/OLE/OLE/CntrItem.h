
// CntrItem.h : ��������� ������ COLECntrItem
//

#pragma once
#include "atltypes.h"

class COLEDoc;
class COLEView;

class COLECntrItem : public COleClientItem
{
	DECLARE_SERIAL(COLECntrItem)

// ������������
public:
	COLECntrItem(COLEDoc* pContainer = NULL);
		// ����������. pContainer ����� ����� �������� NULL ��� ���������� IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE ������� ������� � ������ ������������ �
		//  ������� �����������. ������ �������� OLE ��������� �
		//  ����������� �� ��������, �� ������� NULL

// ��������
public:
	COLEDoc* GetDocument()
		{ return reinterpret_cast<COLEDoc*>(COleClientItem::GetDocument()); }
	COLEView* GetActiveView()
		{ return reinterpret_cast<COLEView*>(COleClientItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);

// ����������
public:
	~COLECntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
	CRect m_rect;
};

