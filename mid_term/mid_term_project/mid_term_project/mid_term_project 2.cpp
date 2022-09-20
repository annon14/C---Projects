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
int M = 15;
int N = 17;
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

void namaayeshe_safhe_asli(){
	for (int i = 0; i < 25; i++){
		cout << map[i] << "\n";
	}
}
int main(int argc, _TCHAR* argv[])
{
		
	move(N, M);
	cin.ignore();
	return 0; 
	
}
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(hConsole, pos);
	}
}
void clrscr()
{
	system("cls");
}

void move(int X, int Y){
	adamak(X, Y);
	health(3);
	char ch;
	while (1){
		if (_kbhit()){
			ch = _getch();


			if (ch == 's' || ch == 'S' || ch == '2'){
				Y++;
				clrscr();
				for (int i = 0; i < 25; i++){
					cout << map[i] << "\n";
				}
				adamak(X, Y);
				health(3);
				maane(M, N);
			}
			else if (ch == 'w' || ch == 'W' || ch == '8'){
				Y--;
				clrscr();
				adamak(X, Y);
				health(3);
				maane(M, N);

			}
			else if (ch == 'a' || ch == 'A' || ch == '4'){
				X--;
				clrscr();
				for (int i = 0; i < 25; i++){
					cout << map[i] << "\n";
				}
				adamak(X, Y);
				health(3);
				maane(M, N);
			}
			else if (ch == 'd' || ch == 'D' || ch == '6'){
				X++;
				clrscr();
				for (int i = 0; i < 25; i++){
					cout << map[i] << "\n";
				}
				adamak(X, Y);
				health(3);
				maane(M, N);
			}
		}

	}
}
void adamak(int x, int y){
	gotoxy(x, y);
	cout << " @@@@@";
	gotoxy(x, y+1);
	cout << " |o o|" ;
	gotoxy(x, y+2);
	cout << "@| | |@" ;
	gotoxy(x, y+3);
	cout << " | o |" ;
	gotoxy(x, y+4);
	cout << " \\___/" ;
}
void health(int h){
	gotoxy(2, 2);
	char ch = 2;
	for (int i = h; i > 0; i--){
		cout << ch<<" ";
	}

}
void maane(int a, int b){
	int X=N, Y=M;
	char ch;
	int i = 1;
	while (1)
	{
		if (_kbhit()){
			ch = _getch();
		}
	}
		

			if (ch == 's' || ch == 'S' || ch == '2'){
				Y++;
				clrscr();
				for (int i = 0; i < 25; i++){
					cout << map[i] << "\n";
				}
				adamak(X, Y);
				health(3);
				move(M, N);
			}
			else if (ch == 'w' || ch == 'W' || ch == '8'){
				Y--;
				clrscr();
				for (int i = 0; i < 25; i++){
					cout << map[i] << "\n";
				}
				adamak(X, Y);
				health(3);
				move(M, N);

			}
			else if (ch == 'a' || ch == 'A' || ch == '4'){
				X--;
				clrscr();
				adamak(X, Y);
				health(3);
				move(M, N);
			}
			else if (ch == 'd' || ch == 'D' || ch == '6'){
				X++;
				clrscr();
				adamak(X, Y);
				health(3);
				move(M, N);

			}
		
		else{
			
			 for (int c = 79; c >= 1; c--){
				gotoxy(c, b);
				cout << "<-- ";
				Sleep(50);
			}
			
		}
	}
