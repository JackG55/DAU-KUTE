#pragma once
#include<string.h>
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<io.h>
using namespace std;

#pragma warning(disable:4996)
#pragma warning(disable:4018)
#pragma warning(disable:4715)
#pragma warning(disable:4244)
#pragma warning(disable:4101)



//ham console
void gotoxy(short, short);
void Color(int);
void XoaManHinh();
void moveCursor(int x, int y);
void hideCursor();
void showCursor();
void delline(int x, int y, int length);
void center(int dau, int cuoi, int y, int length);

//ham dieu huong
int up();
int down();
int right();
int left();
int esc();
int enter();
int tab();
//bonus
void xoa_hang(int, int, int);
void Xoa_man_hinh();

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

HANDLE hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsoleColor, &csbi);
	return csbi.dwCursorPosition;
}

void moveCursor(int x, int y)  //ham dich chuyen con tro  
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsoleColor, pos);
}


void hideCursor() //ham an con tro  
{
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hConsoleColor, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(hConsoleColor, &info);
}

void showCursor() {  //ham hien con tro
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hConsoleColor, &info);
	info.bVisible = true;
	SetConsoleCursorInfo(hConsoleColor, &info);
}


void Color(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void center(int dau, int cuoi, int y, int length)
{
	int x;
	if ((cuoi - dau - length) % 2 == 0)
	{
		x = (cuoi - dau - length) / 2 + dau;
	}
	else
	{
		x = (cuoi - dau - length) / 2 + dau + 1;
	}
	gotoxy(x, y);
}

//ham xoa man hinh 
void Xoa_man_hinh()
{
	system("cls");
}

void delline(int x, int y, int length)
{
	gotoxy(x, y);
	for (int i = 0; i < length; i++)
	{
		cout << " ";
	}
}

int up()
{
	return 72;
}

int down()
{
	return 80;
}

int enter()
{
	return 13;
}

int left()
{
	return 75;
}

int right()
{
	return 77;
}

int esc()
{
	return 27;
}

int tab()
{
	return 9;
}

int backspace()
{
	return 8;
}