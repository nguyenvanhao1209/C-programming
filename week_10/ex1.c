#include<stdio.h>
#include<string.h>
struct address{
	char name[31];
	char email[31];
	char tel[31];
};
typedef struct address address;
int demchon = 0;
int demchen = 0;
void insertionSort(address A[],int n){
	int i,j;
	address last;
	for(i=1;i<n;i++){
		last = A[i];
		j = i;
		while((j>0) && strcmp(A[j-1].email,last.email)>0){
			demchen++;
			A[j] = A[j-1];
			j--;
		}
		A[j] = last;
	}
	for(i=0;i<n;i++)
		printf("%-20s%-20s%-20s\n",A[i].name,A[i].email,A[i].tel);
	printf("so phep so sanh: %d",demchen);
}
void selectionSort(address A[],int n){
	int i,j;
	int min;
	address temp;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(strcmp(A[min].email,A[j].email)>0){
				min = j;
			}
			demchon++;
		}
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;
	}
	for(i=0;i<n;i++)
		printf("%-20s%-20s%-20s\n",A[i].name,A[i].email,A[i].tel);
	printf("so phep so sanh: %d",demchon);
}
int main(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/test.txt","r");
	address x;
	address A[100];
	int n=0;
	address B[100];
	while(!feof(f)){
		fscanf(f,"%s\t",x.name);
		fscanf(f,"%s\t",x.email);
		fscanf(f,"%s\n",x.tel);
		A[n] = x;
		B[n] = x;
		n++;
	}
	printf("SAP XEP CHEN\n");
	insertionSort(A,n);
	printf("\n");
	printf("SAP XEP CHON\n");
	selectionSort(B,n);
	
}
