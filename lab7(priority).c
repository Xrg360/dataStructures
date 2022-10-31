#include<stdio.h>
#define MAX 5
struct queue
{
    int data;
    int priority;
}q[MAX];
int front =-1,rear =-1;
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
void enQueue(int n,int p){
    if(isFull())
        printf("queue full .. try deQueuing some elements");
    else{
        rear++;
        q[rear].data =  n;
        q[rear].priority = p;
        if(front == -1)
            front ++;
    }
}
void sort(){
    int t;
    for (int i = front; i <= rear; i++)
    {
        for (int j = front; j < rear; j++)
        {
            if(q[j].priority>q[j+1].priority){
                t=q[j].data;
                q[j].data = q[j+1].data;
                q[j+1].data = t;

                t=q[j].priority;
                q[j].priority = q[j+1].priority;
                q[j+1].priority = t;
            }
        }
        
    }
    
}
void deQueue(){
    if(isEmpty()){
        printf("nothing here to deQueue");
    }
    else{
        sort();
        int item = q[front].data;
        printf("%d is going to be deleted..",item);
        front ++;
        if (front>rear)
        {
            front =-1;
            rear =-1;
        }
    }
    
}
void traverse(){
    if(isEmpty())
        printf("nothing much to display");
    else{
            sort();
            for (int i = front; i <= rear; i++)
            {
                printf("%d ",q[i]);
            }
        
    }
}
int main()
{
    int choice;
   while(1){
        printf("\n1.enQueue\n2.deQueue\n3.Traverse\n choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the number to enQueue : ");
                int n;
                scanf("%d",&n);
                printf("Enter the priority to enQueue : ");
                int p;
                scanf("%d",&p);

                enQueue(n,p);
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
