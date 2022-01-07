#include <stdio.h>
#include <conio.h>
#include <graph.h>

int
isodd(int n)
{
    return (n & 1);
}

int
main()
{
    int color;
    int xres, yres;

    if (! _setvideomode(_VRES16COLOR) ) {
	fputs("Cannot set video mode\n", stderr);
    }

    xres = 640;
    yres = 480;

    /* border test */

    _setcolor(15); /* br white */
    _rectangle(_GBORDER, 0, 0, xres-1, yres-1);

    _setcolor(7); /* white */
    _moveto(200, 220);
    _outgtext("press any key to start the test ...");

    getch();

    /* color test */

    for (color = 0; color < 8; color++) {
	_setcolor(color); /* color 0-7 */
	_rectangle(_GFILLINTERIOR, (xres/8)*color, 0, xres-1, yres-1);

	_setcolor(color+8); /* bright colors 8-15 */
	_rectangle(_GFILLINTERIOR, (xres/8)*color, yres/2, xres-1, yres-1);

	_setcolor( (isodd(color) ? 0 : 15) ); /* black & br white */
	_rectangle(_GFILLINTERIOR, (xres/8)*color, (yres/2)-20,
	    xres, (yres/2)+20);
    }

    getch();

    _setvideomode(_DEFAULTMODE);

    puts("ok");
    return 0;
}
