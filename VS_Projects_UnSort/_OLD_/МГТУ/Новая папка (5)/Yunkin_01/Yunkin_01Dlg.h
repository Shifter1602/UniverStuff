// Yunkin_01Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CYunkin_01Dlg dialog
class CYunkin_01Dlg : public CDialog
{
// Construction
public:
	CYunkin_01Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_YUNKIN_01_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox s;
	CListBox z;
	CListBox x;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton3();
};
