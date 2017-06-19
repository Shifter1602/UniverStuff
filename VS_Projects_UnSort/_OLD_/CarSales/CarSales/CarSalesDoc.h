
// CarSalesDoc.h : ��������� ������ CCarSalesDoc
//


#pragma once
#include "CarSalesSet.h"


class CCarSalesDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CCarSalesDoc();
	DECLARE_DYNCREATE(CCarSalesDoc)

// ��������
public:
	CCarSalesSet m_CarSalesSet;

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CCarSalesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
