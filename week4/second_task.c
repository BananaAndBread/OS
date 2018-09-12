#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  int n=5;
 
for(int i=0; i<3; i++){
    fork();
    sleep(5);
}
/*
 *Total Number of Processes = 2n where n is number of fork system calls. It is 8 here.
 */
    return 0;
}

