#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/timeb.h>

int main(int argc, char const *argv[])
{    
	time_t t = time(NULL);
	struct tm local = *localtime(&t);
    pid_t pid_1, pid_2;

    if(pid_1 = fork())
        pid_2 = fork();

    if (pid_2 == 0 || pid_1 == 0)
    {
        printf("%d %d [%d:%d:%d]\n", getpid(), getppid(),
            local.tm_hour, local.tm_min, local.tm_sec);
    }
    else
        printf(
            "%d [%d:%d:%d]\n",
            getpid(),
            local.tm_hour, local.tm_min, local.tm_sec);
    system("ps -x ");
    return EXIT_SUCCESS;
}
