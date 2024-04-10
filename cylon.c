#include <stdio.h>
#include <conio.h> /* getch */
#include <graph.h> /* set video mode */
#include <i86.h> /* delay */

char right[] = { ' ', 0xb0, 0xb1, 0xb2, 0xdb }; /* 5 */
char left[] = { 0xdb, 0xb2, 0xb1, 0xb0, ' ' }; /* 5 */

int pause(void)
{
    int key;

    key = getch();

    if (key == 0) {
	/* ext key .. call getch again to clear it */
	getch();
	/* .. return the original zero value anyway */
    }

    return key;
}

int move_cylon(int dir)
{
/* dir should be only +1 (right) or -1 (left) */

    int col;

    if (dir == 1) {
	/* right */
	col = 1;
    }
    else if (dir == -1) {
	/* left */
	col = 75;
    }
    else {
	return 0;
    }

    /* move the cylon */

    while ((col > 0) && (col < 76)) {
	_settextposition(1, col);

	if (dir == 1) {
	    _outmem(right, 5);
	}
	else {
	    _outmem(left, 5);
	}

	delay(10);
	col += dir;

	/* check for quit */

	if (kbhit()) {
	    if (pause() == 27) { /* Esc key */
		return 0;
	    }
	}
    }

    return 1;
}

int main()
{
    int dir = 1;

    /* set up the screen */

    if (_setvideomode(_TEXTC80) == 0) {
	return 1;
    }

    _setbkcolor(7); /* white */
    _clearscreen(_GCLEARSCREEN);

    _setbkcolor(0); /* black */
    _settextcolor(12); /* br red */
    _settextwindow(10, 1, 10, 80);
    _clearscreen(_GWINDOW);

    _settextcursor(0x2000); /* no cursor */

    while ( move_cylon(dir) ) {
	dir *= -1; /* reverse direction */
    }

    _settextcursor(0x0607);
    _setvideomode(_DEFAULTMODE);

    puts("By your command!");
    return 0;
}
