#include<stdio.h>
#include<stdlib.h>

struct node {
  int coefficient, exponent;
  struct node *next;
};

struct node *hPtr1, *hPtr2, *hPtr3;
/*
 * creates new node and fill the given data
 */
struct node * buildNode(int coefficient, int exponent) {
  struct node *ptr = (struct node *) malloc(sizeof (struct node));
  ptr->coefficient = coefficient;
  ptr->exponent = exponent;
  ptr->next = NULL;
  return ptr;
}

/* insert data in decending order - based on exponent value */
void polynomial_insert(struct node ** myNode, int coefficient, int exponent) {
  struct node *lPtr, *pPtr, *qPtr = *myNode;
  lPtr = buildNode(coefficient, exponent);
  
  /* inserting new node at appropriate position */
  if (*myNode == NULL || (*myNode)->exponent < exponent) {
    *myNode = lPtr;
    (*myNode)->next = qPtr;
    return;
  }
  
  /* placing new node between two nodes or end of node */
  while (qPtr) {
    pPtr = qPtr;
    qPtr = qPtr->next;
    if (!qPtr) {
      pPtr->next = lPtr;
      break;
      
    } 
    else if ((exponent < pPtr->exponent) &&       (exponent > qPtr->exponent))
    lPtr->next = qPtr;
    pPtr->next = lPtr;
    break;
      }
    return;
  }
  
  /* inserting new node with resultant data into the output list (n1) */
  void polynomial_add(struct node **n1, int coefficient, int exponent) {
    struct node *x = NULL, *temp = *n1;
    if (*n1 == NULL || (*n1)->exponent < exponent) {
      /* adding at the front */
      *n1 = x = buildNode(coefficient, exponent);
      (*n1)->next = temp;
    } else {
      while (temp) {
    if (temp->exponent == exponent) {
      /* updating the co-efficient value  alone */
      temp->coefficient = temp->coefficient + coefficient;
      return;
    }
    if (temp->exponent > exponent && (!temp->next || temp->next->exponent < exponent)) {
      /* inserting in the middle or end */
      x = buildNode(coefficient, exponent);
      x->next = temp->next;
      temp->next = x;
      return;
    }
    temp = temp->next;
      }
      x->next = NULL;
      temp->next = x;
    }
  }
  
  void polynomial_multiply(struct node **n1, struct node *n2, struct node *n3) {
    struct node * temp;
    int coefficient, exponent;
    
    temp = n3;
    
    /* if both input list are absent, then output list is NULL */
    if (!n2 && !n3)
      return;
    
    /* input list 1(n2) is absent, then output list is input list2 (n3) */
    if (!n2) {
      *n1 = n3;
    } else if (!n3) {
      
      /*
       * list n3 is absent, then o/p list is n2
       */
      *n1 = n2;
    } else {
      while (n2) {
    while (n3) {
      /* multiply coefficient & add exponents */
      coefficient = n2->coefficient * n3->coefficient;
      exponent = n2->exponent + n3->exponent;
      n3 = n3->next;
      /* insert the above manipulated data to o/p list */
      polynomial_add(n1, coefficient, exponent);
    }
    n3 = temp;
    n2 = n2->next;
      }
    }
    return;
  }
  
  /* delete the given input list */
  struct node * polynomial_deleteList(struct node *ptr) {
    struct node *temp;
    while (ptr){
      temp = ptr->next;
      free(ptr);
      ptr = temp;
    }
    return NULL;
  }
  
  void polynomial_view(struct node *ptr) {
    int i = 0;
    int flag=0;
    while (ptr) {
      if(ptr->exponent != 0 || ptr->exponent != 1 ){
    if(ptr->coefficient > 0 && flag==0 ){
      printf("%dx^%d", ptr->coefficient,ptr->exponent);
      flag++;
    }
    else if (ptr->coefficient > 0 && flag==1 )
      printf("+%dx^%d", ptr->coefficient,ptr->exponent);
    else if(ptr->coefficient < 0)
      printf("%dx^%d", ptr->coefficient,ptr->exponent);
      }
      else if (ptr->exponent == 0){
    if(ptr->coefficient > 0 && flag==0 ){
      printf("%d", ptr->coefficient);
      flag++;
    }
    else if (ptr->coefficient > 0 && flag==1 )
      printf("+%d", ptr->coefficient);
    else if(ptr->coefficient < 0)
      printf("%d", ptr->coefficient);
      }
      else if( ptr->exponent == 1 ){
    if(ptr->coefficient > 0 && flag==0 ){
      printf("%dx", ptr->coefficient);
      flag++;
    }
    else if (ptr->coefficient > 0 && flag==1 )
      printf("+%dx", ptr->coefficient);
    else if(ptr->coefficient < 0)
      printf("%dx", ptr->coefficient);
      }
      ptr = ptr->next;
      i++;
    }
    printf("\n");
    return;
  }
  
  int main (int argc, char *argv[]) {
    int coefficient, exponent, i, n;
    int count;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
    printf("            Multiplication of Two Polynomials\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=\n");
    printf("Enter the number of coefficients in the multiplicand:");
    scanf("%d",&count);
    for(i=0;i<count;i++){
      printf("Enter the coefficient part:");
      scanf("%d", &coefficient);
      printf("Enter the exponent part:");
      scanf("%d",&exponent);
          polynomial_insert(&hPtr1, coefficient, exponent);
    }
    printf("Enter the number of coefficients in the multiplier:");
    scanf("%d",&count);
    for(i=0;i<count;i++){
      printf("Enter the coefficient part:");
      scanf("%d", &coefficient);
      printf("Enter the exponent part:");
      scanf("%d",&exponent);
          polynomial_insert(&hPtr2, coefficient, exponent);
    }
        printf("Polynomial Expression 1: ");
        polynomial_view(hPtr1);
        printf("Polynomial Expression 2: ");
        polynomial_view(hPtr2);
    
        polynomial_multiply(&hPtr3, hPtr1, hPtr2);
    
        printf("Output:\n");
        polynomial_view(hPtr3);
    
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        hPtr1 = polynomial_deleteList(hPtr1);
        hPtr2 = polynomial_deleteList(hPtr2);
        hPtr3 = polynomial_deleteList(hPtr3);
    
        return 0;
  
  }