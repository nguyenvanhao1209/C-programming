#include<stdio.h>
#include<string.h>
struct address{
	char name[31];
	char email[31];
	char tel[31];
};
typedef struct address address;
void quickSort(address A[],int l,int r){
	address p = A[(l+r)/2];
	int i = l,j = r;
	while(i<j){
		while(strcmp(A[i].email,p.email)<0){
			i++;
		}
		while(strcmp(A[j].email,p.email)>0){
			j--;
		}
		if(i<=j){
			address temp = A[i];
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
	fclose(f);
	quickSort(A,0,n-1);
	printf("\n");
		int i;
	for(i=0;i<n;i++)
		printf("%-20s%-20s%-20s\n",A[i].name,A[i].email,A[i].tel);
}
