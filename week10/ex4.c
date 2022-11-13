#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

char* path(struct dirent* dp, char* dirname) {
    char* path = malloc(sizeof(char) * 32);
    path = strcat(path, dirname);
    path = strcat(path, "/");
    path = strcat(path, dp->d_name);
    return path;
}

int main() {
    char* dirname = "tmp";
    DIR* dirp = opendir(dirname);
    if ( dirp == NULL ) { return 1 ; }

    struct dirent **namelist = malloc(sizeof(struct dirent) * 8);
    int i = 0;

    struct dirent *d;
    while ((d = readdir(dirp)) != NULL ) {
        namelist[i] = d;
        i++;
    }

    for (int j = 0; j < i; ++j) {
        struct dirent *dp = namelist[j];

        struct stat buff;
        stat(path(dp, dirname), &buff);

        if (strcmp(dp->d_name,".") != 0 && strcmp(dp->d_name,"..") != 0) {
            if (buff.st_nlink > 1) {

                printf("%s %ld (inum=%ld)\n", path(dp, dirname), buff.st_nlink, buff.st_ino);
                printf("\tFiles with the same inumber:\n");
                for (int k = 0; k < i; ++k) {
                    struct dirent *dpk = namelist[k];
                    struct stat buff2;
                    stat(path(dpk, dirname), &buff2);
                    if (buff.st_ino == buff2.st_ino && strcmp(dp->d_name, dpk->d_name) != 0) {
                        printf("\t\t%s\n", dpk->d_name);
                    }
                }
            }
        }
    }
}