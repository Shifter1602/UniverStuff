
// integrDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CintegrDlg
class CintegrDlg : public CDialogEx
{
// ��������
public:
	CintegrDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_INTEGR_DIALOG };

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
	double m_a;
	double m_b;
	double m_c;
	double m_d;
	double m_step;
	double m_integr;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
