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
void push(int n,int p){
    if(isFull())
        printf("queue full .. try popping some elements");
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
        for (int j = front; j <= rear-i; j++)
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
void pop(){
    if(isEmpty()){
        printf("nothing here to pop");
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
        printf("\n1.Push\n2.Pop\n3.Trav\n choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the number to push : ");
                int n;
                scanf("%d",&n);
                printf("Enter the priority to push : ");
                int p;
                scanf("%d",&p);

                push(n,p);
                break;
            case 2: pop();
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
