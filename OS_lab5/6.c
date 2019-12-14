#include <stdio.h>
#include <dirent.h> 

int main(int argc, char* argv[]) {
    DIR *current_dir = opendir("./"); 
    if (current_dir == NULL)
    { 
        printf("Could not open current directory" ); 
        return 0; 
    }
    struct dirent *de; 
    printf("files in current directory:\n");
    while ((de = readdir(current_dir)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(current_dir); 



    DIR *dr = opendir(argv[1]); 
    if (dr == NULL)
    { 
        printf("Could not open desired directory" ); 
        return 0; 
    }

    printf("files in current directory:\n");

    while ((de = readdir(dr)) != NULL) 
            printf("%s\n", de->d_name); 
  
    closedir(dr);     
    return 0; 
}
