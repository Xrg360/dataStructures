#include<stdio.h>
#include<stdlib.h>
struct A
{
    int expo,coeff;
    struct A *next;
}*start1,*end1,*newnode1,*temp1;
struct B
{
    int expo,coeff;
    struct B *next;
}*start2,*end2,*newnode2,*temp2;
struct C
{
    int expo,coeff;
    struct C *next;
}*start3,*end3,*newnode3,*temp3,*t1,*t2;
void read_poly(){
    newnode1 = (struct A *)malloc(sizeof(struct A));
    int ch;
    if(start1==NULL)
    {       
        do{
        printf("enter the expo to be inserted : ");
        scanf("%d",&newnode1->expo);
        printf("enter the coeff to be inserted : ");
        scanf("%d",&newnode1->coeff); 
        start1=newnode1;
        end1 = newnode1;
        printf("Node Inserted");
        printf("do you want to continue : ");
        scanf("%d",&ch);
        }while(ch!=0);
    }
    else
    {
        do{
        printf("enter the expo to be inserted : ");
        scanf("%d",&newnode1->expo);
        printf("enter the coeff to be inserted : ");
        scanf("%d",&newnode1->coeff); 
        end1->next = newnode1;
        end1 =newnode1;
        printf("Node Inserted");
        printf("do you want to continue : ");
        scanf("%d",&ch);
        }while(ch!=0);
    }

}
void read_poly2(){
    newnode2 = (struct B *)malloc(sizeof(struct  B));
    if(start2==NULL)
    {    start2=newnode2;
        end2 = newnode2;}
    else
    {
        printf("enter the expo to be inserted : ");
        scanf("%d",&newnode2->expo);
        printf("enter the coeff to be inserted : ");
        scanf("%d",&newnode2->coeff); 
        end2->next = newnode2;
        end2 =newnode2;
        printf("Node Inserted");
    }

}
void multiply(){
    temp1 = start1;
    while (temp1 != NULL)
    {
        temp2 = start2;
        while (temp2 != NULL)
        {
            int x = temp1->coeff*temp2->coeff;
            int y = temp1->expo+temp2->expo;
            newnode3 = (struct C *)malloc(sizeof(struct C));
            newnode3->coeff = x;
            newnode3->expo = y;
            if(start3 == NULL){
                start3 = newnode3;
                end3 = newnode3;
                newnode3->next = NULL;
            }
            else{
                end3->next = newnode3;
                end3 = newnode3;
                newnode3->next = NULL;
            }

        }
        
    }
    temp3 = start3;
    while (temp3 != NULL)
    {
        t1 = temp3;
        t2= temp3 ->next;
        while (t2!=NULL)
        {
            if (t2->coeff == temp3->coeff)
            {
                temp3->coeff = t2->coeff + temp3->coeff;
                t1->next = t2->next;
                free(t2);
                t2= t1->next;
            }
            else{
                t1 = t2;
                t2 = t2->next;
            }
            
        }
        
    }

    
}
void display(){
    temp3 = start3;
    while (temp3 != NULL)
    {
        printf("%dX^%d",temp3->coeff,temp3->expo);
        temp3 = temp3 ->next;
    }
    
}
void main(){
    read_poly();
    read_poly2();
    multiply();
    display();
}