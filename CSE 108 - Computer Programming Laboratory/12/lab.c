#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node_list
{
    int data;
    float number;
    char* name;
    struct node_list *next;
};

/*Do not modify the following function.*/

void insert_end(struct node_list **head, int val, float num, char* name_)
{ 
    struct node_list *newnode = malloc(sizeof(struct node_list));
    newnode->data = val;
    newnode->number = num;
    newnode->name = name_;
    newnode->next = NULL;

    if(*head == NULL)
 		*head = newnode;
    else
    {
        struct node_list *lastnode = *head;

        while(lastnode->next != NULL)
			lastnode = lastnode->next;

        lastnode->next = newnode;
    }
}

/*Do not modify the following function.*/

void print_list(struct node_list *head)
{
	struct node_list *temp = head;

    while(temp != NULL)
    {
		printf("%d->", temp->data);
		printf("%lf->", temp->number);
		printf("%s", temp->name);
		printf("\t");
		temp = temp->next;
    }
    
    printf("NULL\n\n");
}

/*Do not modify the following function.*/

void print_array(struct node_list *array, int sizeof_array)
{
	int i;
	
	for(i=0;i<sizeof_array;i++)
	{
		printf("%d->", (array+i)->data);
    	printf("%lf->", (array+i)->number);
		printf("%s", (array+i)->name);
		printf("\t");
	}
		
    	printf("NULL\n\n");
}

/*You can modify following functions.*/

struct node_list* merge_list(struct node_list* head_1, struct node_list* head_2)
{
	/*You can modify the entire body of the function including the return statement one line below.*/
	struct node_list *temp = head_1;	/* temporary value to hold head_1 */
	if (head_1 == NULL) head_1 = head_2;/* if head_1 is NULL, head_2 is what we need */
	else if (head_2 != NULL){
		while (temp->next != NULL){	/* finding end */
			temp = temp->next;
		}
		temp->next = head_2;	/* insert head_2 to the end of head_1 */
	}
	return head_1;
}

struct node_list* merge_interleaved(struct node_list* head_1, struct node_list* head_2)
{
	/*You can modify the entire body of the function including the return statement one line below.*/

	struct node_list *temp = head_1; /* defining temporary nodes */
	struct node_list *buff;
	struct node_list *prev;
	if (head_1 == NULL) head_1 = head_2; /* if head_1 is NULL, head_2 is what we need */
	else if (head_2 != NULL){
		while (head_2 ->next != NULL){
			prev = head_2->next;	/* temporary value to hold next node's address for head_2 */
			buff = temp->next;		/* temporary value to hold next node's address for head_1 */
			temp -> next = head_2;	/* assigning values */
			head_2->next = buff;

			head_2 = prev;	/* changing nodes */
			temp = buff;
			/*if(temp->next == NULL) temp->next = head_2;*/
		}
	}

	return head_1;
}

struct node_list* merge_array(struct node_list* a, int na, struct node_list* b, int nb)
{
	/*You can modify the entire body of the function including the return statement one line below.*/
	int i;
	struct node_list *c;
	a = (struct node_list*)calloc(na, sizeof(struct node_list));
	b = (struct node_list*)calloc(nb, sizeof(struct node_list));
	printf("Filling array a\n");	/* GETTING INPUTS */
	for (i = 0; i < na; ++i){
		a[i].name = (char*)calloc(30, sizeof(char));
		printf("For %d. element:\n", i+1);
		printf("Enter data: ");
		scanf("%d", &a[i].data);
		printf("Enter number: ");
		scanf("%f", &a[i].number);
		printf("Enter name: ");
		scanf("%s", a[i].name);
	}
	printf("Filling array b\n");	/* GETTING INPUTS */
	for (i = 0; i < nb; ++i){
		b[i].name = (char*)calloc(30, sizeof(char));
		printf("For %d. element:\n", i+1);
		printf("Enter data: ");
		scanf("%d", &b[i].data);
		printf("Enter number: ");
		scanf("%f", &b[i].number);
		printf("Enter name: ");
		scanf("%s", b[i].name);
	}
	c = (struct node_list*)calloc(na+nb, sizeof(struct node_list));
	/* interleaving 2 arrays */
	if (na>=nb){
		for(i=0; i<nb; i+=2){	/* assigning values for a and b */
			c[i].data = a[i].data;
			c[i].number = a[i].number;
			c[i].name = a[i].name;
			c[i+1].data = b[i].data;
			c[i+1].number = b[i].number;
			c[i+1].name = b[i].name;
		}
		for(i = nb; i<na; i++){	/* assigning remaining values */
			c[i].data = a[i].data;
			c[i].number = a[i].number;
			c[i].name = a[i].name;
		}
	}
	if (nb>na){
		for(i=0; i<na; i+=2){/* assigning values for a and b */
			c[i].data = b[i].data;
			c[i].number = b[i].number;
			c[i].name = b[i].name;
			c[i+1].data = a[i].data;
			c[i+1].number = a[i].number;
			c[i+1].name = a[i].name;
		}
		for(i = na; i<nb; i++){/* assigning remaining values */
			c[i].data = b[i].data;
			c[i].number = b[i].number;
			c[i].name = b[i].name;
		}
	}
	free(a);
	free(b);
	return c;
}


int main()
{
	/*Do not modify anything between 95 and 130 lines.*/
	
	struct node_list *head_1 = NULL;
	struct node_list *head_2 = NULL;
	struct node_list *merged = NULL;
	struct node_list *interleaved = NULL;
	
	insert_end(&head_1,10,1.5,"hello1");
	insert_end(&head_1,30,3.5,"hello3");
	insert_end(&head_1,50,5.5,"hello5");
	 
	insert_end(&head_2,20,2.5,"hello2");
	insert_end(&head_2,40,4.5,"hello4");
	insert_end(&head_2,60,6.5,"hello6");
	
	printf("Print List 1: \n");
	 
	print_list(head_1);
	 
	printf("Print List 2: \n");
	 
	print_list(head_2);
	 
	merged=merge_list(head_1, head_2);
	
	printf("Print List Merged: \n");

    print_list(merged);/*

	interleaved=merge_interleaved(head_1, head_2);
	
	printf("Print List Interleaved: \n");
	
	print_list(interleaved);
 	
 	/*Do not modify anything between 95 and 130 lines.*/    
 	
	/*YOU CAN MODIFY BELOW THIS LINE FOR ONLY PART 3.*/
	
	struct node_list *a, *b, *c;
	int na, nb, i;
	printf("Enter size for array a: ");	/* getting inputs */
	scanf("%d", &na);
	printf("Enter size for array b: ");	
	scanf("%d", &nb);
	c = merge_array(a, na, b, nb);
	
	for (i=0; i<nb+na; i++){/* printing new array */
		printf("FOR %d. ELEMENT: \n",i+1);
		printf("data: %d\n", c[i].data);
		printf("number: %f\n", c[i].number);
		printf("name: %s\n",c[i].name);
	}
	
	
	
	
	
	return 0;
}