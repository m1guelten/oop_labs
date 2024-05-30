#include "framework.h"
#include "shape_editor.h"
#include "shape.h"
#include "point_editor.h"
#include "line_editor.h"
#include "rect_editor.h"
#include "ellipse_editor.h"

ShapeEditor* pse = NULL;
ShapeObjectsEditor::ShapeObjectsEditor() {};
ShapeObjectsEditor::~ShapeObjectsEditor() {};

void ShapeObjectsEditor::StartPointEditor() {
	if (pse) delete pse;
	pse = new PointEditor;
};

void ShapeObjectsEditor::StartLineEditor() {
	if (pse) delete pse;
	pse = new LineEditor;
};

void ShapeObjectsEditor::StartRectEditor() {
	if (pse) delete pse;
	pse = new RectEditor;
};

void ShapeObjectsEditor::StartEllipseEditor() {
	if (pse) delete pse;
	pse = new EllipseEditor;
};

void ShapeObjectsEditor::ClearWindow(HWND hWnd) {
	if (pse) pse->ClearWindow(hWnd);
};

void ShapeObjectsEditor::OnLBdown(HWND hWnd) {
	if (pse) pse->OnLBdown(hWnd);
};

void ShapeObjectsEditor::OnLBup(HWND hWnd) {
	if (pse) pse->OnLBup(hWnd);
}; 

void ShapeObjectsEditor::OnMouseMove(HWND hWnd) {
	if (pse) pse->OnMouseMove(hWnd);
};

void ShapeObjectsEditor::OnPaint(HWND hWnd) {
	if (pse) pse->OnPaint(hWnd);
};

void ShapeObjectsEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (pse) pse->OnInitMenuPopup(hWnd, wParam);
};
