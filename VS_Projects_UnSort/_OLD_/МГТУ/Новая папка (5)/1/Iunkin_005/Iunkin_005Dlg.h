// Iunkin_005Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CIunkin_005Dlg dialog
class CIunkin_005Dlg : public CDialog
{
// Construction
public:
	CIunkin_005Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IUNKIN_005_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void Draw(void);
	void ReDraw(void);
	CComboBox Combo1;
	afx_msg void OnCbnSelchangeCombo1();
	void ParaDraw(void);
	afx_msg void OnEnChangeEdit1();
	CEdit Edit1;
	LRESULT OnMyMessage(WPARAM W, LPARAM L);
	LRESULT OnMyMessage_1(WPARAM W, LPARAM L);
	void Draw1(void);
	void ParaDraw1(void);
};
