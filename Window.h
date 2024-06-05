//
// Created by Admin on 05.06.2024.
//

#ifndef SHIP_WINDOW_H
#define SHIP_WINDOW_H

#include <windows.h>

class Window {
private:
    const char* title;
    int width;
    int height;
    int x;
    int y;
    HWND hwnd;
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    MSG msg;
public:
    Window(const char* title, int width, int height);
    void createWindow();
    void showWindow();
    void hideWindow();
    void closeWindow();
    void setWindowPosition(int x, int y);
    void setWindowSize(int width, int height);
    void setWindowTitle(const char* title);
};


#endif //SHIP_WINDOW_H
