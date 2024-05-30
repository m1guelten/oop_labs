#include "framework.h"
#include "ellipse_editor.h"


void EllipseEditor::OnLBdown(HWND hWnd)
{
	
	isPainting = true;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	UpdatePos();
	CheckNum();
	pcshape[pos] = new EllipseShape;
	pcshape[pos]->SetStart(pt.x, pt.y);
};

void EllipseEditor::OnMouseMove(HWND hWnd)
{
	SetWindowText(hWnd, L"Режим вводу еліпса");
	if (isPainting)
	{
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc = GetDC(hWnd);									//отримуємо контекст вікна для малювання
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_DOT, 1, 0);
		hPenOld = (HPEN)SelectObject(hdc, hPen);

		//Малюються лінії "гумового" сліду попереднього розташування курсору
		Ellipse(hdc, pcshape[pos]->getX1(), pcshape[pos]->getY1(), pcshape[pos]->getX2(), pcshape[pos]->getY2());
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[pos]->SetEnd(pt.x, pt.y);
		//Малюються лінії "гумового" сліду для поточного розташування курсору
		Ellipse(hdc, pcshape[pos]->getX1(), pcshape[pos]->getY1(), pcshape[pos]->getX2(), pcshape[pos]->getY2());
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);									//закриваємо контекст вікна
	}
};

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	
};
