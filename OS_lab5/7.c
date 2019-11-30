#include <stdio.h>
#include <dirent.h> 

int main(int argc, char* argv[]) {

	DIR *dr = opendir(argv[1]); 
    if (dr == NULL)
    { 
        printf("Could not open current directory" ); 
        return 0; 
    }
   	struct dirent *de; 
    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(dr);     
    return 0; 
}

char* search(char* path) {
    if path == null {
        path = ".";
    }
    DIR *dr = opendir(path);
    struct dirent *dir;
    if (dr == NULL)
    { 
        printf("Could not open current directory" ); 
        return 0; 
    }
    FILE *f; 
    while((f = fopen()))
    struct dirent *dir;
    while ((dir = readdir(dr)) != NULL) {
      printf("%s\n", dir->d_name);
    }

}