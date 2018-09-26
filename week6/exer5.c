#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

int main(){
    pid_t childpid;
    childpid = fork();
    if(childpid!=0){
    sleep(10);
    kill(childpid, SIGKILL);
    }
    if(childpid==0){
        while(1){
            fprintf(stderr,"I am alive");
            
            sleep(1);
        }
    }
    return 0;
}
