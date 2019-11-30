#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

	FILE *fp;
  	if((fp=fopen(argv[1], "r"))==NULL) {
    	printf ("Cannot open file.\n");
    	exit(1);
  	}

	int n = atoi(argv[2]);
	char x = (char) n;
	putc(x, stdout);
	// putc('1', stdout);
	int count;
	int len = 1000;
   

    while(1) {
    	if(feof (fp) != 0) {
    		fclose(fp);
    	}
    	return 0;
    	int count = 0;
    	char* s = malloc(len * sizeof(char));
    	int i = 0;
		while(count < n && feof (fp) == 0) {
			char ch = getc(stdin);
			if(ch == 27) {
				exit(0);
			}
			if(ch == '\n') {
				count++;
			}
			s[i] = ch;
			i++;
		}
		for(int j = 0; j < sizeof(s); j++) {
			putc(s[j], stdout);
		}
	}
	

}