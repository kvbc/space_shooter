#include "cmd.h"


void cmd::clear() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    	DWORD buffer;
	FillConsoleOutputCharacter(hOut, ' ', 1, {0, 0}, &buffer);
	SetConsoleCursorPosition(hOut, {0, 0});
}


void cmd::hideCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}


void cmd::setWindowSize(int x, int y) {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, x, y, TRUE);
}
