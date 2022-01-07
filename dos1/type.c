#include <stdio.h>
#include "cpyfile.h"

int
main(int argc, char **argv)
{
  int item;
  FILE *fileptr;

  for (item = 1; item < argc; item++) {
    fileptr = fopen(argv[item], "r");

    if (fileptr != NULL) {
      cpyfile(fileptr, stdout);
      fclose(fileptr);
    }
  }

  return 0;
}
