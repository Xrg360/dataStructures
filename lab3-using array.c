// this is program to add two polynomials using arrays
#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
    int coeff;
    int exp;
};

//array implementation method 1
void main(){
    int i=0,j=0,k=0,n,m;
    struct polynomial p[10],q[10],r[10];
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &m);
    printf("Enter the coefficient and exponent of the first polynomial: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }
    printf("Enter the coefficient and exponent of the second polynomial: ");
    for (j = 0; j < m; j++)
    {
        scanf("%d%d", &q[j].coeff, &q[j].exp);
    }
    i=0;j=0;
    while (i<m&&j<m)
    {
        if (p[i].exp==q[j].exp)
        {
            r[k].exp=p[i].exp;
            r[k].coeff=p[i].coeff+q[j].coeff;
            i++;
            j++;     
            k++;
        }
        else if (p[i].exp>q[j].exp)
        {
            r[k].exp=p[i].exp;
            r[k].coeff=p[i].coeff;
            i++;
            k++;
        }
        else
        {
            r[k].exp=q[j].exp;
            r[k].coeff=q[j].coeff;
            j++;
            k++;
        }
    }
    while (i<n)
    {
        r[k].exp=p[i].exp;
        r[k].coeff=p[i].coeff;
        i++;
        k++;
    }
    while (j<m)
    {
        r[k].exp=q[j].exp;
        r[k].coeff=q[j].coeff;
        j++;
        k++;
    }
    printf("The resultant polynomial is: ");
    for (i = 0; i < k; i++)
    {
        if (r[i].coeff != 0)
        {
            printf("%dx^%d + ", r[i].coeff, r[i].exp);
        }
    }
}

//array implementation method2

// void main(){
//     struct polynomial p[10];
//     int i, j, k, n, m, flag;
//     printf("Enter the number of terms in the first polynomial: ");
//     scanf("%d", &n);
//     printf("Enter the number of terms in the second polynomial: ");
//     scanf("%d", &m);
//     printf("Enter the coefficient and exponent of the first polynomial: ");
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d%d", &p[i].coeff, &p[i].exp);
//     }
//     printf("Enter the coefficient and exponent of the second polynomial: ");
//     for (j = 0; j < m; j++)
//     {
//         scanf("%d%d", &p[i].coeff, &p[i].exp);
//         i++;
//     }
//     k = i;
//     for (i = 0; i < k; i++)    
//     {
//         flag = 0;
//         for (j = i + 1; j < k; j++)
//         {
//             if (p[i].exp == p[j].exp)
//             {
//                 p[i].coeff = p[i].coeff + p[j].coeff;
//                 p[j].coeff = 0;
//                 flag = 1;
//             }
//         }
//         if (flag == 1)
//         {
//             p[i].coeff = p[i].coeff + p[j].coeff;
//             p[j].coeff = 0;
//         }
//     }
//     printf("The resultant polynomial is: ");
//     for (i = 0; i < k; i++)
//     {
//         if (p[i].coeff != 0)
//         {
//             printf("%dx^%d", p[i].coeff, p[i].exp);
//         }
//     }   
// }
