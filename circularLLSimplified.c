#include<stdio.h>
#include<stdlib.h>
void display();
void insertb();
void inserte();
void insertsp();
void deletef();
void deletel();
void deletesp();
int k;
struct node
{
  int data;
  struct node *link;
}*head=NULL,*temp,*newnode,*prevnode=0,*last;

void create()
{
   int n,item;
   int c;
  
  
  
  do
  {
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data item\n");
    scanf("%d",&item);
    newnode -> data=item;
    newnode -> link= NULL;
    if(head==NULL)
    {
      head=newnode;
      temp=newnode;
    }
    else
    {
      temp -> link=newnode;
      temp=newnode;
      newnode->link=head;
    }
    printf("Do you want to continue(1/0)?:\n");
    scanf("%d",&c);
  }while(c==1);
  
}

void display()
{
  if(head==NULL)
  {
    printf("List is empty\n");
  }
  else{
  temp=head;
  printf("\n");
  while(temp->link!=head)
  {
    printf("%d\t",temp->data);
    temp=temp->link;
  }
  printf("%d\n",temp->data);
  }
}

void insertb()
{
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter the element to be inserted:\n");
  scanf("%d",&k);
  newnode->data=k;
  if(head==NULL)
  {
    
    head=newnode;
    head->link=head;
  }
  else
  {
    
    
    while(temp->link!=head)
    {
      temp=temp->link;
    }
    
      temp->link=newnode;
          
      
      newnode->link=head;
      head=newnode;
    
  display();
  }
}

void inserte()
{
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter the element to be inserted:\n");
  scanf("%d",&k);

  temp=head;
  while(temp->link!=head)
  {
    temp=temp->link;
  }
  temp->link=newnode;
  newnode->data=k;
  newnode->link=head;
  display();
  
  
}

void insertsp()
{
  int pos,i=1;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter the element to be inserted:\n");
  scanf("%d",&k);
  newnode->data=k;
  printf("Enter the required position: \n");
  scanf("%d",&pos);
  
  
  if(pos==1)
  insertb();
  else
  {
    
  
    temp=head;
    while(i<pos-1)
    {
      temp=temp->link;
      i++;
    }
      newnode->link=temp->link;
      temp->link=newnode;
    }
   display();
}


void deletef()
{
  if(head==NULL)
  printf("List is Empty!\n");
  else if(head->link==head)
  {
    temp=head;
    head=NULL;
    free(temp);
  }
  else{

  temp=head;
  
  
  while(temp->link!=head)
  {
    temp=temp->link;
  }
  temp->link=head->link;
  temp=head;
  last=head->link;
  free(temp);
  head=last;
  
  }
  display();
}

void deletel()
{
  if(head==NULL)
  printf("List is empty!\n");
  else if(head->link==head)
  {
    temp=head;
    head=NULL;
    free(temp);
  }
  else{
  temp=head;
  
  while(temp->link!=head)
  {
    prevnode=temp;
    temp=temp->link;
  }
  
    free(temp);
    prevnode->link=head;
    
  }
  display();
 }


void deletesp()
{
  temp=head;
  int c=1;
  while(temp->link!=head)
  {
    temp=temp->link;
    c++;
  }
 
  
  
  if(head==NULL)
  printf("List is empty!\n");
  else if(head->link==head)
  {
    temp=head;
    head=NULL;
    free(temp);
  }
  else
  {
  temp=head;
  int i=1,pos;
  printf("Enter the required position: \n");
  scanf("%d",&pos);
  if(pos==1)
  deletef();
  else if(pos>c){
  printf("INVALID POSITION!\n");}
  else{
  while(i<pos)
  {
    prevnode=temp;
    temp=temp->link;
    i++;
  }
  prevnode->link=temp->link;
  free(temp);
  display();
  }
}
}


void main()
{
  int ch,c;
//   create();
  while(1){
  printf("MENU:\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
  printf("Enter your choice:\n");
  scanf("%d",&ch);
  if(ch==1)
  {
    while(1){
    printf("Sub-Menu:\n 1.Insert at Beginning\n 2.Insert at Specific Postion\n 3.Insert at end\n 4.Back\n");
    printf("Enter your choice:\n");
    scanf("%d",&c);
    if(c==1)
    insertb();
    else if(c==2)
    insertsp();
    else if(c==3)
    inserte();
    else if(c==4)
    break;
    elsed
    printf("Invalid Choice\n");
    
    }
  }
  
  else if(ch==2)
  {
    while(1)
    {
      printf("Sub-Menu:\n 1.Delete at front\n 2.Delete at Specific Position\n 3.Delete at last\n 4.Back\n");
      printf("Enter your choice:\n");
      scanf("%d",&c);
      if(c==1)
      deletef();
      else if(c==2)
      deletesp();
      else if(c==3)
      deletel();
      else if(c==4)
      break;
      else
      printf("Invalid Choice\n");
   }
  }
  else if(ch==3)
  display();
  else if(ch==4)
  break;
  else
  printf("Invalid Choice\n");
 }
}

      
  

