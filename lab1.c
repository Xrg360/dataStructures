//this program represents how to insert, delete, sum and display the elements of a array
#include<stdio.h>
int n,a[100];
void main(){
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the elements of the array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    do{
        printf("Enter the choice\n1.Insert\n2.Delete\n3.Sum\n4.Display\n5.Exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                sum();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }while(1);
    
}
void insert(){
    int pos,val;
    printf("Enter the position and value to be inserted");
    scanf("%d%d",&pos,&val);
    for(int i=n; i >= pos ;i--){
        a[i]=a[i-1];
    }
    a[pos-1]=val;
    n++;
}
void delete(){
    int pos;
    printf("Enter the position to be deleted");
    scanf("%d",&pos);
    for(int i=pos;i<n;i++){
        a[i]=a[i+1];
    }
    n--;
}
void sum(){
    int sum;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    printf("The sum of the elements is %d",sum);
}
void display(){
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}