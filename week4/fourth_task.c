#include <stdio.h>
#include <stdlib.h>
int main()
{   
    char string[20];
    
    while(1){
        printf("%s\n", "Enter a command:");
        fgets(string, 17, stdin);
        int cc = 0;
        for(int i = 0; string[i]; i++) {
            cc = i;
        }
        string[cc] = ' ';
        string[cc + 1] = '&';
        string[cc + 2] = 0;
        system(string);
    }
    return 0;
}
