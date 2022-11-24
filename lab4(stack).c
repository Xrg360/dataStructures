#include<stdio.h>
#define MAX 5
int s[10],top =-1;
int isFull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(){
    if(top == -1)
        return 1;
    else 
        return 0;
}
void push(int n){
    if(isFull())
        printf("stack full .. try popping some elements");
    else{
        top++;
        s[top] =  n;
       
    }
}
void pop(){
    if(isEmpty()){
        printf("nothing here to pop");
    }
    else{
        int item = s[top];
        printf("%d is going to be deleted...",item);
        top--;
    }
}
void traverse(){
    if(isEmpty())
        printf("nothing much to display");
    else{
        for (int i = 0; i <= top; i++)
        {
            printf("%d",s[i]);
            if(i!=top)
                printf(", ");
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
                push(n);
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
