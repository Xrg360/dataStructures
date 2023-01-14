//Polynomial multiplication
#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff,expo;
    struct node *link;
}*start1,*start2,*temp1,*temp2,*start3,*temp3,*head,*newNode,*t1,*t2,*X;
void create1();
void create2();
void multiply();
void create1(){
    char ch;
    start1=NULL;
    int co,ex;
    do{
        head=(struct node *)malloc(sizeof(struct node));
        printf("Enter coeff and expo of the term: ");
        scanf("%d %d",&co,&ex);
        head->coeff=co;
        head->expo=ex;
        head->link=NULL;
        if (start1==NULL){
            start1=head;
            temp1=head;
        }
        else{
            temp1->link=head;
            temp1=head;
        }
        printf("Want to add more?(y/n): ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while (ch=='y');
}
void create2(){
    char ch;
    start2=NULL;
    int co,ex;
    do{
        head=(struct node *)malloc(sizeof(struct node));
        printf("Enter coeff and expo of the term: ");
        scanf("%d %d",&co,&ex);
        head->coeff=co;
        head->expo=ex;
        head->link=NULL;
        if (start2==NULL){
            start2=head;
            temp2=head;
        }
        else{
            temp2->link=head;
            temp2=head;
        }
        printf("Want to add more?(y/n): ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while (ch=='y');
}
void multiply(){
    temp1=start1;
    temp2=start2;
    start3=NULL;
    int x,y;
    while (temp1!=NULL){
        while (temp2!=NULL){
            x=temp1->coeff*temp2->coeff;
            y=temp1->expo+temp2->expo;
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode->coeff=x;
            newNode->expo=y;
            newNode->link=NULL;
            if (start3==NULL){
                start3=newNode;
                temp3=newNode;
            }
            else{
                temp3->link=newNode;
                temp3=newNode;
            }
            temp2=temp2->link;
        }
        temp1=temp1->link;
        temp2=start2;
    }
    temp3=start3;
    while (temp3!=NULL){
        t1=temp3;
        t2=temp3->link;
        while (t2!=NULL){
            if (temp3->expo==t2->expo){
                temp3->coeff=temp3->coeff+t2->coeff;
                t1->link=t2->link;
                X=t2;
                t2=t2->link;
                free(X);
            }
            else{
                t1=t2;
                t2=t2->link;
            }
        }
        temp3=temp3->link;
    }
    printf("First Polynomial\n");
    temp1=start1;
    while (temp1->link!=NULL){
        printf("%dx^%d+",temp1->coeff,temp1->expo);
        temp1=temp1->link;
    }
    printf("%dx^%d\n",temp1->coeff,temp1->expo);
    printf("Second Polynomial\n");
    temp2=start2;
    while (temp2->link!=NULL){
        printf("%dx^%d+",temp2->coeff,temp2->expo);
        temp2=temp2->link;
    }
    printf("%dx^%d\n",temp2->coeff,temp2->expo);
    printf("Product polynomial\n");
    temp3=start3;
    while (temp3->link!=NULL){
        printf("%dx%d+",temp3->coeff,temp3->expo);
        temp3=temp3->link;
    }
    printf("%dx%d",temp3->coeff,temp3->expo);
} 
void main(){
    printf("Enter first polynomial \n");
    create1();
    printf("Enter second polynomial \n");
    create2();
    multiply();
}