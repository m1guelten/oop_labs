#include "framework.h"
#include "function.h"

WCHAR FlagMenuPopup, FlagMenuPopupOld;


void FuncInitMenuPopup(HWND hWnd, WPARAM wParam, WCHAR selectId)
{
	FlagMenuPopup = selectId;
	HMENU hMenu, hSubMenu;
	hMenu = GetMenu(hWnd);
	hSubMenu = GetSubMenu(hMenu, 1);							//POPUP-меню ќб'Їкти
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, FlagMenuPopupOld, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, FlagMenuPopup, MF_CHECKED);
	}
	FlagMenuPopupOld = FlagMenuPopup;
};
