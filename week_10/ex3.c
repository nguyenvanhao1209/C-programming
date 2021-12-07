#include<stdio.h>
#include<string.h>
struct address{
	char name[31];
	char email[31];
	char tel[31];
};
typedef struct address address;
int demchen = 0;
int demdong = 0;
void insertionSort(int A[],int n){
	int i,j,last;
	for(i=1;i<n;i++){
		last = A[i];
		j = i;
		while((j>0) && (A[j-1]>last)){
			demchen++;
			A[j] = A[j-1];
			j--;
		}
		A[j] = last;
	}
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\nso phep so sanh: %d",demchen);
}
void heapify(int arr[],int n,int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && arr[l]>arr[largest]){
		demdong++;
		largest = l;
	}
	if(r<n && arr[r]>arr[largest]){
		demdong++;
		largest = r;
	}
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);
	}
}
void heapSort(int arr[],int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=0;i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nso phep so sanh: %d",demdong);	
}
int main(){
	int A[] = {4,22,54,11,55,67,43,76,44,13,7,87,79};
	int B[] = {4,22,54,11,55,67,43,76,44,13,7,87,79};
	printf("SO SANH CHEN\n");
	insertionSort(A,13);
	printf("\n");
	printf("SO SANH DONG\n");	
	heapSort(A,13);
}
