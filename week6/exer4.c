#include <stdio.h>
#include <signal.h>
void notify()
{
  printf("You are user and you are notified");


}
int main(){
    signal(SIGINT, notify);
    signal(SIGSTOP, notify);
    signal(SIGUSR1, notify);
    sleep(50);
    return 0;
}

