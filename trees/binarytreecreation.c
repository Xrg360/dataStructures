#include<stdio.h>  
#include<stdlib.h>
      struct node  
     {  
          int data;  
          struct node *left, *right;  
      } ;
       
struct node *create()  
{  
   struct node *newnode;  
   int data,choice;  
   newnode = (struct node *)malloc(sizeof(struct node));  
   printf("\nEnter the data(-1 for no data)");  
   scanf("%d", &data);  
   if(data==-1)  
    {  
    return 0;  
    }  
else  
{  
   
   newnode->data = data;  
   printf("Enter the left child of data %d", data);  
   newnode->left = create();  
printf("Enter the right child of data %d", data);  
newnode->right = create();  
return newnode;  
}  
}  
void preorder(struct node *root) //address of root node is passed in t
{
if(root!=NULL)
{
printf("\n%d",root->data); //visit the rootw
preorder(root->left); //preorder traversal on left subtree
preorder(root->right); //preorder traversal om right subtree
}
}
void main()  
    {  
         
       struct node *root = create();  
       printf("Elements displayed in preorder");
       preorder(root);
    }