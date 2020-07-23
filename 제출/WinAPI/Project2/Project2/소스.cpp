#include<Windows.h>
#include<math.h>
#include<ctime>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪

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
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //����
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
	switch (iMessage)
	{
	case WM_DESTROY: // �����찡 �ı��Ǿ��ٴ� �޼���
		PostQuitMessage(0); //GetMessage�Լ��� WM_QUIT �޽����� ������.
		return 0; //WndProc�� Switch�� break ��� return 0; �� ����.
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, 100, 100, TEXT("^��^"), 4);
		ReleaseDC(hWnd, hdc);
		hdc = BeginPaint(hWnd, &ps);
		for (int y = 0; y <= 100; y += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, 255, rand() % 266));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, rand() % 266, 255));
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, 255, 255));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int x = 0; x <= 100; x += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(255, 255, rand() % 266));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(255, rand() % 266, 255));
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, 255, 255));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int y = 0; y <= 100; y += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(0, 0, rand() % 266));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(0, rand() % 266, 0));
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, 0, 0));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int x = 0; x <= 100; x += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, 0, rand() % 266));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, rand() % 266, 0));
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, 0, 0));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int y = 0; y <= 100; y += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, 255, rand() % 266));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, rand() % 266, 255));
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, 255, 255));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int x = 0; x <= 100; x += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, 0, rand() % 266));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, rand() % 266, 0));
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, 0, 0));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		EndPaint(hWnd, &ps);
		return 0;
	case WM_PAINT:
		/*hdc = BeginPaint(hWnd, &ps);
		for (int y = 0; y <= 100; y += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, 255, rand() % 266));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, rand() % 266, 255));
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, 255, 255));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int x = 0; x <= 100; x += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(255, 255, rand() % 266));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(255, rand() % 266, 255));
				SetPixel(hdc, 750 + cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, 255, 255));
				SetPixel(hdc, 750 - cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int y = 0; y <= 100; y += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(0, 0, rand() % 266));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(0, rand() % 266, 0));
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, 0, 0));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int x = 0; x <= 100; x += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, 0, rand() % 266));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, rand() % 266, 0));
				SetPixel(hdc, 500 + cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, 0, 0));
				SetPixel(hdc, 500 - cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int y = 0; y <= 100; y += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, 255, rand() % 266));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * 100, 500 + sin(GetRadian(i / 100)) * y, RGB(255, rand() % 266, 255));
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, 255, 255));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * 100, 500 - sin(GetRadian(i / 100)) * y, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		for (int x = 0; x <= 100; x += 10)
		{
			for (int i = 0; i < 9000; i++)
			{
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, 0, rand() % 266));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * x, 500 + sin(GetRadian(i / 100)) * 100, RGB(0, rand() % 266, 0));
				SetPixel(hdc, 250 + cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, 0, 0));
				SetPixel(hdc, 250 - cos(GetRadian(i / 100)) * x, 500 - sin(GetRadian(i / 100)) * 100, RGB(rand() % 266, rand() % 266, rand() % 266));
			}
		}
		EndPaint(hWnd, &ps);*/
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam)); // case�� �ִ� �޽����� ������ ������ �޽����� ó���Ѵ�.
}