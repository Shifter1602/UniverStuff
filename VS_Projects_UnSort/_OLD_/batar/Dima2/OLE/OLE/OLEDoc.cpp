
// OLEDoc.cpp : реализация класса COLEDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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
	// Включите реализацию контейнера OLE
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, &COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, &COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, &COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_TOOLS_OPTIONS, &COLEDoc::OnToolsOptions)
END_MESSAGE_MAP()


// создание/уничтожение COLEDoc

COLEDoc::COLEDoc()
	: m_string(_T(""))
	, m_colour(0)
	, m_hcentre(false)
	, m_vcentre(false)
{
	// Используйте объединенные файлы OLE
	EnableCompoundFile();

	// TODO: добавьте код для одноразового вызова конструктора

}

COLEDoc::~COLEDoc()
{
}

BOOL COLEDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;
	
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	m_string="Привет, мир!";
	m_colour=0;
	m_hcentre=TRUE;
	m_vcentre=TRUE;
	

	return TRUE;
}




// сериализация COLEDoc

void COLEDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
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

	// Вызов базового класса COleDocument включает сериализацию
	//  объектов COleClientItem документа контейнера.
	COleDocument::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void COLEDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
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

// Поддержка обработчиков поиска
void COLEDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
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

// диагностика COLEDoc

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


// команды COLEDoc

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
