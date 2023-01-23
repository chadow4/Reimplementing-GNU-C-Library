#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include "mini_lib.h"


void checkDirectory(DIR *directory) {
    struct dirent *directory_entry = mini_calloc(sizeof(struct dirent), 1);
    struct stat *statsInfos = mini_calloc(sizeof(struct stat), 1);
    struct passwd *pwd = mini_calloc(sizeof(struct stat), 1);
    struct group *grp = mini_calloc(sizeof(struct stat), 1);

    while ((directory_entry = readdir(directory)) != NULL) {
        if (stat(directory_entry->d_name, statsInfos) == 0) {
            pwd = getpwuid(statsInfos->st_uid);
            grp = getgrgid(pwd->pw_gid);

            printf((S_ISDIR(statsInfos->st_mode)) ? "d" : "-");
            printf((statsInfos->st_mode & S_IRUSR) ? "r" : "-");
            printf((statsInfos->st_mode & S_IWUSR) ? "w" : "-");
            printf((statsInfos->st_mode & S_IXUSR) ? "x" : "-");
            printf((statsInfos->st_mode & S_IRGRP) ? "r" : "-");
            printf((statsInfos->st_mode & S_IWGRP) ? "w" : "-");
            printf((statsInfos->st_mode & S_IXGRP) ? "x" : "-");
            printf((statsInfos->st_mode & S_IROTH) ? "r" : "-");
            printf((statsInfos->st_mode & S_IWOTH) ? "w" : "-");
            printf((statsInfos->st_mode & S_IXOTH) ? "x" : "-");

            printf(" %ld", statsInfos->st_nlink);

            printf(" %s", pwd->pw_name);

            printf(" %s", grp->gr_name);

            printf(" %ld", statsInfos->st_size);

            printf(" %s\n", directory_entry->d_name);
        }
    }
}

int main(int argc, char **argv) {

    DIR *directory;

    if (argc != 3) {
        mini_printf("Error: number of arguments invalid\n");
    }


    directory = opendir(argv[2]);


    checkDirectory(directory);


    return 0;

}