
// Hello_projectDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CHello_projectDlg
class CHello_projectDlg : public CDialogEx
{
// ��������
public:
	CHello_projectDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_HELLO_PROJECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_edit;
	afx_msg void OnBnClickedButton1();
	CString m_edit;
};
