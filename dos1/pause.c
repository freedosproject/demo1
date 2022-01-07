#include <stdio.h>
#include <conio.h>

int
main(int argc, char **argv)
{
  int item;

  if (argc == 1) {
    fputs("Press any key to continue..", stdout);
  }
  else {
    for (item = 1; item < argc; item++) {
      fputs(argv[item], stdout);
      putchar(' ');
    }
  }

  fflush(stdout);

  getch();

  putchar('\n');

  return 0;
}
