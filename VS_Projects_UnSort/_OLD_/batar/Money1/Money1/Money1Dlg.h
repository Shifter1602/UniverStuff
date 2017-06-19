
// Money1Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CMoney1Dlg
class CMoney1Dlg : public CDialogEx
{
// Создание
public:
	CMoney1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MONEY1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	int m_raido;
	double m_euro;
	double m_usd;
	double m_sum1;
	double m_sum2;
	afx_msg void OnBnClickedButton1();
	int m_radio;
	afx_msg void OnBnClickedButton2();
};
