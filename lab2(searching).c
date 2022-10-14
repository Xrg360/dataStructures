//this program implements the basic of linear and binary search
#include<stdio.h>
int a[100],b[100],n,i,j,temp,ele,flag=0,left,right,mid;
void bin_search(){
    printf("Enter the element to be searched");
    scanf("%d",&ele);
    left=0;
    right=n-1;
    while(left<=right){
        mid=(left+right)/2;
        if(b[mid]==ele){
            flag=1;
            break;
        }
        else if(b[mid]>ele){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    if(flag==1){
        printf("Element found at position %d",mid+1);
    }
    else{
        printf("Element not found");
    }
}
void sort(){
    for (int i = 0; i < n; i++)
    {
        b[i]=a[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(b[j]>b[j+1]){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
}
void lin_search(){
    // searching the element using linear search
    printf("Enter the element to be searched");
    scanf("%d",&ele);
    for(i=0;i<n;i++){
        if(a[i]==ele){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Element found at %d",i+1);
    }
    else{
        printf("Element not found");
    }

}
void main(){
    
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    printf("Enter the elements of the array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    
    //sorting the array
    sort();
    //searching using binary search
    bin_search();
    //searching using linear search
    lin_search();
   

    
}