#include <stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
} *root, *newnode, *parent, *ptr;

void search()
{
    int key;
    printf("enter the key element to be searched : ");
    scanf("%d", &key);
    int flag = 0;
    if (root == NULL)
    {
        printf("searching not possible tree doesnt exist");
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            if (key == ptr->data)
            {
                flag = 1;
                break;
            }
            else if (key < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        if (flag == 1)
            printf("key found");
        else
            printf("key not found");
    }
}
void insertion()
{
    printf("enter the data to be inserted to the tree : ");
    int item;
    scanf("%d", &item);
    newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("insertion not possible");
                return;
            }
            else if (item < ptr->data)
            {
                parent = ptr;
                ptr = ptr->left;
            }
            else
            {
                parent = ptr;
                ptr = ptr->right;
            }
        }
        if (item < parent->data)
            parent->left = newnode;
        else if (item > parent->data)
            parent->right = newnode;
    }
}

void deletion()
{
    int key;
    printf("enter the key element to be searched : ");
    scanf("%d", &key);
    int flag = 0;
    if (root == NULL)
    {
        printf("searching not possible tree doesnt exist");
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            if (key == ptr->data)
            {
                flag = 1;
                break;
            }
            else if (key < ptr->data)
            {
                parent = ptr;
                ptr = ptr->left;
            }
            else
            {   
                parent = ptr;
                ptr = ptr->right;
            }
        }
        if (flag == 1)
        {
            if(ptr->left == NULL && ptr->right ==NULL){
                if (parent->left = ptr)
                {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
                printf("deletion successfull");
            } else if (ptr->left != NULL && ptr->right !=NULL)
            {
                printf("this case is under observation :)");
            }
            else {
                if (parent->left == ptr)
                {

                    if (ptr->left != NULL)
                        parent->left = ptr->left;
                    
                    else
                        parent->left = ptr->right;
                    
                }
                else{
                    if (ptr->left != NULL)
                        parent->right = ptr->left;
                    
                    else
                        parent->right = ptr->right;
                }
                
            }
        }
        else
            printf("key not found");
    }
}

void traversal(struct tree *ptr){
    traversal(ptr->left);
    printf("%d",ptr->data);
    traversal(ptr->right);
}

void main()
{
    int choice;
    do
    {
        printf("1.insert\n2.search\n3.traverse\n4.delete\n0.EXIT");
        scanf("%d",&choice);
        switch (choice)
        {

        case 1:
            insertion();
            break;
        case 2: search();break;
        case 3: traversal(root); break;
        case 4: deletion(); break;
        default:
            break;
        }
    } while (choice != 0);
    
}