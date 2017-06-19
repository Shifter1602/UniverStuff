
// 333Doc.h : ��������� ������ CMy333Doc
//


#pragma once


class CMy333Doc : public CRichEditDoc
{
protected: // ������� ������ �� ������������
	CMy333Doc();
	DECLARE_DYNCREATE(CMy333Doc)

// ��������
public:

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CMy333Doc();
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
