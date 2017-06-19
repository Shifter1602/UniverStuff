// ���� �������� ��� MFC Samples ������������� ���������������� ����������������� ���������� Fluent �� ������ MFC � Microsoft Office
// ("Fluent UI") � ��������������� ������������� ��� ���������� �������� � �������� ���������� �
// ����������� �� ������ Microsoft Foundation Classes � ��������� ����������� ������������,
// ���������� � ����������� ����������� ���������� MFC C++. 
// ������� ������������� ���������� �� �����������, ������������� ��� ��������������� Fluent UI �������� ��������. 
// ��� ��������� �������������� �������� � ����� ������������ ��������� Fluent UI �������� ���-����
// http://msdn.microsoft.com/officeui.
//
// (C) ���������� ���������� (Microsoft Corp.)
// ��� ����� ��������.

// CntrItem.cpp : ���������� ������ CWordCntrItem
//

#include "stdafx.h"
#include "Word.h"

#include "WordDoc.h"
#include "WordView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CWordCntrItem

IMPLEMENT_SERIAL(CWordCntrItem, CRichEditCntrItem, 0)

CWordCntrItem::CWordCntrItem(REOBJECT* preo, CWordDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: �������� ��� ��� ������������ ������ ������������
}

CWordCntrItem::~CWordCntrItem()
{
	// TODO: �������� ��� �������
}


// ����������� CWordCntrItem

#ifdef _DEBUG
void CWordCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CWordCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

