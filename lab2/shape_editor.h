#pragma once

class ShapeObjectsEditor
	{
	public:
		ShapeObjectsEditor(void);
		~ShapeObjectsEditor();
		void StartPointEditor();
		void StartLineEditor();
		void StartRectEditor();
		void StartEllipseEditor();
		void ClearWindow(HWND);
		void OnLBdown(HWND);
		void OnLBup(HWND);
		void OnMouseMove(HWND);
		void OnPaint(HWND);
		void OnInitMenuPopup(HWND, WPARAM);
	};

