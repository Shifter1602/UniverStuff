
// OLEDoc.h : ��������� ������ COLEDoc
//


#pragma once


class COLEDoc : public COleDocument
{
protected: // ������� ������ �� ������������
	COLEDoc();
	DECLARE_DYNCREATE(COLEDoc)

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
	virtual ~COLEDoc();
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
	afx_msg void OnToolsOptions();
	int m_colour;
	bool m_hcentre;
	bool m_vcentre;
};
