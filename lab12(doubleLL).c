#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
}*start,*end,*temp,*t,*newnode;
insert_begin(int d){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = d;
    if (start == NULL){
        start = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}
insert_end(int d){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = d;
    if (start == NULL){
        start = newnode;
        newnode->next = NULL;
    }
    else{
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}
insert_specified(int d,int d_loc){
    if(start == NULL){
        printf("no element to add in between");
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data= d;
        temp = start;
        while (temp->data != d_loc)
        {
            temp  = temp->next;
        }
 
       newnode->next = temp->next;  
       newnode->prev = temp;  
       temp->next = newnode;  
       temp->next->prev=newnode;

    }
    
}
void traverse(){
    temp = start;
    while (temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    
    
}

void delete_begin(){
    if (start == NULL)
    {
        printf("nothting to delete");
    }
    
    else{
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
}

void delete_end(){
    if (start == NULL)
    {
        printf("nothting to delete");
    }else{
        temp =  start;
        while (temp->next!=NULL)
        {
            t=temp;
            temp = temp->next;
        }
        t->next = NULL;
        free(temp);
    }
    
}

void delete_loc(int d_loc){
    temp = start;
    while (temp->data != d_loc)
    {
        temp = temp->next;
    }
    t= temp->next;
    t->prev = temp->prev;
    temp->prev->next = t;
    free(temp);

        
}

void main(){
    int ch,data,loc;
    do
    {
        scanf("%d",&ch);
        printf("data : ");
        scanf("%d",&data);
        
        switch (ch)
        {
        case 1:
            insert_begin(data);
            break;
        case 2:
            insert_end(data);
            break;
        case 3:
            printf("enter the data after which the data is to be inserted : ");
            scanf("%d",&loc);
            insert_specified(data,loc);
            break;
        case 4: traverse();
                break;
        case 5: delete_loc(30);
                break;
        case 6: delete_begin();
                break;
        case 7: delete_end();
                break;
        default:
            break;
        }
    } while (ch!=0);
    
}