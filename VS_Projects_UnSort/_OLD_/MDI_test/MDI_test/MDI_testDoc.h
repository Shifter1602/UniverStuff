
// MDI_testDoc.h : ��������� ������ CMDI_testDoc
//


#pragma once


class CMDI_testDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CMDI_testDoc();
	DECLARE_DYNCREATE(CMDI_testDoc)

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CMDI_testDoc();
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
