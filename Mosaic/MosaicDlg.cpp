// MosaicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mosaic.h"
#include "MosaicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMosaicDlg dialog

CMosaicDlg::CMosaicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMosaicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMosaicDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMosaicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMosaicDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMosaicDlg, CDialog)
	//{{AFX_MSG_MAP(CMosaicDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RES, OnRes)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMosaicDlg message handlers

BOOL CMosaicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
	HINSTANCE hInst=LoadLibrary("User32.DLL");
	if(hInst){
		typedef BOOL (WINAPI* MYFUNC)(HWND,COLORREF,BYTE,DWORD);
		MYFUNC fun=NULL;
		fun=(MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");
		if(fun)
			fun(this->GetSafeHwnd(),0,128,2);
		FreeLibrary(hInst);
	}
	::SetWindowPos(AfxGetMainWnd()->m_hWnd,HWND_TOPMOST,-1,-1,-1,-1,SWP_NOMOVE|SWP_NOSIZE);

	InitMosaic();
	SetTimer(0,100,NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMosaicDlg::InitMosaic()
{
	int rn;
	
	MosaicInfo.matrix[0][1]=0;
	MosaicInfo.matrix[0][2]=0;
	MosaicInfo.matrix[1][0]=0;
	MosaicInfo.matrix[1][1]=0;
	MosaicInfo.matrix[1][2]=0;
	MosaicInfo.matrix[2][0]=0;
	MosaicInfo.matrix[2][1]=0;
	MosaicInfo.matrix[2][2]=0;
	do{
		rn=rand();
	}while(rn<1 || rn>8);
	MosaicInfo.matrix[0][0]=rn;

	srand(time(NULL));
	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0]);
	MosaicInfo.matrix[0][1]=rn;

	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0] || rn==MosaicInfo.matrix[0][1]);
	MosaicInfo.matrix[0][2]=rn;

	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0] || rn==MosaicInfo.matrix[0][1] || rn==MosaicInfo.matrix[0][2]);
	MosaicInfo.matrix[1][0]=rn;

	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0] || rn==MosaicInfo.matrix[0][1] || rn==MosaicInfo.matrix[0][2] || rn==MosaicInfo.matrix[1][0]);
	MosaicInfo.matrix[1][1]=rn;

	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0] || rn==MosaicInfo.matrix[0][1] || rn==MosaicInfo.matrix[0][2] || rn==MosaicInfo.matrix[1][0] || rn==MosaicInfo.matrix[1][1]);
	MosaicInfo.matrix[1][2]=rn;

	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0] || rn==MosaicInfo.matrix[0][1] || rn==MosaicInfo.matrix[0][2] || rn==MosaicInfo.matrix[1][0] || rn==MosaicInfo.matrix[1][1] || rn==MosaicInfo.matrix[1][2]);
	MosaicInfo.matrix[2][0]=rn;

	do{
		do{
			rn=rand();
		}while(rn<1 || rn>8);
	}while(rn==MosaicInfo.matrix[0][0] || rn==MosaicInfo.matrix[0][1] || rn==MosaicInfo.matrix[0][2] || rn==MosaicInfo.matrix[1][0] || rn==MosaicInfo.matrix[1][1] || rn==MosaicInfo.matrix[1][2] || rn==MosaicInfo.matrix[2][0]);
	MosaicInfo.matrix[2][1]=rn;

	MosaicInfo.matrix[2][2]=0;

	MosaicInfo.step=0;
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMosaicDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMosaicDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMosaicDlg::OnAbout() 
{
	CAboutDlg  dlg;
	dlg.DoModal();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
	HINSTANCE hInst=LoadLibrary("User32.DLL");
	if(hInst){
		typedef BOOL (WINAPI* MYFUNC)(HWND,COLORREF,BYTE,DWORD);
		MYFUNC fun=NULL;
		fun=(MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");
		if(fun)
			fun(this->GetSafeHwnd(),0,128,2);
		FreeLibrary(hInst);
	}
	SetDlgItemText(IDC_CONT,"Mosaic V0.1\r\n程序: 张皖龙\r\nEmail: zhangwanlong@126.com");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMosaicDlg::OnTimer(UINT nIDEvent) 
{
	char temp[10];
	itoa(MosaicInfo.matrix[0][0],temp,10);
	SetDlgItemText(IDC_BUTTON1,temp);
	itoa(MosaicInfo.matrix[0][1],temp,10);
	SetDlgItemText(IDC_BUTTON2,temp);
	itoa(MosaicInfo.matrix[0][2],temp,10);
	SetDlgItemText(IDC_BUTTON3,temp);
	itoa(MosaicInfo.matrix[1][0],temp,10);
	SetDlgItemText(IDC_BUTTON4,temp);
	itoa(MosaicInfo.matrix[1][1],temp,10);
	SetDlgItemText(IDC_BUTTON5,temp);
	itoa(MosaicInfo.matrix[1][2],temp,10);
	SetDlgItemText(IDC_BUTTON6,temp);
	itoa(MosaicInfo.matrix[2][0],temp,10);
	SetDlgItemText(IDC_BUTTON7,temp);
	itoa(MosaicInfo.matrix[2][1],temp,10);
	SetDlgItemText(IDC_BUTTON8,temp);
	itoa(MosaicInfo.matrix[2][2],temp,10);
	SetDlgItemText(IDC_BUTTON9,temp);
	int i,j;
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			int id;
			switch(i){
			case 0:
				id=1000+j;
				break;
			case 1:
				id=1000+3+j;
				break;
			case 2:
				id=1000+6+j;
				break;
			}
			CButton* pb=(CButton *)GetDlgItem(id);
			pb->EnableWindow(TRUE);
			if(MosaicInfo.matrix[i][j]==0){
				SetDlgItemText(id,"");
				pb->EnableWindow(FALSE);
			}
		}
	}
	if(MosaicInfo.matrix[0][0]==1 && MosaicInfo.matrix[0][1]==2 && MosaicInfo.matrix[0][2]==3 && MosaicInfo.matrix[1][0]==4 && MosaicInfo.matrix[1][1]==5 && MosaicInfo.matrix[1][2]==6 && MosaicInfo.matrix[2][0]==7 && MosaicInfo.matrix[2][1]==8){
		int step=MosaicInfo.step;
		InitMosaic();
		CString cs;
		cs.Format("恭喜你!\r\n所用步数: %d",step);
		MessageBox(cs);
	}
	itoa(MosaicInfo.step,temp,10);
	SetDlgItemText(IDC_STEP,temp);
	
	CDialog::OnTimer(nIDEvent);
}

