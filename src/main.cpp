#include "menu.h"
#include "cmd.h"


int main() {
	cmd::setWindowSize(1023 + 11, 663);
	cmd::hideCursor();

	Menu menu;
	while(menu.open()) {
		try {
			menu.update();
		}
		catch(int option) { switch(option) {
			case 0:
				menu.start_game();
				Sleep(100);
				break;
			case 1:
				menu.options();
				Sleep(100);
				break;
			case 2:
				exit(0);
		}}

		Sleep(1);
		cmd::clear();
	}
}