
// MDIDoc.cpp : реализация класса CMDIDoc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MDI.h"
#endif

#include "MDIDoc.h"

#include <propkey.h>
#include "OptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMDIDoc

IMPLEMENT_DYNCREATE(CMDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMDIDoc, CDocument)
	ON_COMMAND(ID_TOOLS_OPTIONS, &CMDIDoc::OnToolsOptions)
END_MESSAGE_MAP()


// создание/уничтожение CMDIDoc

CMDIDoc::CMDIDoc()
	: m_string(_T(""))
	, m_colour(0)
	, m_hcentre(false)
	, m_vcentre(false)
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CMDIDoc::~CMDIDoc()
{
}

BOOL CMDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	m_string="Привет, мир!";
	m_colour=0; //черный
	m_hcentre=TRUE;
	m_vcentre=TRUE;

	return TRUE;
}


// сериализация CMDIDoc

void CMDIDoc::Serialize(CArchive& ar)
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
		// TODO: добавьте код загрузки
		ar >> m_string;
		ar >> m_colour;
		ar >> m_hcentre;
		ar >> m_vcentre;
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMDIDoc::SetSearchContent(const CString& value)
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

// диагностика CMDIDoc

#ifdef _DEBUG
void CMDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CMDIDoc


CString CMDIDoc::GetString(void)
{
	return m_string;
}


void CMDIDoc::OnToolsOptions()
{
	// TODO: добавьте свой код обработчика команд
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
