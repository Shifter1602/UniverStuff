
// CarSalesView.cpp : ���������� ������ CCarSalesView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COleDBRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_EDIT, &CCarSalesView::OnRecordEdit)
	ON_COMMAND(ID_RECORD_DELETE, &CCarSalesView::OnRecordDelete)
END_MESSAGE_MAP()

// ��������/����������� CCarSalesView

CCarSalesView::CCarSalesView()
	: COleDBRecordView(CCarSalesView::IDD)
{
	m_pSet = NULL;
	// TODO: �������� ��� ��������

}

CCarSalesView::~CCarSalesView()
{
}

void CCarSalesView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	// ����� �������� ������� DDX_* , � ����� ������ API SetDlgItem*/GetDlgItem* ��� ����� ���� ������ � ��������������
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// ��� ��������� �������������� �������� ��. ������� MSDN � OLEDB
	::SetDlgItemText(m_hWnd, IDC_SALEID_EDIT, m_pSet->m_SaleID);
	::SetDlgItemText(m_hWnd, IDC_CARMARK_EDIT, m_pSet->m_CarMark);
	::SetDlgItemText(m_hWnd, IDC_CARMODEL_EDIT, m_pSet->m_CarModel);
	::SetDlgItemText(m_hWnd, IDC_CARPRICE_EDIT, m_pSet->m_CarPrice);
	::SetDlgItemText(m_hWnd, IDC_DATASALE_EDIT, m_pSet->m_DataOfSale);
}

BOOL CCarSalesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
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
			// �� ������� ������� ����� �������. ���� recordset �������� 
			// �������� ����������, ��������� � ����������
			// ������������� ����� ������� ���������� ����� �������
			// ������ OpenAll().

			AfxMessageBox(_T("�� ������� ������� ����� �������."), MB_OK);
			// ��������� ������� "��������� ������" � "���������� ������",
			// ��������� ������� �������� ������� ������ ���
			// �������� RowSet �������� � ����
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// ����� ����� ���� (�� �������� ������� �����)
			AfxMessageBox(_T("����� ������� ������, �� � ��� ��� ����� ��� ��������."), MB_OK);
			// ��������� ������� "��������� ������" � "���������� ������"
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();
	m_pSet->MoveFirst();//Move to first entry
	UpdateData();

}


// ������ CCarSalesView

BOOL CCarSalesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CCarSalesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CCarSalesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CCarSalesView

#ifdef _DEBUG
void CCarSalesView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void CCarSalesView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

CCarSalesDoc* CCarSalesView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCarSalesDoc)));
	return (CCarSalesDoc*)m_pDocument;
}
#endif //_DEBUG


// ��������� ���� ������ CCarSalesView
CRowset<>* CCarSalesView::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}



// ����������� ��������� CCarSalesView


void CCarSalesView::OnRecordEdit()
{
	// TODO: �������� ���� ��� ����������� ������
	
}


void CCarSalesView::OnRecordDelete()
{
	// TODO: �������� ���� ��� ����������� ������
	if(MessageBox("Delete?","Delete",MB_ICONQUESTION|MB_YESNO)==IDYES)
	{
		m_pSet->Delete();
		m_pSet->MoveFirst();
		UpdateData();
	}
}
