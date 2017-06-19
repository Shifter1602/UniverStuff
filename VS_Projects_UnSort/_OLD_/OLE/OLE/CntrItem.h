
// CntrItem.h : интерфейс класса COLECntrItem
//

#pragma once
#include "atltypes.h"

class COLEDoc;
class COLEView;

class COLECntrItem : public COleClientItem
{
	DECLARE_SERIAL(COLECntrItem)

// Конструкторы
public:
	COLECntrItem(COLEDoc* pContainer = NULL);
		// Примечание. pContainer может иметь значение NULL для разрешения IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE требует наличия у класса конструктора с
		//  нулевым аргументами. Обычно элементы OLE создаются с
		//  указателями на документ, не равными NULL

// Атрибуты
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

// Реализация
public:
	~COLECntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
	CRect m_rect;
};

