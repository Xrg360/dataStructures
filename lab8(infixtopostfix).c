#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char e[100], x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    strcpy(e,exp);
    int i=0;
    while(e[i] != '\0')
    {
        if(isalnum(e[i]))
            printf("%c ",e[i]);
        else if(e[i] == '(')
            push(e[i]);
        else if(e[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(e[i]))
                printf("%c ",pop());
            push(e[i]);
        }
        i++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
