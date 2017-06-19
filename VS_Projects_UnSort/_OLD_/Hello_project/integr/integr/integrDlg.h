
// integrDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CintegrDlg
class CintegrDlg : public CDialogEx
{
// Создание
public:
	CintegrDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_INTEGR_DIALOG };

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
	double m_a;
	double m_b;
	double m_c;
	double m_d;
	double m_step;
	double m_integr;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
