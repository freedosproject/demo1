#include <stdio.h>

unsigned long
cpyfile(FILE * in, FILE * out)
{
  int ch;
  unsigned long count = 0;

  while ((ch = fgetc(in)) != EOF) {
    fputc(ch, out);
    count++;
  }

  return count;
}
