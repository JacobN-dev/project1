#include "Window.h"
#include <sstream>
Window:: WindowClass Window :: WindowClass::wndClass;
Window::WindowClass::WindowClass() noexcept
	:
	hInst(GetModuleHandle(nullptr)) {

	WNDCLASSEX wc = { 0 }; 
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = HandleMsgSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetInstance();
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = GetName();
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
}

Window::WindowClass:: ~WindowClass()
{
	UnregisterClass(wndClassName, GetInstance());
}

LPCWSTR Window::WindowClass::GetName() noexcept {
	return wndClassName;
}

HINSTANCE Window::WindowClass::GetInstance() noexcept {
	return wndClass.hInst;
}

Window::Window(int width, int height, const char* name) noexcept
{
RECT wr;
wr.left = 100;
wr.right = width + wr.left;
wr.top = 100;
wr.bottom = height + wr.top;
AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);
HWND hWnd;
hWnd = CreateWindow( 
	WindowClass::GetName(),            
	name,                              
	WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 
	CW_USEDEFAULT, CW_USEDEFAULT,      
	wr.right - wr.left,               
	wr.bottom - wr.top,                
	nullptr, nullptr,                  
	WindowClass::GetInstance(),       
	this                               
	);
