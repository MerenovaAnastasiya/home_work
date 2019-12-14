#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
  FILE *rf = fopen(argv[1], "r");
  if(rf == NULL) {
    printf ("Cannot open file 1\n");
    exit(1);
  }

  FILE *wf = fopen(argv[2], "w");
  if(wf == NULL) {
    printf ("Cannot open file 2\n");
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
  struct stat st; 
  stat(argv[1], &st);
  chmod(argv[2], st.st_mode);

}
