
// BvzDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CBvzDlg
class CBvzDlg : public CDialogEx
{
// Создание
public:
	CBvzDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_BVZ_DIALOG };

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
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit4();
	double m_ch1;
	double m_ch2;
	double m_ch3;
	double m_max;
	double m_min;
	double m_sred;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
