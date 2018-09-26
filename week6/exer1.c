#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main(void){
    int     fd[2], nbytes; /*fd[0] for read fd[1] for write*/
    char    string[256]; /*string that should be copied*/
    char    readbuffer[80];/*buffer for input*/
    pipe(fd);
    fprintf (stderr, "Enter the string\n");
    fgets(string, sizeof(string), stdin);
    write(fd[1], string, (strlen(string)+1));


  
   
    nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
     fprintf (stderr, "It happened after\n");

    fprintf(stderr,"Received string: %s", readbuffer);

return 0;
 }
