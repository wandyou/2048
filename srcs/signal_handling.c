#include "2048.h"

void signal_handler(int signum)
{
	signal_global = 0;
	(void) signum;
	clear();
	mvprintw(LINES/2, (COLS / 2) - 7, "PRESS ANY KEY...");
	refresh();
}
