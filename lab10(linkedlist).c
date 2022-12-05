#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*start,*end,*head;

int isEmpty(){
    if (start == NULL)
        return 1;
    return 0;    
}
void insert_begin(int item){
    head =  (struct node *)malloc(sizeof(struct node));
    head->data = item;
    if(isEmpty()){
        start = head;
        end = head;
        head->link = NULL; 
    }
    else{
        head->link =  start;
        start = head;
    }    
}
void insert_end(int item){
    head =  (struct node *)malloc(sizeof(struct node));
    head->data = item;
    if(isEmpty()){
        start = head;
        end = head;
        head->link = NULL; 
    }
    else{
        end->link =  head;
        end = head;
    }    
}
void insert_loc(int item,int loc){
    head =  (struct node *)malloc(sizeof(struct node));
    head->data = item;
    int count = 1;
    struct node *t,*temp;
    temp = start;
    while (count != loc)
    {
        t=temp;
        temp=temp->link;
        count++;
    }
    t->link = head;
    head->link=temp;
    
}
void delete_begin(){
    if(isEmpty())
        printf("nothing to delete..");
    else{
        head = start;
        start =  start->link;
        free(head);
    }    
}
void delete_end(){
   
    if(isEmpty())
        printf("nothing to delete....");
    else{
        head = start;
        while (head->link != end)
        {
            head = head->link;
        }
            head->link = NULL;
            free(end);
            head = end;
        
    }    
}
void delete_loc(int loc){
 
    int count = 1;
    struct node *t,*temp;
    temp = start;
    while (count != loc)
    {
        t=temp;
        temp=temp->link;
        count++;
    }
    t->link = temp->link;
    free(temp);
    
}
void traverse(){
    struct node *t,*temp;
    temp = start;
    while (temp!=NULL)
    {
        printf("%d, ",temp->data );
        temp = temp->link;
    }
    
}
void main(){
    int ch,data,loc;
    do{
    printf("\n\nINSERT\n1.BEGIN\n2.END\n3.LOCATION\n\nDELETE\n4.BEGIN\n5.END\n6.LOCATION\n.");
    scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter the number : ");
            scanf("%d",&data);
            insert_begin(data);
            break;
        case 2:
            printf("enter the number : ");
            scanf("%d",&data);
            insert_end(data);
            break;
        case 3:
            
            printf("enter the number : ");
            scanf("%d",&data);
            printf("enter the location : ");
            scanf("%d",&loc);
            insert_loc(data,loc);
            break;
        case 4:        
            delete_begin();
            break;
        case 5:
        delete_end();
            break;
        case 6:
            printf("enter the location : ");
            scanf("%d",&data);
            delete_loc(data);
            break;
        case 7:
            traverse();
            break;
        
        default:
            break;
        }
        printf("do you want to continue (0/1) : ");
        scanf("%d",&ch);
    }while(ch!=0);

}
