
// MDI1Doc.h : ��������� ������ CMDI1Doc
//


#pragma once


class CMDI1Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CMDI1Doc();
	DECLARE_DYNCREATE(CMDI1Doc)

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
	virtual ~CMDI1Doc();
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
private:
	CString m_string;
public:
	CString GetString(void);
	afx_msg void OnToolOptions();
	int m_color;
	BOOL m_hcenter;
	BOOL m_vcenter;
};
