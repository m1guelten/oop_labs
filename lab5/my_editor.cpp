#include "framework.h"
#include "my_editor.h"
#include "my_table.h"


MyTable* my_tab=MyTable::getInstanse();

int MyEditor::nCurrentIndex = 0;
Shape** MyEditor::pcshape = new Shape * [shape_size] {};

MyEditor::~MyEditor()
{
	delete[]pcshape;
}

void MyEditor::Start(Shape* shape)
{
	currShape = shape;
}


void MyEditor::OnLBdown(HWND hWnd)
{
	if (!currShape) return;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[nCurrentIndex] = currShape->copyShape();
	xstart = xend = pt.x;
	ystart = yend = pt.y;
	pcshape[nCurrentIndex]->Set(xstart, ystart, xend, yend);
}

void MyEditor::OnLBup(HWND hWnd,std::string objName)
{
	
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	pcshape[nCurrentIndex]->Set(xstart, ystart, xend, yend);
	
	
	my_tab->Add(objName, xstart, ystart, xend, yend);

	nCurrentIndex = (++nCurrentIndex) % shape_size;
	InvalidateRect(hWnd, NULL, TRUE);
	xstart = 0;
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (!xstart) return;
	pcshape[nCurrentIndex]->DrawRubberBand(hWnd);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	pcshape[nCurrentIndex]->Set(xstart, ystart, xend, yend);
	pcshape[nCurrentIndex]->DrawRubberBand(hWnd);
}

void MyEditor::OnPaint(HWND hWnd,int selectedItem)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < shape_size; i++)
		if (pcshape[i])
		{
			bool isSelected = selectedItem == i ? true : false;
			pcshape[i]->Show(hdc, isSelected);
		}
	EndPaint(hWnd, &ps);
}


std::string MyEditor::getObjName()
{
	return wsName;
}

void MyEditor::setObjName(std::string objName)
{
	wsName = objName;
};

void MyEditor::RemoveItem(int selectedItem)
{
	if (selectedItem >= 0)
	{
		for (int i = 0; i < shape_size; i++)
			if (i >= selectedItem)
			{
				Shape* next = pcshape[i + 1];
				if (next)
					pcshape[i] = next;
				else
				{
					pcshape[i] = NULL;
					break;
				}
			}
	}
}