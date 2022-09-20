// mid_term_project.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <process.h>
using namespace std;
void gotoxy(int x, int y);
void clrscr();
void adamak(int x, int y);
void move(int X, int Y);
void health(int h);
void maane(int a, int b);
void namaayeshe_safhe_asli();
void namaayeshe_aadamak();
int M = 10;
int N = 15;
char map[25][50] = {
	"#################################################",
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
	"#                                               #",
	"#                                               #",
	"#                                               #",
	"#################################################",
};
char aadamak[5][8]= {
	" @@@@@",
	 " |o o|",
     "@| | |@",
	 " | o |",
	" \___/",
};

void namaayeshe_safhe_asli(){
	gotoxy(0, 0);
	for (int i = 0; i < 25; i++){
		cout << map[i] << "\n";
	}
}
void namaayeshe_aadamak(){
	gotoxy(10, 15);
	for (int i = 0; i <5 ; i++){
		cout << aadamak[i] << "\n";
	}
}
int main(int argc, _TCHAR* argv[])
{
	namaayeshe_aadamak();
	namaayeshe_safhe_asli();
	move(M, N);
	cin.ignore();
	return 0; 	
}
void gotoxy(int x, int y){
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(hConsole, pos);
	}
}
void clrscr(){
	system("cls");
}

void move(int X, int Y){
	char ch;
	int x = N, y = M;
	int i = 1;
	adamak(X, Y);
	health(3);
	while (1)
	{
		if (_kbhit()){
			ch = _getch();
			if (ch == 's' || ch == 'S' || ch == '2'){
				if (map[y + 1][x] == ' ')
					y++;
			}
				else if (ch == 'w' || ch == 'W' || ch == '8'){
					if (map[y - 1][x] == ' ')
						y--;
				}
				else if (ch == 'a' || ch == 'A' || ch == '4'){
					if (map[y][x - 1] == ' ') x--;
				}
				else if (ch == 'd' || ch == 'D' || ch == '6'){
					if (map[y][x + 1] == ' ') x++;
				}

				gotoxy(x, y);
				namaayeshe_safhe_asli();
				namaayeshe_aadamak();
			}
		}
	}


void adamak(int x, int y) {
	gotoxy(x, y);
	cout << " @@@@@";
	gotoxy(x, y + 1);
	cout << " |o o|";
	gotoxy(x, y + 2);
	cout << "@| | |@";
	gotoxy(x, y + 3);
	cout << " | o |";
	gotoxy(x, y + 4);
	cout << " \\___/";

}
void health(int h){
		char ch = 2;
		gotoxy(2, 2);
		for (int i = h; i > 0; i--)
			cout << ch << " ";
}
void maane(int a, int b) {
	int x = N, y = M;
	char ch;
	int i = 1;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 's' || ch == 'S' || ch == '2') {
				if (map[y + 1][x] == ' ') y++;

				else if (ch == 'w' || ch == 'W' || ch == '8') {
					if (map[y - 1][x] == ' ') y--;
				}
				else if (ch == 'a' || ch == 'A' || ch == '4') {
					if (map[y][x - 1] == ' ') x--;
				}
				else if (ch == 'd' || ch == 'D' || ch == '6') {
					if (map[y][x + 1] == ' ') x++;
				}
				namaayeshe_safhe_asli();
				gotoxy(x, y);
				namaayeshe_aadamak();
			}
		}
	}
}