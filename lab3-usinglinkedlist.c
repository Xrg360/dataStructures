#include<stdio.h>
//linked list implementation
struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create(struct node *head)
{
    int n, i;
    struct node *newnode, *temp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent of the term: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    return head;
}