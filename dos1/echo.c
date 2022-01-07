#include <stdio.h>

int
main(int argc, char **argv)
{
  int item;

  for (item = 1; item < argc; item++) {
    fputs(argv[item], stdout);
    putchar(' ');
  }

  putchar('\n');

  return 0;
}
