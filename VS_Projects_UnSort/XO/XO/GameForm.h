#pragma once


// GameForm dialog

class GameForm : public CDialog
{
	DECLARE_DYNAMIC(GameForm)

public:
	GameForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~GameForm();

// Dialog Data
	enum { IDD = IDD_FORMVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
