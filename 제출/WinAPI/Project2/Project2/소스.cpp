#include<Windows.h>
#include<math.h>
#include<ctime>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪
int g_ix = 500;
int g_iy = 500;
bool g_bShape = true;

#define RADIUS 50

double GetRadian(double degree)
{
	return degree * (3.1415926535 / (double)180);
}

LPCTSTR lpszClass = TEXT("HelloWorld"); //Ŭ���� �� : â�̸�
	int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
		srand((unsigned)time(NULL));
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	//WndClass�� �⺻ ������ȯ���� ����� ����ü��. �ɹ������� �ؿ��� ����.
	WndClass.cbClsExtra = 0; //���࿵��
	WndClass.cbWndExtra = 0; //���࿵�� (�Ű�x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); //����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //Ŀ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //������ ���
	WndClass.hInstance = hInstance; //(���α׷� �ڵ鰪(��ȣ)���)
	WndClass.lpfnWndProc = WndProc; //���μ��� �Լ� ȣ��
	WndClass.lpszClassName = lpszClass; //Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //�������� ������ ������ ���� �� �ٽ� �׸���.
	RegisterClass(&WndClass); //������� WidClass�� ���
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	while (GetMessage(&Message, NULL, 0, 0)) //����ڿ��� �޽����� �޾ƿ��� �Լ�(WM_QUIT �޽��� ���� �� ����), �޽����� ������� ��⸦ �ϰ��ִٰ� ���� �۵�.
	{
		TranslateMessage(&Message); // Ű���� �Է� �޽��� ó���Լ�
		DispatchMessage(&Message); //���� �޽����� WndProc�� �����ϴ� �Լ�
	}
	return (int)Message.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect = {0, 0, 1000, 1000};

	switch (iMessage)
	{
	case WM_DESTROY: // �����찡 �ı��Ǿ��ٴ� �޼���
		PostQuitMessage(0); //GetMessage�Լ��� WM_QUIT �޽����� ������.
		return 0; //WndProc�� Switch�� break ��� return 0; �� ����.
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			g_ix -= 1;
			break;
		case VK_RIGHT:
			g_ix += 1;
			break;
		case VK_UP:
			g_iy -= 1;
			break;
		case VK_DOWN:
			g_iy += 1;
			break;
		}
		InvalidateRect(hWnd, &rect, TRUE);
		return 0;
	case WM_LBUTTONDOWN:
		if (MessageBox(hWnd, TEXT("���� ����"), TEXT("����"), MB_OKCANCEL) == IDOK)
			g_bShape = !g_bShape;
		return 0;
	case WM_MOUSEMOVE:
		g_ix = LOWORD(lParam);
		g_iy = HIWORD(lParam);
		InvalidateRect(hWnd, &rect, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		if (g_ix + RADIUS > 1000)
			g_ix = 1000 - RADIUS;
		else if (g_ix - RADIUS < 0)
			g_ix = RADIUS;

		if (g_iy + RADIUS > 1000)
			g_iy = 1000 - RADIUS;
		else if (g_iy - RADIUS < 0)
			g_iy = RADIUS;

		if (g_bShape)
			Ellipse(hdc, g_ix - RADIUS, g_iy + RADIUS, g_ix + RADIUS, g_iy - RADIUS);
		else
			Rectangle(hdc, g_ix - RADIUS, g_iy + RADIUS, g_ix + RADIUS, g_iy - RADIUS);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam)); // case�� �ִ� �޽����� ������ ������ �޽����� ó���Ѵ�.
}