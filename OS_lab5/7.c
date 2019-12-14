#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <time.h>
#include <libgen.h>


char* fname = NULL;
void get_dir(char* dir);
void print_info(char* path);
char* filename;
int count_file = 0, count_dir = 1;

int main(int argc, char *argv[])
{
	filename = argv[2];
	get_dir(argv[1]);

}

void get_dir(char* dir) {
	//содержит информацию о файлах в директории
	struct dirent* d;

	DIR* dp;
	if ((dp = opendir(dir)) == NULL)
    {
        printf("Cannot open dir %s\n", dir);
        // exit(1);
    }
    while ((d = readdir(dp)) != NULL) {
    	char path[1024];
        char buf[200];
         //проверяем, каталог ли это
        if (d -> d_type == DT_DIR) { 
            if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
            	continue;
            if (strcmp(dir, "/") == 0) { 
                snprintf(path, sizeof(path), "/%s", d->d_name);
            }
            else {
                snprintf(path, sizeof(path), "%s/%s", dir, d->d_name);
            }
            count_dir++;
            // вызываем рекурсивно
            get_dir(path);
        }
        else {
            count_file++;
            //cравнивает названия
            if (strcmp(d->d_name, filename) == 0) {
                snprintf(path, sizeof(path), "%s/%s", dir, d->d_name);
                print_info(path);
            }
        }
    }
}

void print_info(char* path) {
	FILE* fp;
	//информация о файле
    struct stat buff;
    stat(path, &buff);
    printf("Path to file:  %s \n", path);
    printf("Name:  %s \n", filename);
    printf("Size %lld \n", buff.st_size);
    printf("Create date %s", asctime(gmtime(&buff.st_ctime)));
    printf("Access: %3o\n", buff.st_mode);
}

