#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

typedef struct {
    int inode;
    char ** filenames;
    int amount;
} equal_inode_filename;

void add_equal_inode_filename(int inode, char * filename, equal_inode_filename * arr, int * last) {
    for (int i = 0; i < *last; i++) {
        if (arr[i].inode == inode) {
            arr[i].filenames[arr[i].amount] = filename;
            arr[i].amount++;
            return;
        }
    }
    arr[*last].inode = inode;
    arr[*last].filenames = malloc(128 * 128 * 4);
    arr[*last].filenames[0] = filename;
    arr[*last].amount = 1;
    (*last)++;
}

int main() {
    mkdir("tmp", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    chdir("tmp");

    FILE * file1;
    FILE * file2;
    file1 = fopen("file1", "w");
    fclose(file1);
    file2 = fopen("file2", "w");
    fclose(file2);
    link ("file1", "link1");    

    equal_inode_filename arr[1000];
    int pp = 0;

    DIR * dirp = opendir(".");
    struct dirent * direntp = malloc(sizeof(struct dirent));
    struct stat * statp = malloc(sizeof(struct stat));
    while ((direntp = readdir(dirp)) != NULL) {
        stat(direntp->d_name, statp);
        if (statp->st_nlink >= 2) {
            add_equal_inode_filename(statp->st_ino, direntp->d_name, arr, &pp);
        }
    }

    for (int i = 0; i < pp; i++) {
        printf("inode: %d\n", arr[i].inode);
        printf("filenames:\n");
        for (int j = 0; j < arr[i].amount; j++) {
            printf("%s\n", arr[i].filenames[j]);
        }
        printf("---------------\n");
    }

    return 0;
}