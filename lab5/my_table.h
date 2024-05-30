#pragma once
#include <string>
#include "framework.h"

#include <fstream>
#include <string>
#include <codecvt>



class MyTable
{
private:
	static MyTable* p_instance;
	MyTable() {};
	MyTable(const MyTable&);
	MyTable& operator=(MyTable&);

	/*MyTable() {};
	MyTable(const MyTable&);
	MyTable& operator=(MyTable&);
	*/
	static HWND hWndTable;
	static HWND hWndParent;

	static LPCSTR path;
	static int selectedItem;
	static int toRemove;

public:
	static MyTable* getInstanse();

	void Add(std::string objN, int x1, int y1, int x2,int y2);
	void Create(HWND,HINSTANCE);
	void Show();

	static HWND getTable();
	static HWND getParent();

	static void setSelected(int);
	static int getSelected();

	static void setRemove(int);
	static int getRemove();

	static void Remove(int);
};