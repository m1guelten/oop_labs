#include "framework.h"
#include "editor.h"

Shape * pcshape[MY_SHAPE_ARRAY_SIZE];

Editor::~Editor() {};
ShapeEditor::ShapeEditor() {};
ShapeEditor::~ShapeEditor() {};

void ShapeEditor::IncPos(void) { pos++; }

void ShapeEditor::CheckNum(void)				//���������� ��� ��� pos �� ������������ ������ ������
{ 
	if (pos == MY_SHAPE_ARRAY_SIZE) pos--;
}

void ShapeEditor::UpdatePos(void)				//��������� pos ��� ������� ��'���� 
{ 
	for (int i = 0; i <= MY_SHAPE_ARRAY_SIZE; i++) 
	{
		if (!pcshape[i]) 
		{
			pos = i;
			return;
		}
	}
}

void ShapeEditor::OnLBup(HWND hWnd) 
{
	isPainting = false;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[pos]->SetEnd(pt.x, pt.y);
	IncPos();
	InvalidateRect(hWnd, NULL, TRUE);
};

void ShapeEditor::OnPaint(HWND hWnd) 
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < pos; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}

void ShapeEditor::ClearWindow(HWND hWnd)	//�������� ���� -> �������� ����� 
{ 
	for (int i = 0; i < pos; i++) pcshape[i] = NULL;
	InvalidateRect(hWnd, NULL, TRUE);
}