#include <stdio.h>
typedef struct node
  {
    int data;
    struct node *next;
  } node;	
struct node *head = NULL;
struct node *current = NULL;
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
   while (ptr->next != NULL) {
      ptr = ptr->next;
      printf("(%d) ",ptr->data);
   }
	
   printf(" ]");
 }

void insert_node(int data, int index)
{
    node * cursor = head;
    
    for(int i=0; i<index; i++){
        cursor = cursor->next;
    }
    /* create a new node */
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    cursor->next = new_node;
}
void delete_node(int index)
{
    node * cursor = head;

    for(int i=0; i<index; i++){
        cursor = cursor->next;
    }
    /* create a new node */
    node ** deleted_node =&cursor->next;
    *deleted_node=(*deleted_node)->next;
    
}

int main(){
	head = (node*) malloc(sizeof(node));
	head->next = NULL;

	insert_node(1, 0);
	insert_node(2, 1);
	insert_node(3, 2);
	delete_node(1);

	printList();
}
