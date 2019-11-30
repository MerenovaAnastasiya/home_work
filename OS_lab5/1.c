  
#include <stdio.h>

int main(int argc, char *argv[])
{
	char s[] = {'h', 'e', 'l', 'l', 'o'};
	for(int i = 0; i < sizeof(s); i ++) {
		putc(s[i], stdout);
	}
    return 0;
}