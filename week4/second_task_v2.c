#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  int n=5;

for(int i=0; i<5; i++){
    fork();
    sleep(5);
}
//now it is 32
    return 0;
}

