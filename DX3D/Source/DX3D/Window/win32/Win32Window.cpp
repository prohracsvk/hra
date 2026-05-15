#include "DX3D/Window/Window.h"
#include <Windows.h>
#include <stdexcept>
LRESULT CALLBACK WindowClose(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) 
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	default:

		 return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}

dx3d::Window::Window(const WindowDesc& desc) : Base(desc.Base), m_size(desc.size)
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"3D hra pokus";
			wc.lpfnWndProc = WindowClose;
			return RegisterClassEx(&wc);
		};
    static const auto windowClassId = std::invoke(registerWindowClassFunction);

	if (!windowClassId)
		DX3DLogThrowError(" failed RegisterClassEx");
		

	RECT rc{ 0,0,m_size.width,m_size.height };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"fetacka hra",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	 if (!m_handle)
	 DX3DLogThrowError(" failed CreateWindowEx");

	 ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
}




dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