void CMosaicDlg::OnRes() 
{
	InitMosaic();
}

void CMosaicDlg::OnButton1() 
{
	if(MosaicInfo.matrix[0][1]==0){
		MosaicInfo.matrix[0][1]=MosaicInfo.matrix[0][0];
		MosaicInfo.matrix[0][0]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][0]==0){
		MosaicInfo.matrix[1][0]=MosaicInfo.matrix[0][0];
		MosaicInfo.matrix[0][0]=0;
		MosaicInfo.step++;
		return;
	}
}

void CMosaicDlg::OnButton2() 
{
	if(MosaicInfo.matrix[0][0]==0){
		MosaicInfo.matrix[0][0]=MosaicInfo.matrix[0][1];
		MosaicInfo.matrix[0][1]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[0][2]==0){
		MosaicInfo.matrix[0][2]=MosaicInfo.matrix[0][1];
		MosaicInfo.matrix[0][1]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][1]==0){
		MosaicInfo.matrix[1][1]=MosaicInfo.matrix[0][1];
		MosaicInfo.matrix[0][1]=0;
		MosaicInfo.step++;
		return;
	}
}

void CMosaicDlg::OnButton3() 
{
	if(MosaicInfo.matrix[0][1]==0){
		MosaicInfo.matrix[0][1]=MosaicInfo.matrix[0][2];
		MosaicInfo.matrix[0][2]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][2]==0){
		MosaicInfo.matrix[1][2]=MosaicInfo.matrix[0][2];
		MosaicInfo.matrix[0][2]=0;
		MosaicInfo.step++;
		return;
	}
}

