#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
int main(){
    int byte_count = 20;
    char data[20];
    FILE *fp;

    fp = fopen("/dev/urandom", "r");
    fread(data, 1, byte_count, fp);
    fclose(fp);
    fp = fopen("./ex1.txt", "w");
    fwrite(data, 1, 20, fp);
    fclose(fp);
}