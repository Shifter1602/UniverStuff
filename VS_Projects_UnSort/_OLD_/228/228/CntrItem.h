
// CntrItem.h : ��������� ������ CMy228CntrItem
//

#pragma once

class CMy228Doc;
class CMy228View;

class CMy228CntrItem : public COleClientItem
{
	DECLARE_SERIAL(CMy228CntrItem)

// ������������
public:
	CMy228CntrItem(CMy228Doc* pContainer = NULL);
		// ����������. pContainer ����� ����� �������� NULL ��� ���������� IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE ������� ������� � ������ ������������ �
		//  ������� �����������. ������ �������� OLE ��������� �
		//  ����������� �� ��������, �� ������� NULL

// ��������
public:
	CMy228Doc* GetDocument()
		{ return reinterpret_cast<CMy228Doc*>(COleClientItem::GetDocument()); }
	CMy228View* GetActiveView()
		{ return reinterpret_cast<CMy228View*>(COleClientItem::GetActiveView()); }

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
	~CMy228CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

