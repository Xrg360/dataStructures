#include <stdio.h>
#include <stdlib.h>
#define m 7
int a[m]; //for oppen address
typedef struct hashTable{
	int data;
	struct hashTable *next;
}hashTable;  //each node in the chain

void hashing(int item);
int hash(int);
void openaddressing();
void chaining();

void main(){
    int ch,e;
    do
    {
    printf("The hash function using is key%7\n");
    printf("MENU\n");
    printf("1. Open addressing\n2. Chaining\n");
    printf("Read your option(1/2)");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        openaddressing();
        break;
        case 2:
        chaining();
        break;
    }
    printf("Do you continue?(0 for end,1 for continue)\n");
    scanf("%d",&e);
    }while(e!=0);
}
void chaining()
{
   hashTable **T;
   int n,key;
	T = (hashTable**)malloc(sizeof(hashTable*)*m); //create table of size m
	for(int i=0;i<m;i++)
		T[i]=NULL;   
	printf("Enter THE NO OF ELEMENTS:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	int h;
	for(int i =0;i<n;i++){
		scanf("%d",&key);
		h = hash(key);
		
		hashTable *newnode = (hashTable*)malloc(sizeof(*newnode));
		newnode->next=NULL;
		newnode->data=key;
		
		if(T[h] != NULL){
			newnode->next = T[h];
		}
		T[h] = newnode;
	}
	printf("\n The List are\n");
	for(int i=0;i<m;i++){
		printf("List %d: ",i);
		
		if(T[i]==NULL)
			printf("Empty\n");
		else{
			hashTable *temp = T[i];
			while(temp!=NULL){
				printf("%d ",temp->data);
				temp = temp->next;
			}
			printf("\n");
		}
	}
	//return 0;
}
int hash(int key){
	return key%m;
	
}
void openaddressing(){
  
    int i,item;
    for (i=0;i<m;i++){
        a[i]=-1;
    } // set all values -1
    for (i=0;item!=-1;i++){
        printf("Enter data to be inserted:(Read -1 to stop)\n ");
        scanf("%d",&item);
        hashing(item);
    }  
}
void hashing(int item){
    int h,i,flag=0;
    for (i=0;i<m;i++){
        int h1=item%m;
        h=(h1+i)%m;
        if (a[h]==-1){
            a[h]=item;
            flag=1;
            break;
        }
        else{
            flag=0;
        }
    }
    if (flag==0){
        printf("Table Oveflow....\n");
        printf("Insertion not possible");
        exit(0);
    }
    else{
        printf("Hash table: \n");
        for (i=0;i<m;i++){
            printf("%d ",a[i]);
        }
    }
    printf("\n");
}
