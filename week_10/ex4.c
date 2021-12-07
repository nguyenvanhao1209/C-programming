#include<stdio.h>
#include<string.h>
void insertionSort(char A[],int n){
	int i,j;
	char last;
	for(i=1;i<n;i++){
		last = A[i];
		j = i;
		while((j>0) && (A[j-1]>last)){
			A[j] = A[j-1];
			j--;
		}
		A[j] = last;
	}
	for(i=0;i<n;i++){
		printf("%c ",A[i]);
	}
}
int main(){
	char A[100];
	int i;
	for(i=0;i<10;i++){
		scanf("%c",&A[i]);
	}
	insertionSort(A,10);
}
