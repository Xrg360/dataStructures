#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head=NULL,*temp,*newnode,*prev;
void insert();
void delete();
void insertatf();
void display();
void insertspecific();
void insertate();
void specificdelete();
void fdelete();
void edelete();
int n;
int main()
{
    while(1)
    {
        printf("\nEnter the choice\n1.insertion\n2.deletion\n3.display\n4.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insert();
                    break;
            case 2:delete();
                    break;
            case 3:display();
                    break;
            case 4:return 0;
            default: printf("Invalid choice");
        }
    }
}
void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    while(1)
    {
        printf("\nWhere to insert node\n1.insert at front\n2.insert at end\n3.insert after specified node\n4.back to main menu\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insertatf();
                    return;
            case 2:insertate();
                    return;
            case 3:insertspecific();
                    return;
            case 4:return;
            default: printf("Invalid choice");
        }
    }
}
void insertatf()
{
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->link=head;
        head=newnode;
    }
}
void insertate()
{
    if(head==NULL)
        head=newnode;
    else
    {
        temp=head;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=newnode;
        printf("Node Inserted");
    }
}
void insertspecific()
{
    int k;
    printf("Enter the data of specificied node: ");
    scanf("%d",&k);
    if(head==NULL)
        printf("Insertion not possible");
    else
    {
        temp=head;
        while(temp->data!=k&&temp->link!=NULL)
            temp=temp->link;
        if(temp->data==k)
        {
            newnode->link=temp->link;
            temp->link=newnode;
            printf("Node Inserted");
        }
        else
            printf("Specified node not found");
    }
}

void display()
{
    if(head==NULL)
       printf("List is Empty");
    else
    {
        temp=head;
        printf("List is : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        
    }
    
}
void delete()
{
    while(1)
    {
        printf("\n from where to delete?\n1.delete from front\n2.delete from end\n3.delete a specified node\n4.back to main menu\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:fdelete();
                    return;
            case 2:edelete();
                    return;
            case 3:specificdelete();
                    return;
            case 4:return;
            default: printf("Invalid choice");
        }
    }
}
void fdelete()
{
    if(head==NULL)
        printf("list empty");
    else
    {
        temp=head;
        head=head->link;
        free(temp);
        printf("Node Deleted");
    }
}
void edelete()
{
    if(head==NULL)
        printf("list empty");
    else if(head->link==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        prev=head;
        temp=head->link;
        while(temp-> link!=NULL)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=NULL;
        free(temp);
    }
    printf("Node Deleted"); 
}
void specificdelete()
{
    int k;
    printf("Enter the data of specificied node: ");
    scanf("%d",&k);
    if(head==NULL)
        printf("list empty");
    else if(head->data==k)
    {
        temp=head;
        head=head->link;
        free(temp);
        printf("Node Deleted");
    }
    else
    {
        prev=head;
        temp=head->link;
        while(temp->data!=k&&temp->link!=NULL)
        {
            prev=temp;
            temp=temp->link;
        }
        if(temp->data!=k)
            printf("Specified node not found");
        else
        {
            prev->link=temp->link;
            free(temp);
            printf("Node Deleted");
        }
    }
}










