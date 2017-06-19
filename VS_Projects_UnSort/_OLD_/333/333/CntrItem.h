
// CntrItem.h : интерфейс класса CMy333CntrItem
//

#pragma once

class CMy333Doc;
class CMy333View;

class CMy333CntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CMy333CntrItem)

// Конструкторы
public:
	CMy333CntrItem(REOBJECT* preo = NULL, CMy333Doc* pContainer = NULL);
		// Примечание. pContainer может иметь значение NULL для разрешения IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE требует наличия у класса конструктора с
		//  нулевым аргументами. Обычно элементы OLE создаются с
		//  указателями на документ, не равными NULL

// Атрибуты
public:
	CMy333Doc* GetDocument()
		{ return reinterpret_cast<CMy333Doc*>(CRichEditCntrItem::GetDocument()); }
	CMy333View* GetActiveView()
		{ return reinterpret_cast<CMy333View*>(CRichEditCntrItem::GetActiveView()); }

// Реализация
public:
	~CMy333CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

