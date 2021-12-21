#include<stdio.h>
#include<string.h>
struct address{
	char name[31];
	char email[31];
	char tel[31];
};
typedef struct address address;
void merge(address A[],int l,int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	address L[n1];
	address R[n2];
	for(i=0;i<n1;i++){
		L[i] = A[l+i];
	}
	for(j=0;j<n2;j++){
		R[j] = A[m+1+j];
	}
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(strcmp(L[i].email,R[j].email)<=0){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		A[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(address A[],int l,int r){
	if(l<r){
		int m = l+(r-l)/2;
		mergeSort(A, l, m);
		mergeSort(A, m+1, r);
		merge(A, l, m, r);
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
		fscanf(f,"%s\t",x.tel);
		fscanf(f,"%s\n",x.email);
		A[n] = x;
		n++;
	}
	mergeSort(A,0,n-1);
	int i;
	for(i=0;i<n;i++)
		printf("%-20s%-20s%-20s\n",A[i].name,A[i].email,A[i].tel);
}
