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
int num_file = 0, num_dir = 1;

int main(int argc, char* argv[]) {
    filename = argv[2];
    fname = argv[2];
    get_dir(argv[1]);
    printf("Directories checked: %d\n", num_dir);
    printf("Files checked: %d\n", num_file);
    return 0;
}

void print_info(char* path) {
    FILE* fp;
    struct stat buff;
    stat(path, &buff);
    printf("File path: %s \n", path);
    printf("File name: %s \n", fname);
    printf("Size: %lld \n", buff.st_size);
    printf("Create date:  %s", asctime(gmtime(&buff.st_ctime)));
    printf("Access: ");
    printf((S_ISDIR(buff.st_mode)) ? "d" : "-");
    printf( (buff.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buff.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buff.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buff.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buff.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buff.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buff.st_mode & S_IROTH) ? "r" : "-");
    printf( (buff.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buff.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("Inode number: %lld \n", buff.st_ino);
}

void get_dir(char* dir) {
    struct dirent* d;
    DIR* dp;
    if ((dp = opendir(dir)) == NULL)
    {
        printf("Cannot open dir %s\n", dir);
        return;
    }
    while ((d = readdir(dp)) != NULL) {
        char path[1024];
        char buf[200];
        if (d->d_type == DT_DIR) {
            if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
                continue;
            if (strcmp(dir, "/") == 0) { 
                snprintf(path, sizeof(path), "/%s", d->d_name);
            }
            else {
                snprintf(path, sizeof(path), "%s/%s", dir, d->d_name);
            }
            num_dir++;
            get_dir(path);
        }
        else {
            num_file++;
            if (strcmp(d->d_name, filename) == 0) {
                snprintf(path, sizeof(path), "%s/%s", dir, d->d_name);
                print_info(path);
            }
        }
    }
    closedir(dp);
}

