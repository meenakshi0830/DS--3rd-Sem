#include <stdio.h>
#include <stdlib.h>

struct node1{
    int data1;
    struct node1 *next1;
};

struct node1 *top=NULL;

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void insert(){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter an element\n");
    scanf("%d",&newNode->data);
    if(front==NULL && rear==NULL){
        front=newNode;
        rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}

void delete(){
    if(front==NULL && rear==NULL){
        printf("List is empty, cannot remove\n");
        return;
    }
   
    int item=front->data;
    if(front==rear){
        front=NULL;
        rear=NULL;
    }
    else{
    front=front->next;
    }
    printf("%d is removed from the queue\n",item);
}

void display(){
    if(front==NULL && rear==NULL){
        printf("List is empty\n");
        return;
    }
   
    struct node *temp;
    temp=front;
    printf("Linked List ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void push(){
    struct node1 *newNode1;
    newNode1=(struct node1*)malloc(sizeof(struct node1));
    printf("Enter an element\n");
    scanf("%d",&newNode1->data1);
    if(top==NULL){
        top=newNode1;
        return;
    }
    newNode1->next1=top;
    top=newNode1;
}

void pop(){
    if(top==NULL){
        printf("List is empty, cannot pop\n");
        return;
    }
   
    int item1=top->data1;
    top=top->next1;
    printf("%d is popped\n",item1);
}

void display1(){
    if(top==NULL){
        printf("List is empty\n");
        return;
    }
   
    struct node1 *temp1;
    temp1=top;
    printf("Linked List ");
    while(temp1!=NULL){
        printf("%d ",temp1->data1);
        temp1=temp1->next1;
    }
    printf("\n");
}

int main()
{int c;
while(1){
    printf("Menu\n");
    printf("1.Stack\n");
    printf("2.Queue\n");
    printf("3.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&c);
    switch(c)
    {
        
    case 1:{ int ch;
    do{
        printf("Enter 1 to enter element into stack\n");
        printf("Enter 2 to delete element from stack\n");
        printf("Enter 3 to display stack\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            push();
            break;
           
            case 2:
            pop();
            break;
           
            case 3:
            display1();
            break;
           
            case 4:
            printf("EXIT\n");
            break;
        }
    }while(ch!=4);
   
    }break;
    
    
     case 2:{ int choice;
    do{
        printf("Enter 1 to enter element into queue\n");
        printf("Enter 2 to delete element from queue\n");
        printf("Enter 3 to display queue\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
           
            case 2:
            delete();
            break;
           
            case 3:
            display();
            break;
           
            case 4:
            printf("EXIT\n");
            break;
        }
    }while(choice!=4);
    
}break;
case 3:exit(0);
}
}
return 0;
}



