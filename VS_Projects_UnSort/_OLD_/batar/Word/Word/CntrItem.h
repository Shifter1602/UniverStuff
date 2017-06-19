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

// CntrItem.h : ��������� ������ CWordCntrItem
//

#pragma once

class CWordDoc;
class CWordView;

class CWordCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CWordCntrItem)

// ������������
public:
	CWordCntrItem(REOBJECT* preo = NULL, CWordDoc* pContainer = NULL);
		// ����������. pContainer ����� ����� �������� NULL ��� ���������� IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE ������� ������� � ������ ������������ �
		//  ������� �����������. ������ �������� OLE ��������� �
		//  ����������� �� ��������, �� ������� NULL

// ��������
public:
	CWordDoc* GetDocument()
		{ return reinterpret_cast<CWordDoc*>(CRichEditCntrItem::GetDocument()); }
	CWordView* GetActiveView()
		{ return reinterpret_cast<CWordView*>(CRichEditCntrItem::GetActiveView()); }

// ����������
public:
	~CWordCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

