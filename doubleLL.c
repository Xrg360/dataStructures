#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
}*head,*end,*temp,*t,*newnode;
void insert_begin(){
    int d;
    printf("enter the data to be inserted  : ");
    scanf("%d",&d);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = d;
    if (head == NULL){
        head = newnode;
        newnode->next = NULL;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("Node inserted succesfully..!\n");
}
void insert_end(){
    int d;
    printf("enter the data to be inserted  : ");
    scanf("%d",&d);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = d;
    if (head == NULL){
        head = newnode;
        newnode->next = NULL;
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Node inserted succesfully..!\n");
}
void insert_specified(){
    int d,d_loc;
    printf("enter the data to be inserted  : ");
    scanf("%d",&d);
    printf("enter the data after which the data to be inserted  : ");
    scanf("%d",&d_loc);
    if(head == NULL){
        printf("no element to add in between");
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data= d;
        temp = head;
        while (temp->data != d_loc)
        {
            temp  = temp->next;
        }
 
       newnode->next = temp->next;  
       newnode->prev = temp;  
       temp->next = newnode;  
       temp->next->prev=newnode;
       printf("Node inserted succesfully..!\n");

    }
    
}
void traverse(){
    temp = head;
    while (temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    
    
}

void delete_begin(){
    if (head == NULL)
    {
        printf("nothting to delete");
    }
    
    else{
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("Node deleted successfully...!\n");
    }
}

void delete_end(){
    if (head == NULL)
    {
        printf("nothting to delete");
    }else{
        temp =  head;
        while (temp->next!=NULL)
        {
            t=temp;
            temp = temp->next;
        }
        t->next = NULL;
        free(temp);
        printf("Node deleted successfully...!\n");
    }
    
}

void delete_loc(){
    
    int d_loc;
    printf("enter the data to be deleted  : ");
    scanf("%d",&d_loc);
    if (d_loc == head->data)
    {
        delete_begin();
        printf("Node deleted successfully...!\n");
        return;
    }
    
    temp = head;
    while (temp->data != d_loc)
    {
        temp = temp->next;
    }
    t= temp->next;
    t->prev = temp->prev;
    temp->prev->next = t;
    free(temp);
    printf("Node deleted successfully...!\n");

        
}
void main(){
    printf("--------Double linkedList-------\n");
    int ch1,ch2;
    do
    {
        ch2=-1;
        printf("1.Insert\n2.Delete\n3.Traverse\n0.Exit\n");   
        scanf("%d",&ch1);
        switch (ch1)
        {
        case 1:
            do
            {
                printf("1.Insert at begin\n2.Insert at end\n3.Insert at a specified location\n0. GOBACK : ");
                scanf("%d",&ch2);
                switch (ch2)
                {
                case 1:
                    insert_begin();
                    break;
                case 2:
                    insert_end();
                    break;
                case 3:
                    insert_specified();
                    break;
                case 0 :
                break;
                
                default:
                    break;
                }
            } while (ch2!=0);
            
            break;
        case 2:
            do
            {
                printf("1.Delete at begin\n2.Delete at end\n3.Delete at a specified location\n0. GOBACK");
                scanf("%d",&ch2);
                switch (ch2)
                {
                case 1:
                    delete_begin();
                    break;
                case 2:
                    delete_end();
                    break;
                case 3:
                    delete_loc();
                    break;
                case 0 :
                break;
                
                default:
                    break;
                }
            } while (ch2!=0);
            
            break;
        case 3:
            traverse();
            break;
        default:
            break;
        }
        
    } while (ch1!=0);
    
}