#include <stdio.h>
#include <conio.h>
#include <graph.h>
#include <string.h>

#define XRES 640
#define YRES 480

int
isodd(int n)
{
    return (n&1);
}

void
print_title(const char *title)
{
    _setcolor(5); /* magenta */
    _rectangle(_GFILLINTERIOR, 1, 1, XRES, 12);

    _setcolor(15); /* br white */
    _moveto(XRES/2 - (strlen(title)*4), 3); /* 8x8 font .. so strlen*8/2 */
    _outgtext(title);
}

void
print_status(const char *status)
{
    _setcolor(3); /* cyan */
    _rectangle(_GFILLINTERIOR, 1, YRES-12, XRES, YRES);

    /* if you don't register and set a font, outgtext uses a std 8x8 font */

    _setcolor(15); /* br white */

    _moveto(4, YRES-10);
    _outgtext(status);
    }

int
main()
{
    int sq;
    int size, offset;

    /* set video mode */

    if (_setvideomode(_VRES16COLOR) == 0) {
	_setvideomode(_DEFAULTMODE);
	fputs("Cannot set video mode\n", stderr);
	return 1;
    }

    size = XRES/10;
    offset = 100;

    /* draw board */

    _setcolor(2); /* green */
    _rectangle(_GFILLINTERIOR, 1, 1, XRES, YRES);

    print_title("SIMPLE SENET");
    print_status("hang on a second while I draw the board on the screen . . .");

    _setcolor(8); /* br black */
    _rectangle(_GFILLINTERIOR, 1, 1+offset, XRES, (size*3) + offset);

    for (sq = 0; sq < 10; sq++) {
	_setcolor(7); /* white */

	if (isodd(sq)) {
	    /* 1st & 3rd rows */

	    _rectangle(_GFILLINTERIOR,
		size*sq, 1+offset, size*(sq+1), size+offset);
	    _rectangle(_GFILLINTERIOR,
		size*sq, (size*2)+offset, size*(sq+1), (size*3)+offset);
	}
	else {
	    /* 2nd row */

	    _rectangle(_GFILLINTERIOR,
		size*sq, size+offset, size*(sq+1), (size*2)+offset);
	}
    }

    /* draw pieces */

    for (sq = 0; sq < 10; sq++) {
	_setcolor( (isodd(sq) ? 9 : 12) ); /* br blue & br red */
	_ellipse(_GFILLINTERIOR,
	    (size*sq) + 10, 10+offset, (size*(sq+1)) - 10, size-10+offset);
    }

    /* highlight 1st square */

    _setcolor(14); /* br yellow */
    _rectangle(_GBORDER, 1, 1+offset, size, size+offset);

    /* done */

    print_status("press any key to quit");
    getch();

    _setvideomode(_DEFAULTMODE);

    puts("Ok");
    return 0;
}
