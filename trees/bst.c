//code for binary search tree in c using menu drivn program
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void insert();
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void search();
void delete();
void main()
{
    int ch;
    while(1)
    {
        printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\n7.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                search();
                break;
            case 6:
                delete();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice");
        }
    }
}   

//code for insertion in binary search tree
void insert()
{
    struct node *ptr,*parentptr,*nodeptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("OVERFLOW");
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&item);
        ptr->data=item;
        if(root==NULL)
        {
            root=ptr;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            parentptr=NULL;
            nodeptr=root;
            while(nodeptr!=NULL)
            {
                parentptr=nodeptr;
                if(item>nodeptr->data)
                {
                    nodeptr=nodeptr->right;
                }
                else
                {
                    nodeptr=nodeptr->left;
                }
            }
            if(item<parentptr->data)
            {
                parentptr->left=ptr;
                ptr->left=NULL;
                ptr->right=NULL;
            }
            else
            {
                parentptr->right=ptr;
                ptr->left=NULL;
                ptr->right=NULL;
            }
        }
    }
}
//code for searching in binary search tree
void search()
{
    struct node *nodeptr;
    int item,flag;
    nodeptr=root;
    if(nodeptr==NULL)
    {
        printf("Empty tree");
    }
    else
    {
        printf("Enter the value to be searched : ");
        scanf("%d",&item);
        while(nodeptr!=NULL)
        {
            if(item>nodeptr->data)
            {
                nodeptr=nodeptr->right;
            }
            else if(item<nodeptr->data)
            {
                nodeptr=nodeptr->left;
            }
            else if(item==nodeptr->data)
            {
                printf("Item found");
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("Item not found");
        }
    }
}
//code for deletion in binary search tree
void delete()
{
    struct node *nodeptr,*parentptr;
    int item;
    if(root==NULL)
    {
        printf("Empty tree");
    }
    else
    {
        printf("Enter the value to be deleted : ");
        scanf("%d",&item);
        nodeptr=root;
        while(nodeptr->data!=item)
        {
            parentptr=nodeptr;
            if(item>nodeptr->data)
            {
                nodeptr=nodeptr->right;
            }
            else
            {
                nodeptr=nodeptr->left;
            }
            if(nodeptr==NULL)
            {
                printf("Item not found");
                return;
            }
        }
        //case 1
        if(nodeptr->left==NULL && nodeptr->right==NULL)
        {
            if(parentptr->left==nodeptr)
            {
                parentptr->left=NULL;
            }
            else
            {
                parentptr->right=NULL;
            }
            nodeptr=NULL;
            free(nodeptr);
            printf("Item deleted");
        }
        //case 2
        else if(nodeptr->left==NULL || nodeptr->right==NULL)
        {
            if(nodeptr->left==NULL)
            {
                if(parentptr->left==nodeptr)
                {
                    parentptr->left=nodeptr->right;
                }
                else
                {
                    parentptr->right=nodeptr->right;
                }
            }
            else
            {
                if(parentptr->left==nodeptr)
                {
                    parentptr->left=nodeptr->left;
                }
                else
                {
                    parentptr->right=nodeptr->left;
                }
            }
            free(nodeptr);
            printf("Item deleted");
        }
        //case 3
        else
        {
            struct node *ptr;
            ptr=nodeptr->right;
            if((ptr->left==NULL) && (ptr->right==NULL))
            {
                nodeptr=ptr;
                free(ptr);
                nodeptr->right=NULL;
            }
            else
            {
                if(ptr->left!=NULL)
                {
                    struct node *p,*ptr;
                    ptr=nodeptr->right;
                    p=ptr->left;
                    while(p->left!=NULL)
                    {
                        ptr=p;
                        p=p->left;
                    }
                    nodeptr->data=p->data;
                    ptr->left=p->right;
                    free(p);
                }
                else
                {
                    struct node *ptr;
                    ptr=nodeptr->right;
                    nodeptr->data=ptr->data;
                    nodeptr->right=ptr->right;
                    free(ptr);
                }
            }
            printf("Item deleted");
        }
    }
}
//code for inorder traversal in binary search tree
void inorder(struct node *nodeptr)
{
    if(root==NULL)
    {
        printf("Empty tree");
    }
    else
    {
        if(nodeptr->left!=NULL)
        {
            inorder(nodeptr->left);
        }
        printf("%d\t",nodeptr->data);
        if(nodeptr->right!=NULL)
        {
            inorder(nodeptr->right);
        }
    }
}
//code for preorder traversal in binary search tree
void preorder(struct node *nodeptr)
{
    if(root==NULL)
    {
        printf("Empty tree");
    }
    else
    {
        printf("%d\t",nodeptr->data);
        if(nodeptr->left!=NULL)
        {
            preorder(nodeptr->left);
        }
        if(nodeptr->right!=NULL)
        {
            preorder(nodeptr->right);
        }
    }
}
//code for postorder traversal in binary search tree
void postorder(struct node *nodeptr)
{
    if(root==NULL)
    {
        printf("Empty tree");
    }
    else
    {
        if(nodeptr->left!=NULL)
        {
            postorder(nodeptr->left);
        }
        if(nodeptr->right!=NULL)
        {
            postorder(nodeptr->right);
        }
        printf("%d\t",nodeptr->data);
    }
}
//code for finding the height of binary search tree
int height(struct node *nodeptr)
{
    int leftheight,rightheight;
    if(nodeptr==NULL)
    {
        return 0;
    }
    else
    {
        leftheight=height(nodeptr->left);
        rightheight=height(nodeptr->right);
        if(leftheight>rightheight)
        {
            return (leftheight+1);
        }
        else
        {
            return (rightheight+1);
        }
    }
}
//code for finding the number of nodes in binary search tree
int count(struct node *nodeptr)
{
    if(nodeptr==NULL)
    {
        return 0;
    }
    else
    {
        return (count(nodeptr->left)+count(nodeptr->right)+1);
    }
}
//code for finding the number of leaf nodes in binary search tree
int leafcount(struct node *nodeptr)
{
    if(nodeptr==NULL)
    {
        return 0;
    }
    else if(nodeptr->left==NULL && nodeptr->right==NULL)
    {
        return 1;
    }
    else
    {
        return (leafcount(nodeptr->left)+leafcount(nodeptr->right));
    }
}
//code for finding the number of non-leaf nodes in binary search tree
int nonleafcount(struct node *nodeptr)
{
    if(nodeptr==NULL)
    {
        return 0;
    }
    else if(nodeptr->left==NULL && nodeptr->right==NULL)
    {
        return 0;
    }
    else
    {
        return (nonleafcount(nodeptr->left)+nonleafcount(nodeptr->right)+1);
    }
}
//code for finding the number of full nodes in binary search tree
int fullcount(struct node *nodeptr)
{
    if(nodeptr==NULL)
    {
        return 0;
    }
    else if(nodeptr->left==NULL && nodeptr->right==NULL)
    {
        return 0;
    }
    else if(nodeptr->left!=NULL && nodeptr->right!=NULL)
    {
        return (fullcount(nodeptr->left)+fullcount(nodeptr->right)+1);
    }
    else
    {
        return (fullcount(nodeptr->left)+fullcount(nodeptr->right));
    }
}
