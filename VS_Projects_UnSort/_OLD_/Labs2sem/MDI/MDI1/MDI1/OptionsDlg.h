#pragma once


// диалоговое окно COptionsDlg

class COptionsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COptionsDlg)

public:
	COptionsDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~COptionsDlg();

// Данные диалогового окна
	enum { IDD = IDD_OPTIONS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeStringEdit();
	CString m_string;
	afx_msg void OnBnClickedRadio4();
	int m_radio;
};
