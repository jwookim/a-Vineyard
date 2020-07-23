#include<Windows.h>
#include<math.h>
#include<ctime>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//글로벌 인스턴스핸들값

double GetRadian(double degree)
{
	return degree * (3.1415926535 / (double)180);
}

LPCTSTR lpszClass = TEXT("HelloWorld"); //클래스 명 : 창이름
	int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
		srand((unsigned)time(NULL));
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	//WndClass는 기본 윈도우환경을 만드는 구조체다. 맴버변수는 밑에와 같다.
	WndClass.cbClsExtra = 0; //예약영역
	WndClass.cbWndExtra = 0; //예약영역 (신경x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //아이콘 모양
	WndClass.hInstance = hInstance; //(프로그램 핸들값(번호)등록)
	WndClass.lpfnWndProc = WndProc; //프로세스 함수 호출
	WndClass.lpszClassName = lpszClass; //클레스 이름
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //윈도우의 수직과 수평이 변경 시 다시 그린다.
	RegisterClass(&WndClass); //만들어진 WidClass를 등록
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	while (GetMessage(&Message, NULL, 0, 0)) //사용자에게 메시지를 받아오는 함수(WM_QUIT 메시지 받을 시 종료), 메시지가 오기까지 대기를 하고있다가 오면 작동.
	{
		TranslateMessage(&Message); // 키보드 입력 메시지 처리함수
		DispatchMessage(&Message); //받은 메시지를 WndProc에 전달하는 함수
	}
	return (int)Message.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (iMessage)
	{
	case WM_DESTROY: // 윈도우가 파괴되었다는 메세지
		PostQuitMessage(0); //GetMessage함수에 WM_QUIT 메시지를 보낸다.
		return 0; //WndProc의 Switch는 break 대신 return 0; 를 쓴다.
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, 100, 100, TEXT("^오^"), 4);
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
	return(DefWindowProc(hWnd, iMessage, wParam, lParam)); // case에 있는 메시지를 제외한 나머지 메시지를 처리한다.
}