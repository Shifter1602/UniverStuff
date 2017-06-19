
// CntrItem.cpp : реализация класса CMy333CntrItem
//

#include "stdafx.h"
#include "333.h"

#include "333Doc.h"
#include "333View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CMy333CntrItem

IMPLEMENT_SERIAL(CMy333CntrItem, CRichEditCntrItem, 0)

CMy333CntrItem::CMy333CntrItem(REOBJECT* preo, CMy333Doc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: добавьте код для одноразового вызова конструктора
}

CMy333CntrItem::~CMy333CntrItem()
{
	// TODO: добавьте код очистки
}


// диагностика CMy333CntrItem

#ifdef _DEBUG
void CMy333CntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CMy333CntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

