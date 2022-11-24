#include<stdio.h>
int n,m,r,c,i=0,j=0,k=1;
int a[10][10],b[10][10],a1[10][10],b1[10][10],c1[10][10];
void input(int x[10][10]){
    for(int i=0;i<r;i++){
        for (int j = 0; j < c; j++)
        {
            scanf("%d",&x[i][j]);
        }
        
    }
}
void tup_conv(int x[10][10],int y[10][10]){
     i=j=0;
     k=1;
    for ( i = 0; i < r; i++)
    {
        for (  j = 0; j < c; j++)
        {
            if(x[i][j]!=0){
                y[k][0]=i;
                y[k][1]=j;
                y[k][2]=x[i][j];
                k++;
            }
        }
        
    }
    y[0][0] = r;
    y[0][1] = c;
    y[0][2] = k-1;
}
void display(int x[10][10]){
    for ( i = 0; i <= x[0][2]; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d ",x[i][j]);
        }
        printf("\n");
    }
}
void sparse_add(){
    if (a1[0][0] == b1[0][0] && a1[0][1] == b1[0][1])
    {
        printf("addition possible..\n");
         i=1;
         j=1;
         k=1;
        while (i<=a1[0][2] && j<=b1[0][2])
        {
            if (a1[i][0]<b1[j][0] || a1[i][1]<b1[j][1])
            {
                c1[k][0] = a1[i][0];
                c1[k][1] = a1[i][1];
                c1[k][2] = a1[i][2];
                i++;
                k++;
            }
            else if (a1[i][0]>b1[j][0] || a1[i][1]>b1[j][1])
            {
                c1[k][0] = b1[j][0];
                c1[k][1] = b1[j][1];
                c1[k][2] = b1[j][2];
                j++;
                k++;
            }
            else if (a1[i][1] == b1[j][1])
            {
                c1[k][0] = a1[i][0];
                c1[k][1] = a1[i][1];
                c1[k][2] = a1[i][2] + b1[j][2];
                i++;
                j++;
                k++;
            }
            
        }
        while (i<=a1[0][2])
        {
            c1[k][0] = a1[i][0];
            c1[k][1] = a1[i][1];
            c1[k][2] = a1[i][2];
            i++;
            k++;
        }
        while (j<=b1[0][2])
        {
            c1[k][0] = b1[j][0];
            c1[k][1] = b1[j][1];
            c1[k][2] = b1[j][2];
            j++;
            k++;
        }
        c1[0][0] = a1[0][0];
        c1[0][1] = a1[0][1];
        c1[0][2] = k-1;
        
        
    }
    else
        printf("not possible");
    
}
void main(){
    printf("enter the rows and columns :");
    scanf("%d %d",&r,&c);
    printf("first matrix\n");
    input(a);
    printf("second matrix\n");
    input(b);
    tup_conv(a,a1);
    tup_conv(b,b1);
    printf("tuple\n");
    display(a1);
    printf("tuple2\n");
    display(b1);
    printf("sum\n");
    sparse_add();
    display(c1); 
    
}