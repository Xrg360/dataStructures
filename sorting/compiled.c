#include<stdio.h>
void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void Insertion_Sort(){
    printf("enter size of the array : ");
    int n,A[100];
    scanf("%d",&n);
    for(int  i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    printArray(A, n);
    int key, j;
    for (int i = 1; i <= n-1; i++){
        key = A[i];
        j = i-1;
        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    printf("Sorted array is\n");
    printArray(A, n);
}

void Selection_Sort(){
    printf("enter size of the array : ");
    int n,A[100];
    scanf("%d",&n);
    for(int  i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    printArray(A, n);
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++){
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;

    }
    printf("Sorted array is\n");
    printArray(A, n);
}

void Merge_Sort(){
    printf("enter size of the array : ");
    int n,A[100];
    scanf("%d",&n);
    for(int  i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    printArray(A, n);
    merge_sort(A,0,n-1);
    printf("Sorted array is\n");
    printArray(A, n);
}
void merge(int A[], int mid, int low, int high)
{
    int B[100];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void merge_sort(int *A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

void Heap_Sort(){
    printf("enter size of the array : ");
    int n,A[100];
    scanf("%d",&n);
    for(int  i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
	printArray(A, n);
    heapSort(A, n);
	printf("Sorted array is\n");
	printArray(A,n);
}
void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}
void heapify(int arr[], int N, int i){
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < N && arr[left] > arr[largest])

		largest = left;
	if (right < N && arr[right] > arr[largest])

		largest = right;
	if (largest != i) {

		swap(&arr[i], &arr[largest]);
		heapify(arr, N, largest);
	}
}
void heapSort(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
void Quick_Sort(){
    printf("enter size of the array : ");
    int n,A[100];
    scanf("%d",&n);
    for(int  i = 0; i < n; i++){
        scanf("%d",&A[i]);
    }
    
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printf("Sorted array is\n");
    printArray(A, n);
}
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}
void main(){
    int choice;
    do{
        printf("enter the choice\n");
        printf("1.Insertion Sort\n2.Selection Sort\n3.Merge Sort\n4.Quick Sort\n5.Heap Sort - ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            Insertion_Sort();
            break;
        case 2:
            Selection_Sort();
            break;
        case 3:
            Merge_Sort();
            break;
        case 4:
            Quick_Sort();
            break;
        case 5:
            Heap_Sort();
            break;
        
        default:
            break;
        }
    }while(choice!=0);
}