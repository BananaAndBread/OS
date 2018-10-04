#include <stdio.h>
#include <stdlib.h>
//I do not know what this code is supposed to do but i fixed is, as it does not produce segmentation fault anymore
int main() {
    char **s=malloc(sizeof(char*));;
    char foo[] = "Hello World";
    *s = foo;            
    printf("s is %s\n", s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    printf("s is %s\n", s);
    return 0;
}
