#include <stdio.h>

int main(int argc, char** argv){
    int m;
    sscanf(argv[1], "%d", &m);
    int spaces=((2*m-1)/2);
    int dots = 1;
    for(int i=0; i<m; i++){
        for(int i=0; i<spaces; i++){
            printf("%s", " ");
        }
        for(int i=0; i<dots; i++){
            printf("%s", "*");
        }
        printf("%s", "\n");
        dots = dots + 2;
        spaces = spaces - 1;
    }
    return 0;
}
