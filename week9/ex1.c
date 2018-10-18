#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct frame {
    int page;
    unsigned char counter;
};

int find_min(struct frame *frames, int size) {
    unsigned char min = frames[0].counter;
    int min_index = 0;
    for (int i = 0; i < size; i++) {
        if ((frames[i].counter < min) || frames[i].page == 0) {
            min = frames[i].counter;
            min_index = i;
        }
    }
    return min_index;
}

int if_found_in_paging_system(int page_number, struct frame *frames, int size){
    for (int i = 0; i < size; i++) {
        if (frames[i].page == page_number) {
            return i;
        }
    }
    return -1;
}

int put_into_paging_system(int page_number, struct frame *frames, int size) {
    int hit = 1;
    int result_of_function = if_found_in_paging_system(page_number, frames, size);

    for (int i = 0; i < size; i++) {
        frames[i].counter = (frames[i].counter >> 1u);     
    }

    if (result_of_function != -1) {
        frames[result_of_function].counter = (frames[result_of_function].counter | (unsigned char) (1<<7U));
    } else {
        int index_for_new = find_min(frames, size);
        frames[index_for_new].counter = (unsigned char) (1 << 7U);
        frames[index_for_new].page = page_number;
        hit = 0;
    }

    return hit;
}



int main(){
    int num;
    scanf("%d", &num);
    struct frame *array = (struct frame*) malloc(num * sizeof(struct frame));
    memset(array, 0, num * sizeof(struct frame));
    FILE *fp;
    int pageNumber;
    int hits = 0;
    int misses = 0;
    fp = fopen("./Lab 09 input.txt", "r");
    while (fscanf(fp, "%d", &pageNumber) != EOF) {
        int hit = put_into_paging_system(pageNumber, array, num);
        if (hit) {
            hits = hits + 1;
        } else {
            misses = misses + 1;
        }
    }
    printf("%d %d\n", hits, misses);


    return 0;
}
