#include <windows.h>
#include <stdlib.h>
void set_size(int width, int height) {
    CONSOLE_CURSOR_INFO ConsoleCursorInfo;
    SMALL_RECT ConsoleWindow;
    COORD dwSize;
    HANDLE hConsoleOutput;

    dwSize.X = (short)width;
    dwSize.Y = (short)height;
    *(unsigned int *)&ConsoleWindow.Left = 0;
    *(unsigned int *)&ConsoleWindow.Right = ((unsigned __int16)(height - 1) << 16) | (unsigned __int16)(width - 1);
    ConsoleCursorInfo.dwSize = 1;
    ConsoleCursorInfo.bVisible = 0;
    hConsoleOutput = GetStdHandle(0xFFFFFFF5);
    SetConsoleWindowInfo(hConsoleOutput, 1, &ConsoleWindow);
    SetConsoleScreenBufferSize(hConsoleOutput, dwSize);
    SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}
void set_title(char *title) {
    SetConsoleTitleA(title);
}
void gotoxy(int x, int y){
    HANDLE v2;
    COORD dwCursorPosition;

    dwCursorPosition.X = (short)x;
    dwCursorPosition.Y = (short)y;
    v2 = GetStdHandle(0xFFFFFFF5);
    SetConsoleCursorPosition(v2, dwCursorPosition);
}
void hide_cursor(void) {
    struct _CONSOLE_CURSOR_INFO ConsoleCursorInfo;
    HANDLE hConsoleOutput;

    hConsoleOutput = GetStdHandle(0xFFFFFFF5);
    GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
    ConsoleCursorInfo.bVisible = 0;
    SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}
void show_cursor(void) {
    struct _CONSOLE_CURSOR_INFO ConsoleCursorInfo;
    HANDLE hConsoleOutput;

    hConsoleOutput = GetStdHandle(0xFFFFFFF5);
    GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
    ConsoleCursorInfo.bVisible = 1;
    SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}
void set_color(int bcolor, int fcolor) {
    HANDLE v2;
    v2 = GetStdHandle(0xFFFFFFF5);
    SetConsoleTextAttribute(v2, fcolor + 16 * bcolor);
}
void delay(int dtime) {
    Sleep(dtime);
}
void play_sound(const char *sndfile) {
    PlaySoundA(sndfile, 0, 0x20001u);
}
void cls(void) {
    system("cls");
}
int getkey(void) {
  int ch;
  ch = getch();
  if ( !ch || ch == 224 )
    ch = getch();
  return ch;
}