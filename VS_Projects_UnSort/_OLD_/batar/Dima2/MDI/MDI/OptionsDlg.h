#pragma once


// ���������� ���� COptionsDlg

class COptionsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COptionsDlg)

public:
	COptionsDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~COptionsDlg();

// ������ ����������� ����
	enum { IDD = IDD_OPTIONS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_string;
	int m_radio1;
	afx_msg void OnBnClickedRadio();
	afx_msg void OnBnClickedOk();
	int m_colour;
	BOOL m_hcentre;
//	BOOL m_vcenter;
	BOOL m_vcentre;
};
