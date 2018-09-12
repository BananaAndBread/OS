#include <stdio.h>
#include <stdlib.h>
int main()
{   
    char string[20];
    while(1){
    printf("%s\n", "Enter a command:");
    fgets(string, 19, stdin);
    system(string);
    }
    return 0;
}
