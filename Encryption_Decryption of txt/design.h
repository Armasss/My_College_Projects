#include <iostream>

using namespace std;

char design[6] = {char(218),char(196),char(191),char(179),char(192),char(217)};
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void createBox(int x, int y, int width, int height, int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
    gotoxy(x, y);
    cout << design[0] << flush; //cout << " " << flush;
    for (int i = 0; i < width - 2; i++) {
    cout << design[1] << flush;/*cout << "_" << flush;*/
    }
    cout << design[2] << flush;

    for (int i = 1; i < height - 1; i++) {
        gotoxy(x, y + i);
    cout << design[3] << flush;//cout << "|" << flush;
        for (int j = 0; j < width - 2; j++) {
            cout << " ";
        }
    cout <<  design[3] << "\n" << flush;
    }
    gotoxy(x, y + height - 1);
    cout << design[4] << flush;//cout << "" << flush;
    for (int i = 0; i < width - 2; i++) {
    cout << design[1] << flush;//cout << "_" << flush;
    }
    cout << design[5] << flush;
}
void clearArea(int x, int y, int width, int height) {
    for (int i = 0; i < height; i++) {
        gotoxy(x, y + i);
        for (int j = 0; j < width; j++) {
            cout << " " <<  flush;
        }
    }
}

void showcursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}



