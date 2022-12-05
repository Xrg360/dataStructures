#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int count = 0;
struct node
{
    int data;
    struct node *next;
}*top, *temp, *head;

int isEmpty(){
    if (top == NULL)
        return 1;
    return 0;
}
int isFull(){
    if(count == MAX-1)
        return 1;
    return 0;
}
void push(int x){
    if (isFull())
        printf("stack overflow");
    else{
        count++;
        head = (struct node *)malloc(sizeof(struct node *));
        head->data = x;
        if (isEmpty())
        {
            top = head;
            head->next = NULL;

        }
        else{
            head->next = top;
            top = head;
        }
        
    }
    
}
void pop(){
    if (isEmpty())
        printf("stack underflow");
    else if(top->next == NULL){
        top == NULL;

    }
    else{
            head = top;
            top = top->next;
            free(head);
            count--;
    }
    
}
void traverse(){
    temp = top;
    if (isEmpty())
    {
        printf("nothing here to display...");
    }
    else
    {
        while (temp->next!=NULL)
        {
            printf("%d-> ",temp->data );
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
    
}
void main(){
    int choice,n;
    do
    {
        printf("\n\n1.Push\n2.Pop\n3.Traverse\nchoice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                printf("enter the value to push : ");
                scanf("%d",&n);
                push(n);
                break;
        case 2: pop();
                break;
        case 3: traverse();
                break;
        
        default:
            break;
        }
    } while (choice!=0);
    
}