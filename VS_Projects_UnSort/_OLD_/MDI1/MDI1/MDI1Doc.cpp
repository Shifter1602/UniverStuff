
// MDI1Doc.cpp : ���������� ������ CMDI1Doc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MDI1.h"
#endif

#include "MDI1Doc.h"

#include "OptionsDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMDI1Doc

IMPLEMENT_DYNCREATE(CMDI1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMDI1Doc, CDocument)
	ON_COMMAND(ID_TOOL_OPTIONS, &CMDI1Doc::OnToolOptions)
END_MESSAGE_MAP()


// ��������/����������� CMDI1Doc

CMDI1Doc::CMDI1Doc()
	: m_string(_T(""))
{
	// TODO: �������� ��� ��� ������������ ������ ������������

}

CMDI1Doc::~CMDI1Doc()
{
}

BOOL CMDI1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)
	m_string="Hello World!!!";
	m_color =0;
	m_hcenter = TRUE;
	m_vcenter = TRUE;


	return TRUE;
}




// ������������ CMDI1Doc

void CMDI1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
		ar << m_string;
		ar << m_color;
		ar << m_hcenter;
		ar << m_vcenter;
	}
	else
	{
		// TODO: �������� ��� ��������
		ar >> m_string;
		ar >> m_color;
		ar >> m_hcenter;
		ar >> m_vcenter;
	}
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CMDI1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CMDI1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CMDI1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CMDI1Doc

#ifdef _DEBUG
void CMDI1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDI1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// ������� CMDI1Doc


CString CMDI1Doc::GetString(void)
{
	return m_string;
}


void CMDI1Doc::OnToolOptions()
{
	// TODO: �������� ���� ��� ����������� ������
	COptionsDlg dlg;
	dlg.m_string=m_string;
	dlg.m_radio=m_color;
	dlg.m_hcenter=m_hcenter;
	dlg.m_vcenter=m_vcenter;
	if(dlg.DoModal()==IDOK)
	{
		m_string=dlg.m_string;
		m_color=dlg.m_radio;
		m_hcenter=dlg.m_hcenter;
		m_vcenter=dlg.m_vcenter;
		SetModifiedFlag();
		UpdateAllViews(NULL);
	}

}
