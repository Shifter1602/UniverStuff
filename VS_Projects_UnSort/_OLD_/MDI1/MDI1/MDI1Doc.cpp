
// MDI1Doc.cpp : реализация класса CMDI1Doc
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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


// создание/уничтожение CMDI1Doc

CMDI1Doc::CMDI1Doc()
	: m_string(_T(""))
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CMDI1Doc::~CMDI1Doc()
{
}

BOOL CMDI1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	m_string="Hello World!!!";
	m_color =0;
	m_hcenter = TRUE;
	m_vcenter = TRUE;


	return TRUE;
}




// сериализация CMDI1Doc

void CMDI1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
		ar << m_string;
		ar << m_color;
		ar << m_hcenter;
		ar << m_vcenter;
	}
	else
	{
		// TODO: добавьте код загрузки
		ar >> m_string;
		ar >> m_color;
		ar >> m_hcenter;
		ar >> m_vcenter;
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMDI1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMDI1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
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

// диагностика CMDI1Doc

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


// команды CMDI1Doc


CString CMDI1Doc::GetString(void)
{
	return m_string;
}


void CMDI1Doc::OnToolOptions()
{
	// TODO: добавьте свой код обработчика команд
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
