#include<Windows.h>
#include<tchar.h>
#include<string>

#define ID_ComboBox 1001
#define ID_Button 1002
#define ID_Edit_Get 1003
#define ID_Edit_Res 1004

static TCHAR WindowsClass[] = L"win32app";
static TCHAR Title[] = L"MyApp";
HINSTANCE hinst;
RECT desktop, cr;
LRESULT cur_sel, count;

HWND combo, button, editGet, editRes;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hinstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hinstance;
	wcex.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	/*wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);*/
	wcex.hbrBackground = CreateSolidBrush(RGB(10, 128, 256));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WindowsClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, L"Call faild!", L"MyApp", NULL);
		return 1;
	}

	hinst = hinstance;
	GetWindowRect(GetDesktopWindow(), &desktop);
	HWND hWnd = CreateWindow(
		WindowsClass,
		Title,
		WS_OVERLAPPEDWINDOW,
		desktop.right / 4,
		desktop.bottom / 6,
		960,
		540,
		NULL,
		NULL,
		hinst,
		NULL);

	if (!hWnd)
	{
		MessageBox(NULL, L"Create window faild!", L"MyApp", NULL);
		return 1;
	}

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return(int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{

	case WM_COMMAND:

		

	case BN_CLICKED:

		

		break;

	case WM_CREATE:

		GetClientRect(hWnd, &cr);

		combo = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"combobox",
			L"",
			WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
			cr.right / 8,
			cr.bottom / 2,
			cr.right / 4,
			cr.bottom / 1.5,
			hWnd,
			(HMENU)ID_ComboBox,
			hinst,
			NULL);

		SendMessage(combo, WM_SETTEXT, 0, (LPARAM)L"Выберите професию");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"HTML-верстальщик");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Web-интегратор");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Web-дизайнер");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Web-программист");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Администратор базы данных");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Администратор сайта");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Блогер");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Диктор");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Кодер");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Контент-менеджер");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Копирайтер");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Оператор ПК");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Программист");
		SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)L"Системный администратор");

		button = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"button",
			L"Конкатенация",
			WS_CHILD | WS_VISIBLE,
			cr.right / 6,
			cr.bottom / 8,
			150,
			30,
			hWnd,
			(HMENU)ID_Button,
			hinst, NULL);

		editGet = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"edit",
			L"Введите фамилию",
			WS_CHILD | WS_VISIBLE | ES_CENTER,
			cr.right / 8,
			cr.bottom / 3,
			cr.right / 4,
			25,
			hWnd,
			(HMENU)ID_Edit_Get,
			hinst,
			NULL);

		editRes = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"edit",
			L"",
			WS_CHILD | WS_VISIBLE,
			cr.right / 8 * 3.5,
			cr.bottom / 8,
			cr.right / 2,
			cr.bottom / 1.5,
			hWnd,
			(HMENU)ID_Edit_Res,
			hinst,
			NULL);

		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}