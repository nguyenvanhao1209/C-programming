#include<stdio.h>
#include<string.h>
struct address{
	char name[31];
	char email[31];
	char tel[31];
};
typedef struct address address;
int dem = 0;
void heapify(address arr[],int n,int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && strcmp(arr[l].email,arr[largest].email)>0){
		largest = l;
	}
	if(r<n && strcmp(arr[r].email,arr[largest].email)>0){
		largest = r;
	}
	dem++;
	if(largest != i){
		address temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);
	}
}
void heapSort(address arr[],int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(i=n-1;i>=0;i--){
		address temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}	
}
int main(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/test.txt","r");
	address x;
	address A[100];
	int n=0;
	while(!feof(f)){
		fscanf(f,"%s\t",x.name);
		fscanf(f,"%s\t",x.email);
		fscanf(f,"%s\n",x.tel);
		A[n] = x;
		n++;
	}
	heapSort(A,n);
	int i;
	for(i=0;i<n;i++)
		printf("%-20s%-20s%-20s\n",A[i].name,A[i].email,A[i].tel);
	printf("so phep so sanh: %d",dem);	
}
