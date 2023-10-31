#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include<mmsystem.h>
using namespace std;

//CỐ ĐỊNH MÀN HÌNH CONSOLE (hàm FixConsoleWindow)
void CreateConsoleWindow(int pWidth, int pHeight) {
	HWND consoleWindow = GetConsoleWindow(); // tra ve con tro thao tac console
	RECT r; //cau truc xac dinh hinh chu nhat goc tren ben phai va goc duoi ben trai.
	HANDLE hConsole;  // khai bao bien hConsole kieu HANDLE

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// lay quyen dieu khien output tieu chuan
	SetConsoleTextAttribute(hConsole, 240);// set thuoc tinh cua text, 240 là nen trang chu den
	GetWindowRect(consoleWindow, &r);// truy xuat kich thuoc gioi han cua console
	MoveWindow(consoleWindow, 0, 0, pWidth, pHeight, TRUE);// di chuyen con tro toi toa do (0;0) va set kich thuoc window
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}


//ĐƯA CON TRỎ TỚI VỊ TRÍ XÁC ĐỊNH (hàm gotoXY)
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//TẠO MÀU CHỮ (hàm b_color và set_color)
void set_color(int color) {
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}
int b_color(std::string c, int k) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
	std::cout << c;
	return 0;
}

//CHỮ NHẤP NHÁY (hàm blink_text)
int blink_text(int x, int y, std::string(c)) {
	for (int i = 0; i < 5; i++) {
		gotoXY(x, y);
		b_color(c, 78);
		Sleep(50);
		gotoXY(x, y);
		b_color(c, 73);
		Sleep(50);
		b_color("", 240);
	}
	return 0;
}

//IN RA LOGO (hàm dongchuchinh)
void dongchuchinh() {
	set_color(16);
	printf("            _/_/_/_/_/_/_/_/_\ \n");
	printf("         _/_/_/_/_/_/_/_/_/_/_\ \n");
	printf("        _/_/_/             _/_/\n");
	printf("       _/_/_/           _/_/_/"); set_color(16); printf("              _/_/_/_/_/_/"); set_color(16); printf("     _/_/_/    _/_/_/_/_/_/"); set_color(16); printf("        _/_/_/_/_/_/_/\n"); set_color(16);
	printf("      _/_/_/"); set_color(16); printf("                        _/_/_/_/_/_/_/_/_/"); set_color(16); printf("        _/_/  _/_/_/_/_/_/_/"); set_color(16); printf("    _/_/_/_/_/_/_/_/_/_/_/\n"); set_color(16);
	printf("     _/_/_/"); set_color(16); printf("                     _/_/           _/_/_/"); set_color(16); printf("        _/_/_/_/_/           "); set_color(16); printf("_/_/_/               _/_/_/\n"); set_color(16);
	printf("    _/_/_/"); set_color(16); printf("                   _/_/               _/_/"); set_color(16); printf("        _/_/_/_/            "); set_color(16); printf("_/_/_/                  _/_/_/\n"); set_color(16);
	printf("   _/_/_/"); set_color(16); printf("                   _/_/               _/_/"); set_color(16); printf("        _/_/_/              "); set_color(16); printf("_/_/_/                  _/_/_/\n"); set_color(16);
	printf("  _/_/_/"); set_color(16); printf("                   _/_/               _/_/"); set_color(16); printf("        _/_/                "); set_color(16); printf("_/_/_/                  _/_/_/\n"); set_color(16);
	printf(" _/_/_/"); set_color(16); printf("                   _/_/               _/_/"); set_color(16); printf("        _/_/                "); set_color(16); printf("_/_/_/                  _/_/_/\n"); set_color(16);
	printf("_/_/_/         _/_/_/"); set_color(16); printf("    _/_/_/           _/_/_/"); set_color(16); printf("        _/_/                "); set_color(16); printf("_/_/_/                  _/_/_/\n"); set_color(16);
	printf("\_/_/_/_/_/_/_/_/_/_/"); set_color(16); printf("      _/_/_/_/_/_/_/_/_/_/_/"); set_color(16); printf("       _/_/                  "); set_color(16); printf("_/_/_/_/_/_/_/_/_/_/_/_/_/\n"); set_color(16);
	printf(" \_/_/_/_/_/_/_/_/_/"); set_color(16); printf("        _/_/_/_/_/_/_/_/_/_/_/_/"); set_color(16); printf("   _/_/                    "); set_color(16); printf("_/_/_/_/_/_/_/_/_/_/_/\n"); set_color(16);
}

//VẼ BẢNG (hàm bangchon)
void line_up(int x, int y, int w) {
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y);
		printf("%c", char(196));
	}
	gotoXY(x, y); printf("%c", char(218));
	gotoXY(x + w, y); printf("%c", char(191));
	gotoXY(x, y + 1); printf("%c", char(179));
	gotoXY(x + w, y + 1); printf("%c", char(179));
}
void line_bot(int x, int y, int w) {
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y);
		printf("%c", char(196));
	}
	gotoXY(x, y); printf("%c", char(195));
	gotoXY(x + w, y); printf("%c", char(180));
	gotoXY(x, y + 1); printf("%c", char(179));
	gotoXY(x + w, y + 1); printf("%c", char(179));
}
void line_down(int x, int y, int w) {
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y);
		printf("%c", char(196));
	}
	gotoXY(x, y); printf("%c", char(192));
	gotoXY(x + w, y); printf("%c", char(217));
}

void bangchon() {
	line_up(40, 14, 30);
	line_bot(40, 16, 30);
	line_bot(40, 18, 30);
	line_bot(40, 20, 30);
	line_bot(40, 22, 30);
	line_bot(40, 24, 30);
	line_bot(40, 26, 30);
	line_down(40, 28, 30);
}



