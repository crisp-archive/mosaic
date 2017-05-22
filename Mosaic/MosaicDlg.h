// MosaicDlg.h : header file
//

#if !defined(AFX_MOSAICDLG_H__2C6AB9AC_9461_4656_83BD_9E83592D96FB__INCLUDED_)
#define AFX_MOSAICDLG_H__2C6AB9AC_9461_4656_83BD_9E83592D96FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMosaicDlg dialog

typedef struct tagMOSAICINFO
{
	int matrix[3][3];
	int step;
} MOSAICINFO;
class CMosaicDlg : public CDialog
{
// Construction
public:
	CMosaicDlg(CWnd* pParent = NULL);	// standard constructor

	MOSAICINFO MosaicInfo;
	void InitMosaic();
// Dialog Data
	//{{AFX_DATA(CMosaicDlg)
	enum { IDD = IDD_MOSAIC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMosaicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMosaicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRes();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOSAICDLG_H__2C6AB9AC_9461_4656_83BD_9E83592D96FB__INCLUDED_)
