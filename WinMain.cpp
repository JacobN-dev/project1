#include "Winhexcepts.h"
#include <string>
#include <sstream>
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_CLOSE:
            PostQuitMessage(69);
            break;
        case WM_KEYDOWN:
            if (wParam == 'F')
            {
                SetWindowText(hWnd, "Soft happy window");
            }
            break;
        case WM_KEYUP:
            if (wParam == 'F') {
                SetWindowText(hWnd, "Flacid sad window");
            }
            break;
        case WM_CHAR: {
            static std::string title;
            title.push_back((char)wParam);
            SetWindowText(hWnd, title.c_str());
        }
        break;
        case WM_LBUTTONDOWN: {
            POINTS pt = MAKEPOINTS(lParam);
            std::ostringstream oss;
            oss << "(" << pt.x << "," << pt.y << ")";
            SetWindowText(hWnd,oss.str().c_str());
        }

    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow
) {
    const auto pClassName = "hw3dbutts";

    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx(
        0, pClassName,
        "Happy Hard Window",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        200, 200, 500, 500,
        nullptr, nullptr, hInstance, nullptr
    );
    ShowWindow(hWnd, SW_SHOW);
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }
    if (gResult == -1) {
        return -1;
    }
    else {
        return msg.wParam;
    }
}