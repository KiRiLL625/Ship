//
// Created by Admin on 05.06.2024.
//

#include "Drawer.h"

Drawer::Drawer(HWND hwnd): hwnd(hwnd) {}

void Drawer::drawRectangle(int x, int y, int width, int height, COLORREF color) {
    HDC hdc = GetDC(hwnd);
    HBRUSH brush = CreateSolidBrush(color);
    RECT rect;
    rect.left = x;
    rect.top = y;
    rect.right = x + width;
    rect.bottom = y + height;
    FillRect(hdc, &rect, brush);
    DeleteObject(brush);
    ReleaseDC(hwnd, hdc);
}

void Drawer::drawLine(int x1, int y1, int x2, int y2, COLORREF color, int thickness) {
    HDC hdc = GetDC(hwnd);
    HPEN pen = CreatePen(PS_SOLID, thickness, color);
    SelectObject(hdc, pen);
    MoveToEx(hdc, x1, y1, 0);
    LineTo(hdc, x2, y2);
    DeleteObject(pen);
    ReleaseDC(hwnd, hdc);
}

void Drawer::drawText(int x, int y, const char* text, COLORREF color, int fontSize) {
    HDC hdc = GetDC(hwnd);
    HFONT font = CreateFont(fontSize, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
    SelectObject(hdc, font);
    SetTextColor(hdc, color);
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, x, y, text, strlen(text));
    DeleteObject(font);
    ReleaseDC(hwnd, hdc);
}

void Drawer::drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, COLORREF color) {
    HDC hdc = GetDC(hwnd);
    HBRUSH brush = CreateSolidBrush(color);
    HPEN pen = CreatePen(PS_NULL, 1, RGB(0, 0, 0));
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);
    POINT points[3] = {{x1, y1}, {x2, y2}, {x3, y3}};
    Polygon(hdc, points, 3);
    DeleteObject(brush);
    DeleteObject(pen);
    ReleaseDC(hwnd, hdc);
}