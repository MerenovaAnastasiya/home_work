#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE *fp;
  char ch;
  if((fp=fopen(argv[1], "w"))==NULL) {
    printf ("Cannot open file.\n");
    exit(1);
  }

  while(1) {
    char c = getc(stdin);
    if(c!=27) {
      fputc(c, fp);
    }
    else {
      fclose(fp);
      exit(0);
    }
  }
}