// Mosaic.h : main header file for the MOSAIC application
//

#if !defined(AFX_MOSAIC_H__F4D9B762_C122_4517_8D0A_9EACB8448333__INCLUDED_)
#define AFX_MOSAIC_H__F4D9B762_C122_4517_8D0A_9EACB8448333__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMosaicApp:
// See Mosaic.cpp for the implementation of this class
//

class CMosaicApp : public CWinApp
{
public:
	CMosaicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMosaicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMosaicApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOSAIC_H__F4D9B762_C122_4517_8D0A_9EACB8448333__INCLUDED_)
