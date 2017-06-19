#pragma once
#include "afxwin.h"


// TextDialog dialog

class TextDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TextDialog)

public:
	TextDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~TextDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cEdit1;
	CString m_str;
	};
