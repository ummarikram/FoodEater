#ifndef MYGRAPHICS_H_
#define MYGRAPHICS_H_

#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     // Part of the Font Color Function.

// function prototypes

void drawLine(int x1,int y1,int x2,int y2,int colour); // draws a line between two points given their x-y coordinates in gray-scale
void drawLine(int x1,int y1,int x2,int y2,int r, int g, int b); // draws a line between two points given their x-y coordinates using RGB colouring
void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B); // draws a rectangle using top-left and bottom-right x-y coordinates with a border using RGB colouring
void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB ); // draws a rectangle using top-left and bottom-right x-y coordinates with separate border and fill colours
void drawEllipse(int x1, int y1, int x2, int y2,int R, int G, int B); // draws a rectangle-bounded ellipse using top-left and bottom-right x-y coordinates with a border using RGB colouring
void drawEllipse(int x1, int y1, int x2, int y2,int R, int G, int B, int FR, int FG, int FB); // draw a rectangle-bounded ellipse using top-left and bottom-right x-y coordinates with separate border and fill colours
void cls(); // clears the screen
void delay(int ms); // waits for some time (in milli-seconds)
char getKey(); // gets key typed into the console without waiting for the input
void getWindowDimensions(int& width, int& height); // gets width and height of the window
void getConsoleWindowDimensions(int& width, int& height); // gets width and height of console window (in character mode)
void gotoxy(int x,int y); // sets console cursor on given x-y coordinates
void showConsoleCursor(bool showFlag); // shows or hides the cursor
void fontsize(int a, int b); // Font size adjustment
void SetConsoleWindowDimensions(int a, int b); // Console window adjustment.
void Maximize(); 
void SetConsoleStyle(int x, int y);
void SetINTRO();


// function definitions

void drawLine(int x1,int y1,int x2,int y2,int colour){
	drawLine(x1,y1,x2,y2,colour,colour,colour);
}

void drawLine(int x1, int y1, int x2, int y2,int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND consoleHandle = GetConsoleWindow();
    HDC deviceContext = GetDC(consoleHandle);

    //change the colour by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for color.
	HPEN pen = CreatePen(PS_SOLID,2,RGB(R,G,B)); //2 is the width of the pen
    SelectObject(deviceContext,pen);
	MoveToEx(deviceContext,x1,y1,NULL);
    LineTo(deviceContext,x2, y2);
    DeleteObject(pen);
	ReleaseDC(consoleHandle, deviceContext);
}

void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B){
	drawRectangle(x1, y1, x2, y2, R, G, B, 0,0,0);
}

void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB )
{
	HWND consoleHandle = GetConsoleWindow();
    HDC deviceContext = GetDC(consoleHandle);

    //change the colour by changing the values in RGB (from 0-255)
    HPEN pen = CreatePen(PS_SOLID,2,RGB(R,G,B));
    SelectObject(deviceContext,pen);
	HBRUSH brush = CreateSolidBrush(RGB(FR,FG,FB));
	SelectObject(deviceContext,brush);
	Rectangle(deviceContext,x1,y1,x2,y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(consoleHandle, deviceContext);

}

void drawEllipse(int x1, int y1, int x2, int y2,int R, int G, int B){
	drawEllipse(x1, y1, x2, y2, R, G, B, 0, 0, 0);
}

void drawEllipse(int x1, int y1, int x2, int y2,int R, int G, int B,int FR,int FG,int FB)
{
	HWND consoleHandle = GetConsoleWindow();
    HDC deviceContext = GetDC(consoleHandle);

    //change the colour by changing the values in RGB (from 0-255)

    HPEN pen = CreatePen(PS_SOLID,2,RGB(R,G,B));
    SelectObject(deviceContext,pen);
	HBRUSH brush = CreateSolidBrush(RGB(FR,FG,FB)); // fill colour
	SelectObject(deviceContext,brush);
	Ellipse(deviceContext,x1,y1,x2,y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(consoleHandle, deviceContext);

}

void cls()
{
   COORD coordScreen = { 0, 0 };    // home for the cursor
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;

   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

   if( !GetConsoleScreenBufferInfo( consoleHandle, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   FillConsoleOutputCharacter( consoleHandle,        // Handle to console screen buffer
                               (TCHAR) ' ',          // Character to write to the buffer
                               dwConSize,            // Number of cells to write
                               coordScreen,          // Coordinates of first cell
                               &cCharsWritten );     // Receive number of characters written

}

void delay(int ms)
{
	Sleep(ms);
}

char getKey()
{
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD events;
	INPUT_RECORD buffer;
	PeekConsoleInput(handle, &buffer, 1, &events);

	if (events > 0)
	{
		ReadConsoleInput(handle, &buffer, 1, &events);
		return buffer.Event.KeyEvent.wVirtualKeyCode;
	}
	else return 0;
}

void getWindowDimensions(int& width, int& height)
{
	HWND consoleHandle = GetConsoleWindow();
	RECT rc;
	GetClientRect(consoleHandle, &rc);
	width = rc.right;
	height = rc.bottom;
}

void getConsoleWindowDimensions(int& width, int& height)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if( !GetConsoleScreenBufferInfo( consoleHandle, &csbi )) {
	   return;
	}

	width = csbi.srWindow.Right;
	height = csbi.srWindow.Bottom;
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void showConsoleCursor(bool flag)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = flag; // show or hide if flag is true or false respectively
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void fontsize(int a, int b)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;     // Width(Pixel) of Font.
	lpConsoleCurrentFontEx->dwFontSize.Y = b;     // Height(Pixel) of Font.
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

void SetConsoleWindowDimensions(int a, int b)
{
	HWND console = GetConsoleWindow();                          // Fixing console windwow dimension to avoid shapes being dispersed on different computers.
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, a, b, TRUE);            

}

void Maximize()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);

}

void SetConsoleStyle(int x, int y)
{
	CONSOLE_FONT_INFOEX cf = { 0 };
	cf.cbSize = sizeof cf;
	cf.dwFontSize.X = x;
	cf.dwFontSize.Y = y;
	wcscpy_s(cf.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

void BlackBackground()
{
	drawRectangle(265, 20, 1285, 675, 0, 0, 0);
}

void SetINTRO(string Text)
{
	showConsoleCursor(false);

	system("mode 650");

	Maximize();

	SetConsoleStyle(34, 70);

	gotoxy(15, 5);

	int len = Text.length();

	PlaySound(TEXT("Wind2.wav"), NULL, SND_FILENAME | SND_ASYNC);

	for (int i = 0; i < len; i++)
	{
		putchar(Text[i]);

		delay(450);
	}

	for (int i = 0; i < 265; i++)
	{
		drawLine(460 + (i * 2), 330, 460 + (i * 2), 450, 0);

		delay(25);
	}
	
	delay(1000);

	system("cls");
	
	fontsize(26, 36);

	system("mode 650");

	Maximize();

	gotoxy(80, 20);

	cout << "Loading";

	int count = 0;

	while (count < 3)
	{
		delay(500);
		std::cout << "." << std::flush;
		delay(500);
		std::cout << "." << std::flush;
		delay(500);
		std::cout << "." << std::flush;
		delay(500);
		std::cout << "\b\b\b   \b\b\b" << std::flush;
		count++;
	}

	system("cls");
}

#endif /* MYGRAPHICS_H_ */
