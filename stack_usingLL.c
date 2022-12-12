#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
struct node
{
    int data;
    struct node *next;
}*newnode,*top,*temp;


int count=0;
void push(int a) //push is essentially inserting the newnode to the beginning of the linked list
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    if (count == MAX_SIZE)           //checking the full condition
    {
        printf("Stack overflow..");
    }
    else if (top == NULL)
    {
       top = newnode;
       newnode->next = NULL;
       count++;                //to check whether the stack has reached to the MAX_SIZE
       printf("node pushed successfully..");
    }
    else{
        newnode->next = top;
        top = newnode; 
        count++;
        printf("node pushed successfully..");
    }
}
void pop(){
    if (top == NULL)
    {
        printf("stack underflow..");
    }
    else{
        temp = top;
        top = top->next;
        free(temp);
        count --;
        printf("node popped succesfully..");    
    }
    
}
void traverse(){
    if (top == NULL)
    {
        printf("nothing here to display..");
    }
    else{
        temp = top;
        while (temp->next!=NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
}
void main()
{
    int ch,data;
     do{
    printf("\n\n1.PUSH\n2.POP\n3.TRAVERSE\n");
    scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the number : ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            
            traverse();
            break;
        default:
            break;
        }
        printf("\ndo you want to continue (0/1) : ");
        scanf("%d",&ch);
    }while(ch!=0);
}

