#pragma once


// диалоговое окно OptionsDlg

class OptionsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OptionsDlg)

public:
	OptionsDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~OptionsDlg();

// Данные диалогового окна
	enum { IDD = IDD_OPTIONSDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
