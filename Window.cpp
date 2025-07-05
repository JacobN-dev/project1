#include "Window.h"
#include <sstream>
// Window Class Stuff
Window:: WindowClass Window :: WindowClass::wndClass;
Window::WindowClass::WindowClass() noexcept
	:
	hInst(GetModuleHandle(nullptr)) {

	WNDCLASSEX WC = { 0 }; 
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = HandleMsgSetup;
	wc.cbclsExtra = 0;
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