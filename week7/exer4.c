#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

//function to copy only part that is in need
size_t find_min(size_t a, size_t b) {
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

void * my_realloc(void *ptr, size_t old_size, size_t new_size) {
    if (!ptr && !new_size) return NULL;
    void *new_ptr;
    if (new_size) {
        new_ptr = malloc(new_size);
        if (ptr) {
            memcpy(new_ptr, ptr, find_min(new_size, old_size));
        }
    }
    if (ptr) {
        free(ptr);
    }

    return new_ptr;
}
//main is from the previous task except for the realloc, just to check that my_realloc works correctly
int main(){

	//Allows you to generate random number
	//?
	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = (int*) malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		*(a1 + i) =100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", *(a1 + i) );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");//?
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = my_realloc(a1, sizeof(int)*n1, sizeof(int)*n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
    if(n2>n1){
        for(int i = n1; i<n2; i++){
            *(a1 + i) = 0;
        }
    }

	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", *(a1 + i));
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
