#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
        int     fd[2], nbytes; /*fd[0] for read fd[1] for write*/
        pid_t   childpid; /*create childpid for fork*/
        char    string[256]; /*string that should be copied*/
        fprintf (stderr, "Enter the string\n");
        fgets(string, sizeof(string), stdin);
        char    readbuffer[80];

        pipe(fd); /*launch pipe*/
        
        if((childpid = fork()) == -1)/*if error, exit*/
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                /*if child process*/
                /* Child process closes write and only reads */
                close(fd[1]);

                /* Read in a string from the pipe */
                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                printf("Received string: %s", readbuffer);

        }
        else
        {
                /*if parent process*/
                /* Parent process closes read and only writes*/
                close(fd[0]);

                /* Send string through write */
                write(fd[1], string, (strlen(string)+1));
                exit(0);

        }
        
        return(0);
}
