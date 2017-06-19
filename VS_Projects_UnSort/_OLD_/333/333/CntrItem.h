
// CntrItem.h : ��������� ������ CMy333CntrItem
//

#pragma once

class CMy333Doc;
class CMy333View;

class CMy333CntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CMy333CntrItem)

// ������������
public:
	CMy333CntrItem(REOBJECT* preo = NULL, CMy333Doc* pContainer = NULL);
		// ����������. pContainer ����� ����� �������� NULL ��� ���������� IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE ������� ������� � ������ ������������ �
		//  ������� �����������. ������ �������� OLE ��������� �
		//  ����������� �� ��������, �� ������� NULL

// ��������
public:
	CMy333Doc* GetDocument()
		{ return reinterpret_cast<CMy333Doc*>(CRichEditCntrItem::GetDocument()); }
	CMy333View* GetActiveView()
		{ return reinterpret_cast<CMy333View*>(CRichEditCntrItem::GetActiveView()); }

// ����������
public:
	~CMy333CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

