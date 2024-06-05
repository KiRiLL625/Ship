//
// Created by Admin on 05.06.2024.
//

#ifndef SHIP_DRAWER_H
#define SHIP_DRAWER_H

#include <windows.h>

class Drawer {
private:
    HWND hwnd;
public:
    Drawer(HWND hwnd);
    void drawRectangle(int x, int y, int width, int height, COLORREF color);
    void drawLine(int x1, int y1, int x2, int y2, COLORREF color, int thickness);
    void drawText(int x, int y, const char* text, COLORREF color, int fontSize = 30);
    void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, COLORREF color);
};


#endif //SHIP_DRAWER_H
