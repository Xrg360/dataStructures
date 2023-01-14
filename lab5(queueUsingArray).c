#include<stdio.h>
#define MAX 5
int q[10],front =-1,rear =-1;
int isFull(){
    if(rear == MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(front == -1)
        return 1;
    else 
        return 0;
}
void enQueue(int n){
    if(isFull())
        printf("queue full .. try deQueueping some elements");
    else{
        rear++;
        q[rear] =  n;
        if(front == -1)
            front ++;
    }
}
void deQueue(){
    if(isEmpty()){
        printf("nothing here to deQueue");
    }
    else{
        int item = q[front];
        printf("%d is going to be deleted...",item);
        front++;
        if(front == rear){
            front = -1;
            rear = -1;
        }
    }
}
void traverse(){
    if(isEmpty())
        printf("nothing much to display");
    else{
            for (int i = front; i <= rear; i++)
            {
                printf("%d ",q[i]);
            }
        
    }
}
int main(int argc, char const *argv[])
{
    int choice;
   while(1){
        printf("\n1.enQueue\n2.deQueue\n3.Trav\n choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the number to enQueue : ");
                int n;
                scanf("%d",&n);
                enQueue(n);
                break;
            case 2: deQueue();
                    break;
            case 3: traverse();
                    break;
            case 0: break;
            
            default:
                printf("invalid choice");
        }
    }
    return 0;
}
