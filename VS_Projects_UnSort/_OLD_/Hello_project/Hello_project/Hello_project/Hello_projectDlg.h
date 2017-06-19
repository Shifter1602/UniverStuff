
// Hello_projectDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CHello_projectDlg
class CHello_projectDlg : public CDialogEx
{
// Создание
public:
	CHello_projectDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_HELLO_PROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
	CString m_edit;
};
