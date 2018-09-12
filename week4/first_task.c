#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
int main() 
{ 
  int n=5;
    pid_t pid = fork(); 
if (pid == 0) { 
	printf("hello from child\n");
       printf("My pid:%d\n", getpid());
       printf("%d\n", n);
} 
else {  
	printf("hello from parent\n"); 
	printf("My pid:%d\n", getpid());
	printf("%d\n", n);

} 
    return 0; 
} 
