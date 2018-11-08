#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char* argv[]){
    FILE *fp;
    FILE *fp2;
    char data[20];
    fp = stdin;
   
    if ((strcmp(argv[1], "-a"))==0){
         fp2 = fopen(argv[2], "wa");
    }
    else{
       fp2 = fopen(argv[1], "wa"); 
    }
    int _;
    while(_=fread(data, 1, 20, fp)){
        fwrite(data, 1 ,_, stdout);
        fwrite(data, 1, _, fp2);
    }
    fclose(fp2);
}