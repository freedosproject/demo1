#include <stdio.h>
#include "cpyfile.h"

int
main(int argc, char **argv)
{
  FILE *in, *out;

  /* check args */

  if (argc != 3) {
    fputs("usage: COPY source dest\n", stderr);
    return 1;
  }

  /* open files and copy */

  in = fopen(argv[1], "r");

  if (in == NULL) {
    fprintf(stderr, "COPY: Cannot read file %s\n", argv[1]);
    return 2;
  }

  out = fopen(argv[2], "w");

  if (out == NULL) {
    fprintf(stderr, "COPY: Cannot write to file %s\n", argv[2]);
    fclose(in);
    return 3;
  }

  cpyfile(in, out);
  fclose(in);
  fclose(out);

  return 0;
}
