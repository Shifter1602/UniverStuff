#pragma once


// RectDiag dialog

class RectDiag : public CDialog
{
	DECLARE_DYNAMIC(RectDiag)

public:
	RectDiag(CWnd* pParent = NULL);   // standard constructor
	virtual ~RectDiag();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	int m_a;
	int m_b;
	int m_c;
	int m_d;
	};
