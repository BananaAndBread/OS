#include <stdio.h>
#include <string.h>
 
int main()
{
       char arr[100];
        
          printf("Enter a string to reverse\n");
          fgets(arr, 99, stdin);
              
       int size=strlen(arr);
       char temp[100];
       int j=0;
             for(int i=size-1; i>-1; i--) {
                 temp[j]=arr[i];
                 j=j+1;

             }
             temp[j]='\0';
                 
             printf("Reverse of the string is \n%s\n", temp);
                    
             return 0;
}
