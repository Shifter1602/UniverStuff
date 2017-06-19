
// 333View.h : интерфейс класса CMy333View
//

#pragma once

class CMy333CntrItem;

class CMy333View : public CRichEditView
{
protected: // создать только из сериализации
	CMy333View();
	DECLARE_DYNCREATE(CMy333View)

// Атрибуты
public:
	CMy333Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMy333View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // отладочная версия в 333View.cpp
inline CMy333Doc* CMy333View::GetDocument() const
   { return reinterpret_cast<CMy333Doc*>(m_pDocument); }
#endif

