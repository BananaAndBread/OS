#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
int main(){
    printf("I am in main");
    pid_t childFirst;
    pid_t  childSecond;
    int fd[2];
    int nbytes;
    pipe(fd);
    childFirst = fork();
    if(childFirst==0){
        int temp;
        close(fd[1]);
       /* Read in a string from the pipe */
        nbytes = read(fd[0], &temp, sizeof(temp));

        printf("Received pid: %d\n", temp);
        
        kill(temp, SIGSTOP);
        waitpid(temp);
        exit(0);
        for (;;) {
            // first child
        }
    }
    childSecond = fork();
    if(childSecond==0){
        printf("I have send my pid%d\n", getpid());
        close(fd[0]);
        int pid = getpid();
        write(fd[1], &pid, sizeof(pid));
        
        for (;;) {
            printf("They are going to stop me\n");

        }
    }

    return 0;

}
