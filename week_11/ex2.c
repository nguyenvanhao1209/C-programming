#include<stdio.h>
void quickSort(int A[],int l,int r){
	int p = A[(l+r)/2];
	int i = l,j = r;
	while(i<j){
		while(A[i]<p){
			i++;
		}
		while(A[j]>p){
			j--;
		}
		if(i<=j){
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}
	if(i<r){
		quickSort(A,i,r);
	}
	if(l<j){
		quickSort(A,l,j);
	}
}
void insertionSort(int A[],int n){
	int i,j,last;
	for(i=1;i<n;i++){
		last = A[i];
		j = i;
		while((j>0) && (A[j-1]>last)){
			A[j] = A[j-1];
			j--;
		}
		A[j] = last;
	}
}
int main(){
	int n;
	int A[100];
	int B[100];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
		B[i] = A[i];
	}
	printf("SAP XEP CHEN\n");
	insertionSort(A,n);
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	printf("SAP XEP NHANH\n");
	quickSort(B,0,n-1);	
	for(i=0;i<n;i++){
		printf("%d ",B[i]);
	}	
}
