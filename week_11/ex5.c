#include<stdio.h>
#include<string.h>
typedef char name[31];
void quickSort(name A[],int l,int r){
	name p;
	strcpy(p,A[(l+r)/2]);
	int i = l,j = r;
	while(i<j){
		while(strcmp(A[i],p)<0){
			i++;
		}
		while(strcmp(A[j],p)>0){
			j--;
		}
		if(i<=j){
			name temp;
			strcpy(temp,A[i]);
			strcpy(A[i],A[j]);
			strcpy(A[j],temp);
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
	int n;
	scanf("%d",&n);
	name A[100];
	int i;
	for(i=0;i<n;i++){
		fflush(stdin);
		scanf("%s",A[i]);
	}
	quickSort(A,0,n-1);
	for(i=0;i<n;i++){
		printf("%s ",A[i]);
	}
}
