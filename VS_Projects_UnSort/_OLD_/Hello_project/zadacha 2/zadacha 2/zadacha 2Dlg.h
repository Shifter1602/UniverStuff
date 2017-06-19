
// zadacha 2Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно Czadacha2Dlg
class Czadacha2Dlg : public CDialogEx
{
// Создание
public:
	Czadacha2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_ZADACHA2_DIALOG };

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
	double m_euro;
	double m_usd;
	double m_su1;
	double m_su2;
	afx_msg void OnBnClickedButton1();
	int m_radio;
	afx_msg void OnBnClickedButton2();
};
