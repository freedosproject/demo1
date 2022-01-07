#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* time function */

int
main()
{
    int randnum; /* between 1 and 100 */
    int guess; /* the user's guess */

    /* pick a random number */

    srand( time(NULL) );
    randnum = (rand() % 100) + 1;

    /* guess the random number */

    puts("Pick a number between 1 and 100");

    do {
	scanf("%d", &guess);

	/* give feedback */

	if (guess < randnum) {
	    puts("Too low");
	}
	else if (guess > randnum) {
	    puts("Too high");
	}
    } while (guess != randnum);

    puts("That's right!");

    return 0;
}

