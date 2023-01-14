#include<stdio.h>
#include<stdlib.h>
struct term
{
    int expo,coeff;
    struct term *next;
}*startP,*startQ,*startR,*endP,*endQ,*endR,*temp1,*temp2,*temp3,*newterm;



// void read_polynomial(struct term *startX,struct term *endX){
//         int num_of_terms,coeff,expo;
//         printf("enter the number of terms : ");
//         scanf("%d",&num_of_terms);
//         for (int i = 0; i < num_of_terms; i++)
//         {
//             printf("enter the coeffcient : ");
//             scanf("%d",&coeff);
//             printf("enter the expo : ");
//             scanf("%d",&expo);
//             newterm = (struct term *)malloc(sizeof(struct term));
//             if (startX == NULL)
//             {
//                 startX = newterm;
//                 endX = newterm;
//             }
//             else{
//                 newterm->next = NULL;
//                 endX->next = newterm;
//                 endX = newterm;
//             }
            
//         }
        
// }   
void read_polynomialP(){
        // int num_of_terms,coeff,expo;
        // printf("enter the number of terms : ");
        // scanf("%d",&num_of_terms);
        // for (int i = 0; i < num_of_terms; i++)
        // {
        //     printf("enter the coeffcient : ");
        //     scanf("%d",&coeff);
        //     printf("enter the expo : ");
        //     scanf("%d",&expo);
        //     newterm = (struct term *)malloc(sizeof(struct term));
        //     newterm->coeff = coeff;
        //     newterm->expo = expo;
        //     if (startP == NULL)
        //     {
        //         startP = newterm;
        //         endP = newterm;
        //     }
        //     else{
        //         newterm->next = NULL;
        //         endP->next = newterm;
        //         endP = newterm;
        //     }
            
        // }
        char ch;
    startP=NULL;
    int co,ex;
    do{
        newterm=(struct term *)malloc(sizeof(struct term));
        printf("Enter coeff and expo of the term: ");
        scanf("%d %d",&co,&ex);
        newterm->coeff=co;
        newterm->expo=ex;
        newterm->next=NULL;
        if (startP==NULL){
            startP=newterm;
            temp2=newterm;
        }
        else{
            temp2->next=newterm;
            temp2=newterm;
        }
        printf("Want to add more?(y/n): ");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while (ch=='y');
        
}   
void read_polynomialQ(){
        int num_of_terms,coeff,expo;
        printf("enter the number of terms : ");
        scanf("%d",&num_of_terms);
        for (int i = 0; i < num_of_terms; i++)
        {
            printf("enter the coeffcient : ");
            scanf("%d",&coeff);
            printf("enter the expo : ");
            scanf("%d",&expo);
            newterm = (struct term *)malloc(sizeof(struct term));
            newterm->coeff = coeff;
            newterm->expo = expo;
            if (startQ == NULL)
            {
                startQ = newterm;
                endQ = newterm;
            }
            else{
                newterm->next = NULL;
                endQ->next = newterm;
                endQ = newterm;
            }
            
        }
        
}   

void multiply_poly(){
    temp1 = startP;
    int x,y;
    while (temp1!=NULL)
    {
        temp2 =  startQ;
        while (temp2!=NULL)
        {
            x=temp1->coeff*temp2->coeff;
            y=temp1->expo+temp2->expo;
            newterm = (struct term *)malloc(sizeof(struct term));
            newterm->coeff = x;
            newterm->expo = y;
            if (startR==NULL)
            {
                startR = newterm;
                endR = newterm;
                newterm->next = NULL;
            }
            else{
                endR->next = newterm;
                newterm->next = NULL;
                endR = newterm;
            }
            temp2 = temp2->next;            
        }
        temp1 = temp1->next;
        
    }
    
}

void display(struct term *startX,struct term *endX){
    if (startX == NULL)
    {
        printf("no terms to display...!");
    }
    else{
        struct term *temp = startX;
        while (temp->next!=NULL)
        {
            printf("%dx^%d +  ",temp->coeff,temp->expo);
        }
        printf("%dx^%d +  ",temp->coeff,temp->expo);
        
    }
    
    
}

void main(){
    read_polynomialP();
    read_polynomialQ();
    multiply_poly();
    display(startR,endR);
}
