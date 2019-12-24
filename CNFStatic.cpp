#include "stdafx.h"
#include "CNFStatic.h"


CNFStatic::CNFStatic()
{

}

CNFStatic::~CNFStatic()
{
}


BEGIN_MESSAGE_MAP(CNFStatic, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CNFStatic ��Ϣ�������


//----------------------------------------------------------------------------------------------------------------------
BOOL CNFStatic::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

//	return CStatic::OnEraseBkgnd(pDC);
	return TRUE;
}


//----------------------------------------------------------------------------------------------------------------------
void CNFStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	if (!dcMem)
		PrepareMemDC(dc, rect.Width(), rect.Height());
	Draw(dcMem, rect, &dc);
}


//----------------------------------------------------------------------------------------------------------------------
void CNFStatic::Draw(CDC& dc, CRect& rect, CDC* pDCTarget)
{
	if (dc)
	{
		CRect rt = rect;
		dc.FillSolidRect(rect, ::GetSysColor(COLOR_INFOBK));
		dc.DrawFocusRect(&rt);
		rt.DeflateRect(2, 2);
		dc.DrawText(strContent, &rt, DT_LEFT | DT_EXPANDTABS);
		if (pDCTarget)
		{
			pDCTarget->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
		}
	}
}


//----------------------------------------------------------------------------------------------------------------------
void CNFStatic::PrepareMemDC(CDC& dc, int nw, int nh)
{
	if (bmp.operator HBITMAP())
		bmp.DeleteObject();
	if (dcMem)
		dcMem.DeleteDC();

	dcMem.CreateCompatibleDC(&dc);
	bmp.CreateCompatibleBitmap(&dc, nw, nh);
	dcMem.SelectObject(bmp);
	dcMem.SelectStockObject(SYSTEM_FONT);
	dcMem.SetTextColor(::GetSysColor(COLOR_INFOTEXT));
}

