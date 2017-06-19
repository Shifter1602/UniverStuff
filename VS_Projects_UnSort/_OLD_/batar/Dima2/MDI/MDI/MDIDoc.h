
// MDIDoc.h : интерфейс класса CMDIDoc
//


#pragma once


class CMDIDoc : public CDocument
{
protected: // создать только из сериализации
	CMDIDoc();
	DECLARE_DYNCREATE(CMDIDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMDIDoc();
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
private:
	CString m_string;
public:
	CString GetString(void);
	afx_msg void OnToolsOptions();
	int m_colour;
	bool m_hcentre;
	bool m_vcentre;
};
