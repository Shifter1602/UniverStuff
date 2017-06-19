
// OLEDoc.cpp : ���������� ������ COLEDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "OLE.h"
#endif

#include "OLEDoc.h"
#include "CntrItem.h"

#include <propkey.h>
#include "OptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COLEDoc

IMPLEMENT_DYNCREATE(COLEDoc, COleDocument)

BEGIN_MESSAGE_MAP(COLEDoc, COleDocument)
	// �������� ���������� ���������� OLE
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, &COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, &COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, &COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_TOOLS_OPTIONS, &COLEDoc::OnToolsOptions)
END_MESSAGE_MAP()


// ��������/����������� COLEDoc

COLEDoc::COLEDoc()
	: m_string(_T(""))
	, m_colour(0)
	, m_hcentre(false)
	, m_vcentre(false)
{
	// ����������� ������������ ����� OLE
	EnableCompoundFile();

	// TODO: �������� ��� ��� ������������ ������ ������������

}

COLEDoc::~COLEDoc()
{
}

BOOL COLEDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;
	
	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)
	m_string="������, ���!";
	m_colour=0;
	m_hcentre=TRUE;
	m_vcentre=TRUE;
	

	return TRUE;
}




// ������������ COLEDoc

void COLEDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
		ar << m_string;
		ar << m_colour;
		ar << m_hcentre;
		ar << m_vcentre;
	}
	else
	{
		ar >> m_string;
		ar >> m_colour;
		ar >> m_hcentre;
		ar >> m_vcentre;
	}

	// ����� �������� ������ COleDocument �������� ������������
	//  �������� COleClientItem ��������� ����������.
	COleDocument::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void COLEDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void COLEDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void COLEDoc::SetSearchContent(const CString& value)
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

// ����������� COLEDoc

#ifdef _DEBUG
void COLEDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void COLEDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG


// ������� COLEDoc

CString COLEDoc::GetString(void)
{
	return m_string;
}

void COLEDoc::OnToolsOptions()
{
	COptionsDlg dlg;
	dlg.m_string=m_string;
	dlg.m_colour=m_colour;
	dlg.m_hcentre=m_hcentre;
	dlg.m_vcentre=m_vcentre;
		if (dlg.DoModal()==IDOK)
		{
			m_string=dlg.m_string;
			m_colour=dlg.m_colour;
	        m_hcentre=dlg.m_hcentre;
	        m_vcentre=dlg.m_vcentre;
			SetModifiedFlag();
			UpdateAllViews(NULL);
		}
}
