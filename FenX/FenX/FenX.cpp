// FenX.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "FenX.h"
#include <math.h>
#include <complex>

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
//
const int iXmax = 700;
const int iYmax = 600;
//绘制平面的最大像素范围
//例子为600*600
const double CxMin = -2.5;
const double CxMax = 1.5;
const double CyMax = 2.0;
const double CyMin = -2.0;
//逻辑上x与y范围
double NUM = 0.5;
double NUMx = -0.576;
double NUMy = 0.456;
//茱莉亚集合用
const int IterationMax = 200;
//递归最大次数
const double EscapeRadius = 2;
//逃逸半径
char oper='1';
//switch
float amplitude = 50;
float step = 60;
//sin

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_FENX, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FENX));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FENX));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_FENX);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
		zuichudeqidian:
	case WM_KEYDOWN:
		switch (wParam) {
		case  '1':
			oper = '1';
			NUMx = -0.576;
			NUMy = 0.456;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '2':
			oper = '2';
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '3':
			oper = '1';
			NUMx = -0.85;
			NUMy = 0.0088;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '4':
			oper = '1';
			//NUMx = -0.85;
			//NUMy = 0.088;
			//NUMx = -0.576;
			//NUMy = 0.456;
			//NUMx = -0.285;
			//NUMy = 0.02;
			NUMx = -0.85;
			NUMy = 0.088;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '5':
			oper = '1';
			NUMx = 0.285;
			NUMy = 0.1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '6':
			oper = '1';
			NUMx = 0.3;
			NUMy = -0.1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '7':
			oper = '7';
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '8':
			oper = '8';
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '9':
			oper = '9';
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case '0':
			oper = '0';
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'W':			
			step = step - 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'A':
			
			amplitude = amplitude - 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'S':			
			step = step + 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 'D':
			amplitude = amplitude + 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
			switch (oper) {
			case '1':
			zhuliyajihe:
				{int iX, iY;//像素位置
				double Cx, Cy;//数学公式中逻辑坐标
				double PixelWidth = (CxMax - CxMin) / iXmax;
				double PixelHeight;
				PixelHeight = (CyMax - CyMin) / iYmax;
				//PixelWidth、PixelHeight对应像素大小
				//用来计算像素实际坐标与逻辑坐标之间对应关系
				COLORREF color;
				//决定要不要上色
				double Zx, Zy;
				double Zx2, Zy2;
				//_Fcomplex Z=0.I;
				double a = 0; double b = 0;
				//std::complex<double> Z(a, b);
				//公式核心
				int Iteration;//记录递归次数
				double ER2;
				ER2 = EscapeRadius * EscapeRadius;
				//逃逸半径平方
				//以下for循环计算是否达到逃逸条件
				for (iY = 0; iY < iYmax; iY++)
				{
					Cy = CyMin + iY * PixelHeight;
					if (fabs(Cy) < PixelHeight / 2) Cy = 0.0;
					//
					for (iX = 0; iX < iXmax; iX++)//循环每一列
					{
						Cx = CxMin + iX * PixelHeight;
						Zx = Zy = Zy2 = Zx2 = 0.0;
						Iteration = 0;
						//针对每个像素进行循环计算

						/*while (Iteration < IterationMax && ((Zx2 + Zy2) < ER2))
						{

							Zy = 2 * Zx*Zy + Cy;
							Zx = Zx2 - Zy2 + Cx;
							Zx2 = Zx * Zx;
							Zy2 = Zy * Zy;
							Iteration++;

						}*/

						while (Iteration < IterationMax && ((Zx2 + Zy2) < ER2))
						{
							if (Iteration == 0)
							{

								Zy = 2 * Cx*Cy + NUMy;
								Zx = Cx * Cx - Cy * Cy + NUMx;
								Zx2 = Zx * Zx;
								Zy2 = Zy * Zy;
								Iteration++;
							}
							if (Iteration >= 1)
							{
								Zy = 2 * Zx*Zy + NUMy;
								Zx = Zx2 - Zy2 + NUMx;
								Zx2 = Zx * Zx;
								Zy2 = Zy * Zy;
								Iteration++;
							}

						}

						/*while (Iteration < IterationMax && (a*a+b*b < ER2))
						{
							double aII = a; double bII = b;
							a = aII*aII - bII*bII+Cx;
							b = 2 * aII*bII+Cy;
							std::complex<double> Z(a, b);
							Iteration++;
						}*///做梦呢
						if (Iteration == IterationMax)
							color = RGB(0, 0, 0);//前景色黑色
						else
							color = RGB(255, 255, 255);//背景色白色

						SetPixel(hdc, iX, iY, color);
						//
					}
				}
				}
				break;
			mandeboji:
			case '2':
				{int iX, iY;//像素位置
				double Cx, Cy;//数学公式中逻辑坐标
				double PixelWidth = (CxMax - CxMin) / iXmax;
				double PixelHeight;
				PixelHeight = (CyMax - CyMin) / iYmax;
				//PixelWidth、PixelHeight对应像素大小
				//用来计算像素实际坐标与逻辑坐标之间对应关系
				COLORREF color;
				//决定要不要上色
				double Zx, Zy;
				double Zx2, Zy2;
				//_Fcomplex Z=0.I;
				double a = 0; double b = 0;
				//std::complex<double> Z(a, b);
				//公式核心
				int Iteration;//记录递归次数
				double ER2;
				ER2 = EscapeRadius * EscapeRadius;
				//逃逸半径平方
				//以下for循环计算是否达到逃逸条件
				for (iY = 0; iY < iYmax; iY++)
				{
					Cy = CyMin + iY * PixelHeight;
					if (fabs(Cy) < PixelHeight / 2) Cy = 0.0;
					//
					for (iX = 0; iX < iXmax; iX++)//循环每一列
					{
						Cx = CxMin + iX * PixelHeight;
						Zx = Zy = Zy2 = Zx2 = 0.0;
						Iteration = 0;
						//针对每个像素进行循环计算

						while (Iteration < IterationMax && ((Zx2 + Zy2) < ER2))
						{

							Zy = 2 * Zx*Zy + Cy;
							Zx = Zx2 - Zy2 + Cx;
							Zx2 = Zx * Zx;
							Zy2 = Zy * Zy;
							Iteration++;
						}
						

						/*while (Iteration < IterationMax && (a*a+b*b < ER2))
						{
							double aII = a; double bII = b;
							a = aII*aII - bII*bII+Cx;
							b = 2 * aII*bII+Cy;
							std::complex<double> Z(a, b);
							Iteration++;
						}*///做梦呢
						if (Iteration == IterationMax)
							color = RGB(0, 0, 0);//前景色黑色
						else
							color = RGB(255, 255, 255);//背景色白色

						SetPixel(hdc, iX, iY, color);
						//
					}
				}				
				}
				break;
			disanzhe:
			case '0':
				{int iX, iY;//像素位置
				double PixelWidth = (CxMax - CxMin) / iXmax;
				double PixelHeight;
				PixelHeight = (CyMax - CyMin) / iYmax;
				COLORREF color;
				for (iX = 0; iX < iXmax; iX++)
				{
					iY = sin(iX*3.1415926 / 180)*amplitude+step;
					//iY = sin(iX*3.1415926 / 180) * 50 + 60;
					color = RGB(0, 0, 0);//前景色黑色
					SetPixel(hdc, iX, iY, color);
						
					
				}				
				}//c3
				break;
			meiguihua:
			case '7':
			{
				int iX, iY;
				int iXII;
				double PixelWidth = (CxMax - CxMin) / iXmax;
				double PixelHeight;
				PixelHeight = (CyMax - CyMin) / iYmax;
				COLORREF color;
				//for (iX = 0; iX < iXmax; iX++)
				for (iX = 0; iX < 800; iX++)
				{
					float ix = iX * 3.1415926 / 180;
					iXII = 50 * sin(3*ix/2)* cos(ix)+ amplitude;
					iY = 50 * sin(3*ix/2)* sin(ix)+step;
					//x=a* sin(nθ)* cos(θ), y=a*sin(nθ)* sin(θ)
					//如对于方程式ρ=5* sin(3*θ)、ρ=5* sin(2*θ)、ρ=5* sin(3*θ/2)，分别对应的是三叶、四叶和六叶玫瑰线
					//iY = sin(iX*3.1415926 / 180) * 50 + 60;
					color = RGB(0, 0, 0);//前景色黑色
					SetPixel(hdc, iXII, iY, color);


				}

			}
			break;//c4
		yuan:
			case '9':
			{
				
				int iX, iY;
				int iXII;
				double PixelWidth = (CxMax - CxMin) / iXmax;
				double PixelHeight;
				PixelHeight = (CyMax - CyMin) / iYmax;
				COLORREF color;
				//for (iX = 0; iX < iXmax; iX++)
				for (iX = 0; iX < 800; iX++)
				{
					float ix = iX * 3.1415926 / 180;
					iXII = 50*cos(ix) + amplitude;
					iY = 50*sin(ix) + step;
					//x=a* sin(nθ)* cos(θ), y=a*sin(nθ)* sin(θ)
					//如对于方程式ρ=5* sin(3*θ)、ρ=5* sin(2*θ)、ρ=5* sin(3*θ/2)，分别对应的是三叶、四叶和六叶玫瑰线
					//iY = sin(iX*3.1415926 / 180) * 50 + 60;
					color = RGB(0, 0, 0);//前景色黑色
					SetPixel(hdc, iXII, iY, color);


				}
			}
			break;//c0
			luoxuanxian:
			case '8':
			{
				{

					int iX, iY;
					int iXII;
					double PixelWidth = (CxMax - CxMin) / iXmax;
					double PixelHeight;
					PixelHeight = (CyMax - CyMin) / iYmax;
					COLORREF color;
					//for (iX = 0; iX < iXmax; iX++)
					for (iX = 0; iX < 800; iX++)
					{
						float ix = iX * 3.1415926 / 180;
						iXII = (5+5*ix) * cos(ix) + amplitude;
						iY = (5+5*ix) * sin(ix) + step;
						//x=a* sin(nθ)* cos(θ), y=a*sin(nθ)* sin(θ)
						//如对于方程式ρ=5* sin(3*θ)、ρ=5* sin(2*θ)、ρ=5* sin(3*θ/2)，分别对应的是三叶、四叶和六叶玫瑰线
						//iY = sin(iX*3.1415926 / 180) * 50 + 60;
						color = RGB(0, 0, 0);//前景色黑色
						SetPixel(hdc, iXII, iY, color);


					}
				}
			}
			break;//c8



			}
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
