#include<Windows.h>
#include<math.h>
#include<string>
#include<ctime>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪
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

	HPEN hNewPen;

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 40, Move);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_DESTROY: // �����찡 �ı��Ǿ��ٴ� �޼���
		KillTimer(hWnd, 1);
		PostQuitMessage(0); //GetMessage�Լ��� WM_QUIT �޽����� ������.
		return 0; //WndProc�� Switch�� break ��� return 0; �� ����.
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
	return(DefWindowProc(hWnd, iMessage, wParam, lParam)); // case�� �ִ� �޽����� ������ ������ �޽����� ó���Ѵ�.
}