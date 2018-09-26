#include <stdio.h>                               
#include <signal.h>
void notify()
{
  printf("You are user and you are notified");
 
 
}
int main(){
    signal(SIGINT, notify);
    sleep(10);
    return 0;
}


