
// CntrItem.cpp : ���������� ������ CMy333CntrItem
//

#include "stdafx.h"
#include "333.h"

#include "333Doc.h"
#include "333View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CMy333CntrItem

IMPLEMENT_SERIAL(CMy333CntrItem, CRichEditCntrItem, 0)

CMy333CntrItem::CMy333CntrItem(REOBJECT* preo, CMy333Doc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: �������� ��� ��� ������������ ������ ������������
}

CMy333CntrItem::~CMy333CntrItem()
{
	// TODO: �������� ��� �������
}


// ����������� CMy333CntrItem

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

