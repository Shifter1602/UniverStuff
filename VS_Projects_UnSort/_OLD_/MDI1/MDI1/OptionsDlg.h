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
	afx_msg void OnEnChangeStringEdit();
	CString m_string;
	int m_radio;
	BOOL m_hcenter;
	BOOL m_vcenter;
};
