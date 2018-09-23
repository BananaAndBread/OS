#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000000

int buf_ptr = 0;
char empty = 1, full = 0;

void* produce(void* p) {
    for (int i = 0; i < MAX; i++) {
        if (full) continue;
        if (i % 1000 == 0) {
            printf("producer %d\n", i);
        }
        buf_ptr++;
        empty = 0;
        if (buf_ptr == MAX / 10000) {
            full = 1;
        }
    }

    pthread_exit(0);
}

void* consume(void* p) {
    while (1) {
        if (empty) continue;
        buf_ptr--;
        full = 0;
        if (buf_ptr == 0) {
            empty = 1;
        }
    }
}

int main() {
    pthread_t producer, consumer;

    pthread_create(&consumer, NULL, consume, NULL);
    pthread_create(&producer, NULL, produce, NULL);

    pthread_join(consumer, NULL);
    pthread_join(producer, NULL);
}
