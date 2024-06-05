#include "Window.h"
#include "Drawer.h"

#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)
#define DARK_GREY RGB(100, 100, 100)
#define GREEN RGB(0, 200, 0)
#define DARK_WHITE RGB(240, 240, 240)
#define BLUE RGB(0, 0, 200)
#define RED RGB(200, 0, 0)
#define ORANGE RGB(255, 165, 0)

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

Window::Window(const char* title, int width, int height):
title(title), width(width), height(height), x(SCREEN_WIDTH / 2 - width / 2), y(SCREEN_HEIGHT / 2 - height / 2), msg({}) {}

void Window::createWindow() {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = Window::WindowProc;
    wc.hInstance = GetModuleHandle(0);
    wc.lpszClassName = "Window";
    RegisterClass(&wc);
    hwnd = CreateWindow("Window", title, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, x, y, width, height, 0, 0, GetModuleHandle(0), this);
    ShowWindow(hwnd, SW_SHOW);
}

void Window::showWindow() {
    ShowWindow(hwnd, SW_SHOW);
    Drawer drawer(hwnd);
    while(GetMessage(&msg, 0, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if(msg.message == WM_QUIT) break;
        //корпус
        drawer.drawRectangle(width / 2 - 300 / 2, height / 2 - 80 / 2,
                             300, 80, DARK_GREY);
        //левый треугольник
        drawer.drawTriangle(width / 2 - 300 / 2, height / 2 + 80 / 2,
                            width / 2 - 300 / 2, height / 2 - 80 / 2,
                            width / 2 - 300 / 2 - 80, height / 2 - 80 / 2,
                            DARK_GREY);
        //правый треугольник
        drawer.drawTriangle(width / 2 + 300 / 2, height / 2 + 80 / 2,
                            width / 2 + 300 / 2, height / 2 - 80 / 2,
                            width / 2 + 300 / 2 + 80, height / 2 - 80 / 2,
                            DARK_GREY);
        //мачта
        drawer.drawRectangle(width / 2, height / 2 - 80 / 2 - 150,
                             10, 150, GREEN);

        //флаг
        int flagWidth = 60;
        int flagHeight = 30;
        int flagX = width / 2;
        int flagY = height / 2 - 80 / 2 - 150;
        drawer.drawRectangle(flagX, flagY, flagWidth, flagHeight / 3, DARK_WHITE); // Белая полоса
        drawer.drawRectangle(flagX, flagY + flagHeight / 3, flagWidth, flagHeight / 3, BLUE); // Синяя полоса
        drawer.drawRectangle(flagX, flagY + 2 * flagHeight / 3, flagWidth, flagHeight / 3, RED); // Красная полоса

        //пушки
        int cannonWidth = 40;
        int cannonHeight = 20;
        int cannonY = height / 2 - 80 / 2 - cannonHeight;
        drawer.drawRectangle(width / 2 - 300 / 2, cannonY, cannonWidth, cannonHeight, DARK_GREY); // Пушка слева
        drawer.drawRectangle(width / 2 + 300 / 2 - cannonWidth, cannonY, cannonWidth, cannonHeight, DARK_GREY); // Пушка справа

        //дула
        drawer.drawLine(width / 2 - 300 / 2, cannonY, width / 2 - 300 / 2 - 20, cannonY - 20, DARK_GREY, 10); // Дуло пушки слева
        drawer.drawLine(width / 2 + 300 / 2, cannonY, width / 2 + 300 / 2 + cannonWidth - 20, cannonY - 20, DARK_GREY, 10); // Дуло пушки справа

        //текст
        drawer.drawText(width / 2 - 300 / 2, height / 2 - 80 / 2 + 30, "Z", ORANGE); // Буква Z слева
        drawer.drawText(width / 2, height / 2 - 80 / 2 + 30, "O", ORANGE); // Буква O посередине
        drawer.drawText(width / 2 + 300 / 2 - 10, height / 2 - 80 / 2 + 30, "V", ORANGE); // Буква V справа
    }
}

void Window::hideWindow() {
    ShowWindow(hwnd, SW_HIDE);
}

void Window::closeWindow() {
    DestroyWindow(hwnd);
}

void Window::setWindowPosition(int x, int y) {
    SetWindowPos(hwnd, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void Window::setWindowSize(int width, int height) {
    SetWindowPos(hwnd, 0, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);
}

void Window::setWindowTitle(const char* title) {
    SetWindowText(hwnd, title);
}