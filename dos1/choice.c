#include <stdio.h>
#include <conio.h>

int
main(int argc, char **argv)
{
  int item;
  int key;

  if (argc == 1) {
    fputs("yn? ", stdout);
  }
  else {
    for (item = 1; item < argc; item++) {
      fputs(argv[item], stdout);
      putchar(' ');
    }
  }

  fflush(stdout);

  do {
    key = getch();
  } while ((key != 'y') && (key != 'n'));

  putchar(key);
  putchar('\n');

  if ((key == 'y') || (key == 'Y')) {
    return 1;
  }
  if ((key == 'n') || (key == 'N')) {
    return 2;
  }
  return 0;
}
