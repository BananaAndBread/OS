#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_PROC 5
#define NUM_OF_RES 3

void read_file(int matrix1[][NUM_OF_RES], int matrix2[][NUM_OF_RES], int *exist, int* avail){
    //read file
    //existing resources in exist
    //available resources in avail
    //store current allocation matrix by address of matrix1
    //store request matrix by address of matrix2
    FILE *f;
    f = fopen("./input.txt", "r");
    for(int i=0; i<NUM_OF_RES; i++){
        fscanf(f, "%d", &exist[i]);
    }
    for(int i=0; i<NUM_OF_RES; i++){
        fscanf(f, "%d", &avail[i]);
    }


    for(int i =0; i<NUM_OF_PROC; i++){
        for(int j=0; j<NUM_OF_RES; j++){
            fscanf(f, "%d", &matrix1[i][j]) ;
        }

    }
    for(int i =0; i<NUM_OF_PROC; i++){
        for(int j=0; j<NUM_OF_RES; j++){
            fscanf(f, "%d", &matrix2[i][j]) ;
        }

    }

}

void execute(int * avail, int matrix2[][NUM_OF_RES], int matrix1[][NUM_OF_RES]){
    int num_of_satisfied_proc =0;
    int prev_num_of_satisfied_proc = -1;
    int a[NUM_OF_PROC];
    for (int i = 0; i < NUM_OF_PROC; i++) {
        a[i] = 0;
    }
    //End cycle when we satisfied all processes or when the number of satisfied processes is the same with
    //the previous step(deadlock)

    //When we have enough resources to satisfy the process, we satisfy it and it gives us resources
    while(num_of_satisfied_proc < NUM_OF_PROC && num_of_satisfied_proc!=prev_num_of_satisfied_proc){
        prev_num_of_satisfied_proc = num_of_satisfied_proc;
        for(int i =0; i<NUM_OF_PROC; i++){
            if (a[i]) continue;
            int can_satisfy_all_res = 1;
            for(int j=0; j<NUM_OF_RES; j++){
                if (matrix2[i][j] > avail[j]) {
                    can_satisfy_all_res = can_satisfy_all_res * 0;
                }
                
            }
            if (can_satisfy_all_res) {
                a[i] = 1;
                num_of_satisfied_proc = num_of_satisfied_proc+1;
                for (int k=0; k<NUM_OF_RES; k++) {
                    avail[k] = avail[k] + matrix1[i][k];
                    matrix1[i][k] = 0;
                }
            }
            
        }
    }
        if(num_of_satisfied_proc==NUM_OF_PROC){
            printf("processes are ok");            
        }
        else{
            printf("processes are deadlocked");
        }
        
        
}

int main(){

    int A[NUM_OF_PROC][NUM_OF_RES];
    int B[NUM_OF_PROC][NUM_OF_RES];
    int avail[NUM_OF_RES];
    int exist[NUM_OF_RES];

    read_file(A, B,  exist,  avail);
    execute(avail, B, A);


} 
