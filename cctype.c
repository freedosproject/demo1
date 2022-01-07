

#include <stdio.h>

void
showctrlchars(FILE *pfile)
{
    int ch;

    /* loop through the file one ch at a time */

    while ((ch = fgetc(pfile)) != EOF) {
        /* ASCII reserves 0-31 as ctrl codes */
        if (ch == '\n') {
            /* print newline */
            putchar(ch);
        }
        else if (ch < 32) {
            /* print the ctrl code */
            printf("<%d>", ch);
        }
        else {
            /* print the character */
            putchar(ch);
        }
    }
}

int
main(int argc, char **argv)
{
    FILE *pfile;
    int iter;

    /* scan each arg as a file */

    for (iter = 1; iter < argc; iter++) {
        pfile = fopen(argv[iter], "r");

        if (pfile) {
            showctrlchars(pfile);
            fclose(pfile);
        }
    }

    /* if no args, then read stdin */

    if (argc == 1) {
        showctrlchars(stdin);
    }

    /* done */

    return 0;
}

