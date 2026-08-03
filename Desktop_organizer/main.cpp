#include <windows.h>

//窗口消息处理函数
//目标窗口，消息类型，附加参数1，附加参数2
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
//进程id，NULL，命令行参数，初始窗口显示状态
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance; 
	wc.lpszClassName = L"DesktopOrganizerWindowClass";
	RegisterClassEx(&wc);
	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		L"DesktopOrganizerWindowClass", // Window class
		L"Desktop Organizer",           // 窗口标题栏显示文字
		WS_OVERLAPPEDWINDOW,            // 风格
		// Size and position			// 尺寸
		100,
		100,
		800,
		600,
		nullptr,
		nullptr,
		hInstance,  // Instance handle
		nullptr        // Additional application data
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);//转化消息
		DispatchMessage(&msg);//分发消息
	}
	return 0;
}
