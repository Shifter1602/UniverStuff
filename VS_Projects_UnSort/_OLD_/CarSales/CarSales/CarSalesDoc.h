
// CarSalesDoc.h : интерфейс класса CCarSalesDoc
//


#pragma once
#include "CarSalesSet.h"


class CCarSalesDoc : public CDocument
{
protected: // создать только из сериализации
	CCarSalesDoc();
	DECLARE_DYNCREATE(CCarSalesDoc)

// Атрибуты
public:
	CCarSalesSet m_CarSalesSet;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CCarSalesDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