//Mục 4. ÂM THANH
int a_th = 1;
void _sound() {
	if (a_th == 1) PlaySound(TEXT("C:\\Users\\ADMIN\\Downloads\\01.-Main-Menu"), NULL, SND_ASYNC | SND_LOOP);
	else PlaySound(NULL, NULL, SND_ASYNC);
}


//Mục 5. HELP
void _help() {
	system("cls");
	printf("\n\n\n\t\t\t\t\t\t  CONTROL:");
	printf("\n\n\t\tUsing 'W', 'A', 'S', 'D' button to go up, left, down, right;\n\t\t press Enter to play");
	printf("\n\n\n\t\t\t\t\t\tINSTRUCTION:\n");
	printf("\n\n\t\t1. Caro is a 2-player game. Players alternate turns marking an X or O on an\n\t\t empty square on the board. The X player go first\n");
	printf("\n\t\t2. The winner is the first player to form an unbroken line of five marks of\n\t\t their color horizontally, vertically, or diagonally.\n");
	printf("\n\t\t3. If the board is completely filled and no one can make a line of 5 Xs or\n\t\t Os, then the game ends in a draw\n");
	printf("\n\n\t\tHAVE FUN!");
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t(Press any key to go back)");
	_getch();
}

//Mục 6. ABOUT
void _about() {
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t\t\tGROUP 7 - 23TNT1:");
	printf("\n\n\n\t\t\t\tStudent 1: 23122010_Nguyen Nhat Minh (Leader)");
	printf("\n\n\t\t\t\tStudent 2: 23122005_Le Hai Dang");
	printf("\n\n\t\t\t\tStudent 3: 23122011_Doan Hai Nam");
	printf("\n\n\t\t\t\tStudent 4: 23122027_Vo Ngoc Hieu");
	printf("\n\n\t\t\t\tInstructor: Mr. Truong Toan Thinh");
	_getch();
}



//XỬ LÝ MENU CHÍNH (hàm menu):
int cn = 1;
void text_with_bg() {																		//tạo chữ có highlight
	if (cn == 1) {
		gotoXY(41, 15); b_color(">>>  PLAYER VS COMPUTER  <<<", 78);
	}
	if (cn != 1) {
		gotoXY(41, 15); b_color("     PLAYER VS COMPUTER     ", 240);
	}
	if (cn == 2) {
		gotoXY(41, 17); b_color(">>>   PLAYER VS PLAYER   <<<", 78);
	}
	if (cn != 2) {
		gotoXY(41, 17); b_color("      PLAYER VS PLAYER      ", 240);
	}
	if (cn == 3) {
		gotoXY(41, 19); b_color(">>>      SAVED GAME      <<<", 78);
	}
	if (cn != 3) {
		gotoXY(41, 19); b_color("         SAVED GAME         ", 240);
	}
	if (cn == 4) {
		switch (a_th) {
		case 0:
			gotoXY(41, 21); b_color(">>>      SOUND: OFF      <<<", 78);
			break;
		case 1:
			gotoXY(41, 21); b_color(">>>      SOUND:  ON      <<<", 78);
			break;
		}
	}
	if (cn != 4) {
		switch (a_th) {
		case 0:
			gotoXY(41, 21); b_color("         SOUND: OFF         ", 240);
			break;
		case 1:
			gotoXY(41, 21); b_color("         SOUND:  ON         ", 240);
			break;
		}
	}
	if (cn == 5) {
		gotoXY(41, 23); b_color(">>>         HELP         <<<", 78);
	}
	if (cn != 5) {
		gotoXY(41, 23); b_color("            HELP            ", 240);
	}
	if (cn == 6) {
		gotoXY(41, 25); b_color(">>>        ABOUT         <<<", 78);
	}
	if (cn != 6) {
		gotoXY(41, 25); b_color("           ABOUT            ", 240);
	}
	if (cn == 7) {
		gotoXY(41, 27); b_color(">>>         EXIT         <<<", 78);
	}
	if (cn != 7) {
		gotoXY(41, 27); b_color("            EXIT            ", 240);
	}
}
void menu() {
	system("cls");
	dongchuchinh();
	bangchon();
	text_with_bg();
	int t = _getch();
	if (t == 13) {				//nhan enter
		switch (cn) {
		case 1:
			blink_text(46, 15, "PLAYER VS COMPUTER");
			break;
		case 2:
			blink_text(47, 17, "PLAYER VS PLAYER");
			//bắt đầu mở game
			break;
		case 3:
			blink_text(50, 19, "SAVED GAME");
			//mở game đã lưu
			break;
		case 4: 
			switch (a_th) {
			case 0:
				blink_text(50, 21, "SOUND: OFF");
				a_th = 1;
				_sound();
				break;
			case 1:
				blink_text(50, 21, "SOUND:  ON");
				a_th = 0;
				_sound();
				break;
			}
			break;
		case 5:
			blink_text(53, 23, "HELP");
			_help();
			break;
		case 6:
			blink_text(52, 25, "ABOUT");
			_about();
			break;
		case 7:
			blink_text(53, 27, "EXIT");
			printf("\n\n________________");
			exit(0);
			break;
		}
	}
	else if (t == 80) {			//mui ten xuong
		cn++;
	}
	else if (t == 72) {			//mui ten len
		cn--;
	}
	if (cn == 8) {
		cn = 1;
	}
	else if (cn == 0) {
		cn = 7;
	}
}

int main() {
	_sound();
	CreateConsoleWindow(1000, 700);
	FixConsoleWindow();
	while (1) {
		menu();
	}
	return 0;
}