// Этот исходный код MFC Samples демонстрирует функционирование пользовательского интерфейса Fluent на основе MFC в Microsoft Office
// ("Fluent UI") и предоставляется исключительно как справочный материал в качестве дополнения к
// справочнику по пакету Microsoft Foundation Classes и связанной электронной документации,
// включенной в программное обеспечение библиотеки MFC C++. 
// Условия лицензионного соглашения на копирование, использование или распространение Fluent UI доступны отдельно. 
// Для получения дополнительных сведений о нашей лицензионной программе Fluent UI посетите веб-узел
// http://msdn.microsoft.com/officeui.
//
// (C) Корпорация Майкрософт (Microsoft Corp.)
// Все права защищены.

// CntrItem.cpp : реализация класса CWordCntrItem
//

#include "stdafx.h"
#include "Word.h"

#include "WordDoc.h"
#include "WordView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CWordCntrItem

IMPLEMENT_SERIAL(CWordCntrItem, CRichEditCntrItem, 0)

CWordCntrItem::CWordCntrItem(REOBJECT* preo, CWordDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: добавьте код для одноразового вызова конструктора
}

CWordCntrItem::~CWordCntrItem()
{
	// TODO: добавьте код очистки
}


// диагностика CWordCntrItem

#ifdef _DEBUG
void CWordCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CWordCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

