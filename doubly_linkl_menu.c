#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
	int info;
	struct node *prev, *next;
};
struct node* start = NULL;

// Function to traverse the linked list
void traverse()
{
	// List is empty
	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	// Else print the Data
	struct node* temp;
	temp = start;
	printf("Elements:\t");
	while (temp != NULL) {
		printf(" %d\t", temp->info);
		temp = temp->next;
	}
}

// Function to insert at the front
// of the linked list
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;

	// Pointer of temp will be
	// assigned to start
	temp->next = start;
	start = temp;
}

// Function to insert at the end of
// the linked list
void insertAtEnd()
{
	int data;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;

	// If start is NULL
	if (start == NULL) {

		start = temp;
	}

	// Changes Links
	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

// Function to insert at any specified
// position in the linked list
void insertAtPosition()
{
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;

	// Enter the position and data
	printf("\nEnter position : ");
	scanf("%d", &pos);
	

	// If start==NULL,
	if (start == NULL) {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}

	// If position==1,
	else if (pos == 1) {
	// this is author method its correct but we can simply call insertAtfront() function for this special case
	/* newnode->next = start;
		newnode->next->prev = newnode;
		newnode->prev = NULL;
		start = newnode; */
	// now this is improved by Jay Ghughriwala on geeksforgeeks
	insertAtFront();
	}

	// Change links
	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	temp = start;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

// Function to delete from the front
// of the linked list
void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}

// Function to delete from the end
// of the linked list
void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

// Function to delete from any specified
// position from the linked list
void deletePosition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;

	// If DLL is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Otherwise
	else {
		// Position to be deleted
		printf("\nEnter position : ");
		scanf("%d", &pos);

		// If the position is the first node
		if (pos == 1) {
			deleteFirst(); // im,proved by Jay Ghughriwala on GeeksforGeeks
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}

		// Traverse till position
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		// Change Links
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

		// Free memory
		free(position);
	}
}

void search()  
{  int data;
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->info == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  


// Driver Code
int main()
{
	int choice;
	while (1) {

		printf("\n\t1 Display\n");
		printf("\t2 For insertion at"
			" beginning\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");
		printf("\t5 For deletion at "
			"beginning\n");
		printf("\t6 For deletion at "
			"at end \n");
		printf("\t7 For deletion of "
			"element at any position\n");
		printf("\t8 Search element\n");
		printf("\t9 Exit\n");
		
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;

		case 8:
		search();
		break;
		case 9:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}

