
// CarSalesView.cpp : реализация класса CCarSalesView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "CarSales.h"
#endif

#include "CarSalesSet.h"
#include "CarSalesDoc.h"
#include "CarSalesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCarSalesView

IMPLEMENT_DYNCREATE(CCarSalesView, COleDBRecordView)

BEGIN_MESSAGE_MAP(CCarSalesView, COleDBRecordView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COleDBRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_EDIT, &CCarSalesView::OnRecordEdit)
	ON_COMMAND(ID_RECORD_DELETE, &CCarSalesView::OnRecordDelete)
END_MESSAGE_MAP()

// создание/уничтожение CCarSalesView

CCarSalesView::CCarSalesView()
	: COleDBRecordView(CCarSalesView::IDD)
{
	m_pSet = NULL;
	// TODO: добавьте код создания

}

CCarSalesView::~CCarSalesView()
{
}

void CCarSalesView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	// можно вставить функции DDX_* , а также вызовы API SetDlgItem*/GetDlgItem* для связи базы данных с представлением
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// Для получения дополнительных сведений см. примеры MSDN и OLEDB
	::SetDlgItemText(m_hWnd, IDC_SALEID_EDIT, m_pSet->m_SaleID);
	::SetDlgItemText(m_hWnd, IDC_CARMARK_EDIT, m_pSet->m_CarMark);
	::SetDlgItemText(m_hWnd, IDC_CARMODEL_EDIT, m_pSet->m_CarModel);
	::SetDlgItemText(m_hWnd, IDC_CARPRICE_EDIT, m_pSet->m_CarPrice);
	::SetDlgItemText(m_hWnd, IDC_DATASALE_EDIT, m_pSet->m_DataOfSale);
}

BOOL CCarSalesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return COleDBRecordView::PreCreateWindow(cs);
}

void CCarSalesView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_CarSalesSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr))
		{
			// Не удается открыть набор записей. Если recordset является 
			// хранимой процедурой, убедитесь в правильной
			// инициализации любых входных параметров перед вызовом
			// метода OpenAll().

			AfxMessageBox(_T("Не удалось открыть набор записей."), MB_OK);
			// Отключите команды "Следующая запись" и "Предыдущая запись",
			// поскольку попытка изменить текущую запись без
			// открытия RowSet приведет к сбою
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// набор строк пуст (не содержит никаких строк)
			AfxMessageBox(_T("Набор записей открыт, но в нем нет строк для возврата."), MB_OK);
			// Отключите команды "Следующая запись" и "Предыдущая запись"
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();
	m_pSet->MoveFirst();//Move to first entry
	UpdateData();

}


// печать CCarSalesView

BOOL CCarSalesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CCarSalesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CCarSalesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CCarSalesView

#ifdef _DEBUG
void CCarSalesView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void CCarSalesView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

CCarSalesDoc* CCarSalesView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCarSalesDoc)));
	return (CCarSalesDoc*)m_pDocument;
}
#endif //_DEBUG


// поддержка базы данных CCarSalesView
CRowset<>* CCarSalesView::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}



// обработчики сообщений CCarSalesView


void CCarSalesView::OnRecordEdit()
{
	// TODO: добавьте свой код обработчика команд
	
}


void CCarSalesView::OnRecordDelete()
{
	// TODO: добавьте свой код обработчика команд
	if(MessageBox("Delete?","Delete",MB_ICONQUESTION|MB_YESNO)==IDYES)
	{
		m_pSet->Delete();
		m_pSet->MoveFirst();
		UpdateData();
	}
}
