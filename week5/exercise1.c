#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

 
#define ERROR_CREATE_THREAD -11
#define ERROR_JOIN_THREAD   -12
#define BAD_MESSAGE         -13
#define SUCCESS               0
 
typedef struct someArgs_tag {
    int id;
} someArgs_t;
 
void* helloFromThread(void *args) {
    someArgs_t *arg = (someArgs_t*) args;

    printf("%s%d\n", "Hello from thread ", arg->id);
 
    return SUCCESS;
}
 
int main() {

    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);
    
    pthread_t threads[num_threads];
    int status;
  
    someArgs_t args[num_threads];
 
    for (int i = 0; i < num_threads; i++) {
        args[i].id = i;
    }
 
    for (int i = 0; i < num_threads; i++) {
        status = pthread_create(&threads[i], NULL, helloFromThread, (void*) &args[i]);
        if (status != 0) {
            printf("main error: can't create thread, status = %d\n", status);
            exit(ERROR_CREATE_THREAD);
        }
        status = pthread_join(threads[i], NULL);
        if (status != SUCCESS) {
            printf("main error: can't join thread, status = %d\n", status);
            exit(ERROR_JOIN_THREAD);
        }
    }
 
    printf("Main Message\n");
 
    return 0;
}
