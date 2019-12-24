#pragma once

#include <atldlgs.h>
#include <atlctrls.h>
#include <atlstr.h>

#include "resource.h"
#include "CKamacOptions.h"
#include "CKMData.h"

class CPPMain :	public CPropertyPage<IDD_CPPMain>
{
public:
	CPPMain(CKamacOptions& ko);
	virtual ~CPPMain();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

public:
	virtual BOOL OnInitDialog();
	void UpdateInfo(void);
	void UpdateMousePos(void);
	void UpdateMouseLeftClick(ULONG32 ulLCSession, ULONG32 ulLCToday, ULONG32 ulLCTotal);
	void UpdateMouseRightClick(ULONG32 ulLCSession, ULONG32 ulLCToday, ULONG32 ulLCTotal);
	void UpdateMouseMiddleClick(ULONG32 ulLCSession, ULONG32 ulLCToday, ULONG32 ulLCTotal);
	void UpdateMouseDistance(ULONG64 ulMDSession, ULONG64 ulMDToday, ULONG64 ulMDTotal);
	void UpdateKeyboard(ULONG32 ulKSSession, ULONG32 ulKSToday, ULONG32 ulKSTotal, USHORT usCode);
	void UpdateAll(const CKMData& kmdSession, const CKMData& kmdToday, const CKMData& kmdTotal);
protected:
	CListViewCtrl lcMain;
	CString strInfo, strScreenSize, strResolution, strKeyboard, strMouse;
	//CStatic statInfo;
	CNFStatic statInfo;
	CKamacOptions& koOptions;
};

