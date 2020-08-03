#include<Windows.h>
#include<math.h>
#include<string>
#include<ctime>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//글로벌 인스턴스핸들값
SYSTEMTIME st;
RECT rect = { 1, 1, 1000, 1000 };


#define RADIUS 100

double GetRadian(double degree)
{
	return degree * (3.1415926535 / (double)180);
}

enum DIRECT
{
	DIR_NW,
	DIR_NE,
	DIR_SW,
	DIR_SE
};

class Clock
{
private:
	int m_ix;
	int m_iy;
	int m_iRadius;
	int m_iHour;
	int m_iMin;
	int m_iSecond;
	DIRECT m_dir;
public:
	Clock(int x, int y, int rad) : m_ix(x), m_iy(y), m_iRadius(rad)
	{
		m_dir = (DIRECT)(rand() % 4);
	}
	void Move()
	{
		if (m_ix - m_iRadius <= 1 || m_ix + m_iRadius >= 1000)
		{
			switch (m_dir)
			{
			case DIR_NW:
				m_dir = DIR_NE;
				break;
			case DIR_NE:
				m_dir = DIR_NW;
				break;
			case DIR_SW:
				m_dir = DIR_SE;
				break;
			case DIR_SE:
				m_dir = DIR_SW;
				break;
			}
		}

		if (m_iy - m_iRadius <= 1 || m_iy + m_iRadius >= 1000)
		{
			switch (m_dir)
			{
			case DIR_NW:
				m_dir = DIR_SW;
				break;
			case DIR_NE:
				m_dir = DIR_SE;
				break;
			case DIR_SW:
				m_dir = DIR_NW;
				break;
			case DIR_SE:
				m_dir = DIR_NE;
				break;
			}
		}

		switch (m_dir)
		{
		case DIR_NW:
			m_ix--;
			m_iy--;
			break;
		case DIR_NE:
			m_ix++;
			m_iy--;
			break;
		case DIR_SW:
			m_ix--;
			m_iy++;
			break;
		case DIR_SE:
			m_ix++;
			m_iy++;
			break;
		}

		GetLocalTime(&st);

		m_iHour = st.wHour;
		m_iMin = st.wMinute;
		m_iSecond = st.wSecond;

	}
	int GetX()
	{
		return m_ix;
	}
	int GetY()
	{
		return m_iy;
	}
	int GetRad()
	{
		return m_iRadius;
	}
	int GetHour()
	{
		return m_iHour;
	}
	int GetMin()
	{
		return m_iMin;
	}
	int GetSecond()
	{
		return m_iSecond;
	}
};

Clock watch(200, 500, RADIUS);

void CALLBACK Move(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	watch.Move();

	InvalidateRect(hWnd, &rect, TRUE);
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

	HPEN hNewPen;

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 40, Move);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_DESTROY: // 윈도우가 파괴되었다는 메세지
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //GetMessage함수에 WM_QUIT 메시지를 보낸다.
		return 0; //WndProc의 Switch는 break 대신 return 0; 를 쓴다.
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 0, 0, 1001, 1001);
		Ellipse(hdc, watch.GetX() - watch.GetRad(), watch.GetY() + watch.GetRad(), watch.GetX() + watch.GetRad(), watch.GetY() - watch.GetRad());

		for (int i = 1; i <= 12; i++)
		{
			int size = 1;
			if (i >= 10)
				size = 2;

			SetTextAlign(hdc, TA_CENTER);
			TCHAR buff[10];
			wsprintf(buff, TEXT("%d"), i);
			TextOut(hdc, watch.GetX() + cos(GetRadian(i * 30 - 90)) * (watch.GetRad() - 10), watch.GetY() + sin(GetRadian(i * 30 - 90)) * (watch.GetRad() - 10) - 6, buff, size);
		}

		hNewPen = CreatePen(PS_SOLID, 3, RGB(100, 100, 100));
		SelectObject(hdc, hNewPen);
		MoveToEx(hdc, watch.GetX(), watch.GetY(), NULL);
		LineTo(hdc, watch.GetX() + cos(GetRadian(watch.GetHour() * 30 + watch.GetMin() / 2 - 90)) * (watch.GetRad() / 3), watch.GetY() + sin(GetRadian(watch.GetHour() * 30 + watch.GetMin() / 2 - 90)) * (watch.GetRad() / 3));
		DeleteObject(hNewPen);

		hNewPen = CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
		SelectObject(hdc, hNewPen);
		MoveToEx(hdc, watch.GetX(), watch.GetY(), NULL);
		LineTo(hdc, watch.GetX() + cos(GetRadian(watch.GetMin() * 6 - 90)) * (watch.GetRad() - 20), watch.GetY() + sin(GetRadian(watch.GetMin() * 6 - 90)) * (watch.GetRad() - 20));
		DeleteObject(hNewPen);

		hNewPen = CreatePen(PS_SOLID, 1, RGB(255, 100, 100));
		SelectObject(hdc, hNewPen);
		MoveToEx(hdc, watch.GetX(), watch.GetY(), NULL);
		LineTo(hdc, watch.GetX() + cos(GetRadian(watch.GetSecond() * 6 - 90)) * (watch.GetRad() - 20), watch.GetY() + sin(GetRadian(watch.GetSecond() * 6 - 90)) * (watch.GetRad() - 20));
		DeleteObject(hNewPen);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam)); // case에 있는 메시지를 제외한 나머지 메시지를 처리한다.
}