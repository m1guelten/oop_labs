#include "my_table.h"
#include <stdio.h>
#include "resource1.h"
#include <string>
#include<iostream>

HWND MyTable::hWndTable = NULL;
HWND MyTable::hWndParent = NULL;

LPCSTR MyTable::path = "myfile.txt";
int MyTable::selectedItem = 0;
int MyTable::toRemove = 0;

INT_PTR CALLBACK Table(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		WORD button = LOWORD(wParam);
		WORD action = HIWORD(wParam);

		if (button == IDCANCEL_TABL || button == IDCANCEL)
		{
			MyTable::setSelected(0);
			InvalidateRect(MyTable::getParent(), NULL, TRUE);

			ShowWindow(MyTable::getTable(), SW_HIDE);
			return (INT_PTR)TRUE;
		}

		if (action == LBN_SELCHANGE)
		{
			int selectedItem = (int)SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);
			MyTable::setSelected(selectedItem);
		}

		if (action == LBN_DBLCLK)
		{
			int selectedItem = (int)SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_GETCURSEL, 0, 0);

			if (selectedItem)
			{
				MyTable::Remove(selectedItem);
				SendMessage(GetDlgItem(hDlg, IDC_LIST1), LB_DELETESTRING, selectedItem, 0);
			}
		}
		InvalidateRect(MyTable::getParent(), NULL, TRUE);
		break;
	}
	return (INT_PTR)FALSE;
}



MyTable* MyTable::p_instance = 0;
MyTable* MyTable::getInstanse()
{
	if (!p_instance)
		p_instance = new MyTable();
	return p_instance;
}

void MyTable::Create(HWND hWnd, HINSTANCE hInst)
{
	FILE* fout;
	fopen_s(&fout, path, "wt");
	if (fout)	
	{
		fprintf(fout, "%s\t%s\t%s\t%s\t%s\n", "Фігура", "x1", "y1", "x2", "y2");
		fclose(fout);
	}

	hWndParent = hWnd;
	hWndTable = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TABL_OBJ), 0, Table);
	ShowWindow(hWndTable, SW_HIDE);	
}

void MyTable::Add(std::string objN, int x1, int y1, int x2, int y2)
{
	FILE* fout = NULL;
	fopen_s(&fout, path, "at");
	if (fout)
	{
		fprintf(fout, "%s\t%d\t%d\t%d\t%d\n", objN.c_str(), x1, y1, x2, y2);
		fclose(fout);
	}
	FILE* fin;
	fopen_s(&fin, path, "rt");
	if (fin)
	{
		SendMessage(GetDlgItem(hWndTable, IDC_LIST1), LB_RESETCONTENT, 0, 0);
		char buf[256];
		while (fgets(buf, 256, fin))
		{
			
			SendMessageA(GetDlgItem(hWndTable, IDC_LIST1), LB_ADDSTRING, 0, (LPARAM)buf);
		}
		fclose(fin);
	}
}


void MyTable::Show()
{
	ShowWindow(hWndTable, SW_SHOW);
}

HWND MyTable::getTable()
{
	return hWndTable;
}

HWND MyTable::getParent()
{
	return hWndParent;
}

void MyTable::setSelected(int number)
{
	selectedItem = number;
}

int MyTable::getSelected()
{
	return selectedItem;
}

void MyTable::setRemove(int number)
{
	toRemove = number;
}

int MyTable::getRemove()
{
	return toRemove;
}


void MyTable::Remove(int selectedItem)
{
	std::ifstream filein;
	filein.open(path);

	std::string line;
	std::string table;

	int i = 0;
	while (getline(filein, line))
	{
		if (i != selectedItem)
		{
			table.insert(table.size(), line);
			table.insert(table.size(), "\n");
		}
		i++;
	}

	filein.close();

	std::ofstream fileout;
	fileout.open(path);
	fileout << table << std::endl;
	fileout.close();

	setRemove(selectedItem);
	setSelected(0);
}

