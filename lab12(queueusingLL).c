#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int count = 0;
struct node
{
    int data;
    struct node *next;
}*front, *temp, *rear, *head;

int isEmpty(){
    if (front == NULL)
        return 1;
    return 0;
}
int isFull(){
    if(count == MAX)
        return 1;
    return 0;
}
void enQueue(int x){
    if (isFull())
        printf("queue full");
    else{
        count++;
        head = (struct node *)malloc(sizeof(struct node *));
        head->data = x;
        head->next = NULL;
        if (isEmpty())
        {
            front = head;
            rear  = head;

        }
        else{
            rear->next = head;
            rear = head;
        }
        
    }
    
}
void deQueue(){
    if (isEmpty())
        printf("stack underflow");
    else if(front == rear){
        front = NULL;
        rear = NULL;

    }
    else{
            temp = front;
            front = front->next;
            free(temp);
            count--;
    }
    
}
void traverse(){
    temp = front;
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
        printf("\n\n1.enQueue\n2.deQueue\n3.Traverse\nchoice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                printf("enter the value to enQueue : ");
                scanf("%d",&n);
                enQueue(n);
                break;
        case 2: deQueue();
                break;
        case 3: traverse();
                break;
        
        default:
            break;
        }
    } while (choice!=0);
    
}