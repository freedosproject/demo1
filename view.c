#include <stdio.h>
#include <conio.h>
#include <graph.h>

int pause(const char *str)
{
    int key;

    _settextcolor(15); /* br wh */
    _setbkcolor(3); /* cyan */
    _settextwindow(25,1, 25,80);
    _clearscreen(_GWINDOW);

    _settextposition(25,1);
    _outtext(str);

    /* get key from keyboard */

    key = getch();

    if (key == 0) {
	/* ext key, call getch one more time */
	getch();
    }

    return key;
}

void cls(void)
{
    _settextcolor(7); /* white */
    _setbkcolor(1); /* blue */
    _settextwindow(1,1, 25,80);
    _clearscreen(_GWINDOW);
}

void view(FILE *in, const char *name)
{
    /* read the file one line at a time, and display to the screen.
	after 24 lines, pause and wait for the user to press a key */

    char text[80];
    int line = 1;

    /* read all lines, print to the screen */

    cls();

    while ((fgets(text, 80, in)) != NULL) {
	_settextposition(line, 1);
	_outtext(text);

	line++;
	if (line == 25) {
	    if (pause(name) == 27) { /* 27 is Esc */
		return; /* quit early */
	    }

	    /* else */

	    cls();
	    line = 1;
	}
    } 

    pause("[end]");

    return;
}

int main(int argc, char **argv)
{
    FILE *pfile;
    int i;

    /* set video mode */

    if (_setvideomode(_TEXTC80) == 0) {
	fputs("cannot set video mode", stderr);
	fputc('\n', stderr);
	return 1;
    }

    /* read the files */

    for (i = 1; i < argc; i++) {
	pfile = fopen(argv[i], "r");
	if (pfile) {
	    view(pfile, argv[i]);
	    fclose(pfile);
	}
	/* for a basic view program, we won't print error messages */
    }

    /* done */

    _setvideomode(_DEFAULTMODE);

    return 0;
}
