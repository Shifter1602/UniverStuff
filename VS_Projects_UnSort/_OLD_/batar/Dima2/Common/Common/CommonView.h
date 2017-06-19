
// CommonView.h : интерфейс класса CCommonView
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"


class CCommonView : public CScrollView
{
protected: // создать только из сериализации
	CCommonView();
	DECLARE_DYNCREATE(CCommonView)

// Атрибуты
public:
	CCommonDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CCommonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSmallButton();
	afx_msg void OnLargeButton();
	afx_msg void OnListButton();
	afx_msg void OnReportButton();
	afx_msg void OnBoldButton();
	afx_msg void OnLeftButton();
	afx_msg void OnRightButton();
	afx_msg void OnCenterButton();
	
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_progressbar;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL m_timer;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CSliderCtrl m_trackbar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CIPAddressCtrl m_ipaddress;
	CDateTimeCtrl m_day;
	CSpinButtonCtrl m_updown;
	CEdit m_buddy;
	CListCtrl m_list;
	CImageList m_smallimagelist;
	CImageList m_largeimagelist;
	CButton m_smallbutton;
	CButton m_largebutton;
	CButton m_listbutton;
	CButton m_reportbutton;
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	CTreeCtrl m_tree;
	CImageList m_treeimagelist;
	CRichEditCtrl m_richedit;
	CButton m_bold;
	CButton m_left;
	CButton m_right;
	CButton m_center;
	CMonthCalCtrl m_month;
};

#ifndef _DEBUG  // отладочная версия в CommonView.cpp
inline CCommonDoc* CCommonView::GetDocument() const
   { return reinterpret_cast<CCommonDoc*>(m_pDocument); }
#endif

