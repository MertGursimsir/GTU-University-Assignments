#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    float number;
    char* name;
    struct node *next;
};

int global = 0;

void insert_end(struct node **head, int val, float num, char* name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}

void printList_withLoop(struct node *head)
{
    //iterate the entire linked list and print the data with loop
    while (head!=NULL){
    	printf("%d->%f->%s,",head->data, head->number,head->name);
    	printf("\n");
    	head=head->next;
    }

}
void printList_withRecursive(struct node *list) {
   //iterate the entire linked list and print the data with recursive
	if (list!=NULL){
		if (list->next == NULL){
			printf("%d->%f->%s", list->data, list->number,list->name);
			printf("]");
		}
		else{
			if (global == 0){
				printf("[%d->%f->%s, ", list->data, list->number,list->name);
				global++;
			}
			else printf("%d->%f->%s, ", list->data, list->number,list->name);
			
		}
		printList_withRecursive(list->next);
	}
}


void sortedInsert(struct node** head_ref, struct node* new_node)
{

   // Sort according to string into the node struct.
   // It's name is "name".
   // You will sort ascending order.
	int temp_data;
	float temp_number;
	char* temp_name;
	int counter = 0;
	struct node* temp_node = *head_ref;

	/*while (temp_node->next!=NULL){
		if(strcmp(temp_node->name, temp_node->next->name) > 0){
			temp_name = temp_node->name;
			temp_node->name = temp_node->next->name;
			temp_node->next->name = temp_name;

			temp_number = temp_node->number;
			temp_node->number = temp_node->next->number;
			temp_node->next->number = temp_number;

			temp_data = temp_node->data;
			temp_node->data = temp_node->next->data;
			temp_node->next->data = temp_data;		
		}
		temp_node = temp_node->next;
	}
	temp_node=*head_ref;*/
	while (temp_node != NULL){
		if (strcmp(temp_node->name, new_node->name) > 0){
			new_node->next = temp_node;
			temp_node = new_node;
			if (counter == 0) *head_ref = temp_node;
			break;
		}
		counter++;
		temp_node = temp_node->next;
	}
	if (temp_node == NULL){
		temp_node = new_node;
		new_node->next = NULL;
	}
}


/* A utility function to create a new node */
struct node* newNode(int new_data, float num, char* name_)
{
    /* allocate node */
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
 	new_node -> name = (char*)malloc(20*sizeof(char));
    /* put in the data  */
	new_node->data=new_data;
	new_node->number=num;
	strcpy(new_node->name, name_);
	new_node->next = NULL;

	return new_node;
}


bool search(struct node* head, int x)
{
    // Search according to "data" which defined in node struct.
	// You will control x number comparision with "data" which struct element.
	int flag = 0;
	while (head!=NULL && !flag){
		if (head->data == x) flag=1;
		head = head->next;
	}
	if (flag == 1) return true;
	else return false;
}

int main()
{
     struct node *head = NULL;

     insert_end(&head,10,5.5,"hello1");
     insert_end(&head,20,5.5,"hello2");
     insert_end(&head,30,5.5,"hello3");

     printf("Print List with Loop: \n");
     printList_withLoop(head);
     
     struct node* new_node = newNode(1,5.5, "a");
     sortedInsert(&head, new_node);

     
     new_node = newNode(3,5.5, "c");
     sortedInsert(&head, new_node);

     
     new_node = newNode(2,5.5, "d");
     sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "b");
     sortedInsert(&head, new_node);
     printf("%d\n", new_node->data);

     printf("Print List with Recursive: \n");
     printList_withRecursive(head);
	 
	 printf("\nIs 20 belong this linked list?: " );
     printf(search(head, 20) ? "YES \n" : "NO \n");
     
     printf("\nIs 18 belong this linked list?: " );
     printf(search(head, 18) ? "YES \n" : "NO \n");


     return 0;
}