#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <iostream>
#include "functions.h"
using namespace std;

int makane_x_maane;
int makane_y_maane;
int flag = 1;

int X1;
int Y1;
char map[25][50]{
	"#################################################",
	"#                                               #",
	"#                                               #",
	"#-----------------------------------------------#",

	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#################################################",
};
char aadamak[5][8]{
	" @@@@@",
	" |o o|",
	"@| | |@",
	" | o |",
	" \\___/",
};
char clear[5][8] = {
	"       ",
	"       ",
	"       ",
	"       ",
	"       "
}; 
void gotoxy(int x, int y) {
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
}
void clrscr() {
	system("cls");
}
void namaayeshe_safhe_asli() {
	gotoxy(0, 0);
	for (int i = 0; i < 25; i++)
		cout << map[i] << "\n";
}
void namaayeshe_aadamak(int x1, int y1) {
	for (int i = 0; i <5; i++) {
		gotoxy(x1, y1);
		cout << aadamak[i];
		y1++;
	}
}
void clear_adamak(int x1, int y1)
{
	for (int i = 0; i <5; i++) {
		gotoxy(x1, y1);
		cout << clear[i];
		y1++;
	}
}
void move(char ch, int& x2, int& y2) {
	while (flag)
	{
		if (ch == 's' || ch == 'w' || ch == 'd' || ch == 'a') {
			clear_adamak(x2, y2);
			if (ch == 's') {
				if (map[y2 + 5][x2] == ' ')	y2++;
			}
			else if (ch == 'w') {
				if (map[y2 - 1][x2] == ' ')y2--;
			}
			else if (ch == 'a') {
				if (map[y2][x2 - 1] == ' ') x2--;
			}
			else if (ch == 'd') {
				if (map[y2][x2 + 7] == ' ') x2++;
			}
		}
		else if (_kbhit() != 0) {
			ch = _getch();
			clear_adamak(x2, y2);
			if (ch == 's' || ch == 'S' || ch == 50 || ch == 80) {
				if (map[y2 + 5][x2] == ' ')	y2++;
			}
			else if (ch == 'w' || ch == 'W' || ch == 56 || ch == 72) {
				if (map[y2 - 1][x2] == ' ')y2--;
			}
			else if (ch == 'a' || ch == 'A' || ch == 52 || ch == 75) {
				if (map[y2][x2 - 1] == ' ') x2--;
			}
			else if (ch == 'd' || ch == 'D' || ch == 54 || ch == 77) {
				if (map[y2][x2 + 7] == ' ') x2++;
			}
			else if (ch == 27)
				exit(1);
		}
		

		namaayeshe_safhe_asli();
		health(3);
		namaayeshe_aadamak(x2, y2);
		maane(makane_x_maane, x2, y2);
		flag = 0;
	}
}


void health(int h) {
	char ch = 2;
	gotoxy(2, 2);
	for (int i = h; i > 0; i--)
		cout << ch << " ";
}
void maane(int i, int& x2, int& y2) {
	int y = makane_y_maane;
	char ch;

	srand((unsigned)time(NULL));
	if (i == 45)
		y = RangedRandDemo(3, 23);

	for (i = 45; i >= 1; i--) {
		if (i == 1) {
			y = RangedRandDemo(3, 23);
			i = 45;
		}
		else {
			gotoxy(i, y);
			cout << "<--";
			Sleep(50);
			gotoxy(i-3, y);
			cout << "  ";
			flag = 1;
			if (_kbhit() != 0) {
				ch = _getch();
				makane_x_maane = i;
				makane_y_maane = y;
				if (ch == 's' || ch == 'S' || ch == 50 || ch == 80) {
					namaayeshe_safhe_asli();
					health(3);
					namaayeshe_aadamak(x2, y2);
					move('s');
				}
				else if (ch == 'w' || ch == 'W' || ch == 56 || ch == 72) {
					namaayeshe_safhe_asli();
					health(3);
					namaayeshe_aadamak(x2, y2);
					move('w');
				}
				else if (ch == 'a' || ch == 'A' || ch == 52 || ch == 75) {
					namaayeshe_safhe_asli();
					health(3);
					namaayeshe_aadamak(x2, y2);
					move('a');
				}
				else if (ch == 'd' || ch == 'D' || ch == 54 || ch == 77) {
					namaayeshe_safhe_asli();
					health(3);
					namaayeshe_aadamak(x2, y2);
					move('d');
				}
				else if (ch == 27)
					exit(1);
			}
			else {
				namaayeshe_safhe_asli();
				health(3);
				namaayeshe_aadamak(x2, y2);
				continue;
			}
		}
	}
}

int RangedRandDemo(int range_min, int range_max)
{
	// Generate random numbers in the half-closed interval
	// [range_min, range_max). In other words,
	// range_min <= random number < range_max
	int i;
	int x[3], y;
	srand((unsigned)time(NULL));
	for (i = 0; i < 3; i++)
	{
		int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
			+ range_min;
		x[i] = u;
	}
	y = x[2];
	return y;
}
