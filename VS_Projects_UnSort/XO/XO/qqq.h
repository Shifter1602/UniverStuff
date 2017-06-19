#pragma once


// qqq dialog

class qqq : public CDialog
{
	DECLARE_DYNAMIC(qqq)

public:
	qqq(CWnd* pParent = NULL);   // standard constructor
	virtual ~qqq();

// Dialog Data
	enum { IDD = IDD_FORMVIEW1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
