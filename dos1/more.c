#include <stdio.h>
#include <conio.h>

void
showfile(FILE * in, int mxlines)
{
  int ch;
  int col = 0;
  int lines = 0;

  while ((ch = fgetc(in)) != EOF) {
    putchar(ch);

    /* increment the column */

    if (ch == '\t') {                  /* tab */
      col += 8;                        /* this is an approximation to make this simpler */
    }
    else {
      col++;
    }

    /* did we wrap lines? */

    if (col >= 80) {                   /* max screen columns */
      col = 0;
      lines++;
    }

    if (ch == '\n') {                  /* newline */
      col = 0;
      lines++;
    }

    /* are we at the bottom of the screen? */

    if (lines >= mxlines) {
      fputs(">> MORE <<", stdout);
      fflush(stdout);
      getch();
      putchar('\n');
      lines = 0;
    }
  }                                    /* while */
}

int
main()
{
  showfile(stdin, 24);

  return 0;
}
