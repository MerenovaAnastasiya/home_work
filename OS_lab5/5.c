#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE *rf;
  if((rf=fopen(argv[1], "r"))==NULL) {
    printf ("Cannot open file.\n");
    exit(1);
  }

  FILE *wf;
  if((wf=fopen(argv[2], "w"))==NULL) {
    printf ("Cannot open file.\n");
    exit(1);
  }


  while(1) {
    char c = fgetc(rf);
         if ( feof (rf) != 0)
         {  
            fclose(rf);
            fclose(wf);
            exit(0);
         }
    
      fputc(c, wf);
    }

}