void CMosaicDlg::OnButton4() 
{
	if(MosaicInfo.matrix[0][0]==0){
		MosaicInfo.matrix[0][0]=MosaicInfo.matrix[1][0];
		MosaicInfo.matrix[1][0]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[2][0]==0){
		MosaicInfo.matrix[2][0]=MosaicInfo.matrix[1][0];
		MosaicInfo.matrix[1][0]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][1]==0){
		MosaicInfo.matrix[1][1]=MosaicInfo.matrix[1][0];
		MosaicInfo.matrix[1][0]=0;
		MosaicInfo.step++;
		return;
	}	
}

void CMosaicDlg::OnButton5() 
{
	if(MosaicInfo.matrix[0][1]==0){
		MosaicInfo.matrix[0][1]=MosaicInfo.matrix[1][1];
		MosaicInfo.matrix[1][1]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][2]==0){
		MosaicInfo.matrix[1][2]=MosaicInfo.matrix[1][1];
		MosaicInfo.matrix[1][1]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][0]==0){
		MosaicInfo.matrix[1][0]=MosaicInfo.matrix[1][1];
		MosaicInfo.matrix[1][1]=0;
		MosaicInfo.step++;
		return;
	}		
	if(MosaicInfo.matrix[2][1]==0){
		MosaicInfo.matrix[2][1]=MosaicInfo.matrix[1][1];
		MosaicInfo.matrix[1][1]=0;
		MosaicInfo.step++;
		return;
	}
}

void CMosaicDlg::OnButton6() 
{
	if(MosaicInfo.matrix[0][2]==0){
		MosaicInfo.matrix[0][2]=MosaicInfo.matrix[1][2];
		MosaicInfo.matrix[1][2]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[1][1]==0){
		MosaicInfo.matrix[1][1]=MosaicInfo.matrix[1][2];
		MosaicInfo.matrix[1][2]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[2][2]==0){
		MosaicInfo.matrix[2][2]=MosaicInfo.matrix[1][2];
		MosaicInfo.matrix[1][2]=0;
		MosaicInfo.step++;
		return;
	}		
}

void CMosaicDlg::OnButton7() 
{
	if(MosaicInfo.matrix[1][0]==0){
		MosaicInfo.matrix[1][0]=MosaicInfo.matrix[2][0];
		MosaicInfo.matrix[2][0]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[2][1]==0){
		MosaicInfo.matrix[2][1]=MosaicInfo.matrix[2][0];
		MosaicInfo.matrix[2][0]=0;
		MosaicInfo.step++;
		return;
	}
}

void CMosaicDlg::OnButton8() 
{
	if(MosaicInfo.matrix[1][1]==0){
		MosaicInfo.matrix[1][1]=MosaicInfo.matrix[2][1];
		MosaicInfo.matrix[2][1]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[2][0]==0){
		MosaicInfo.matrix[2][0]=MosaicInfo.matrix[2][1];
		MosaicInfo.matrix[2][1]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[2][2]==0){
		MosaicInfo.matrix[2][2]=MosaicInfo.matrix[2][1];
		MosaicInfo.matrix[2][1]=0;
		MosaicInfo.step++;
		return;
	}		
}

void CMosaicDlg::OnButton9() 
{
	if(MosaicInfo.matrix[1][2]==0){
		MosaicInfo.matrix[1][2]=MosaicInfo.matrix[2][2];
		MosaicInfo.matrix[2][2]=0;
		MosaicInfo.step++;
		return;
	}
	if(MosaicInfo.matrix[2][1]==0){
		MosaicInfo.matrix[2][1]=MosaicInfo.matrix[2][2];
		MosaicInfo.matrix[2][2]=0;
		MosaicInfo.step++;
		return;
	}
}
