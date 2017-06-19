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

// CntrItem.h : интерфейс класса CWordCntrItem
//

#pragma once

class CWordDoc;
class CWordView;

class CWordCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CWordCntrItem)

// Конструкторы
public:
	CWordCntrItem(REOBJECT* preo = NULL, CWordDoc* pContainer = NULL);
		// Примечание. pContainer может иметь значение NULL для разрешения IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE требует наличия у класса конструктора с
		//  нулевым аргументами. Обычно элементы OLE создаются с
		//  указателями на документ, не равными NULL

// Атрибуты
public:
	CWordDoc* GetDocument()
		{ return reinterpret_cast<CWordDoc*>(CRichEditCntrItem::GetDocument()); }
	CWordView* GetActiveView()
		{ return reinterpret_cast<CWordView*>(CRichEditCntrItem::GetActiveView()); }

// Реализация
public:
	~CWordCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

