#include<stdio.h>

#define MAX_SIZE 1000
int Bsearch(int A[],int start,int finish,int b){
	while(start <= finish){
		int middle = (start + finish)/2;
		if(A[middle]<b){
			start = middle + 1;
		}
		else if(A[middle]>b){
			finish = middle - 1;
		}
		else{
			return middle;
		}
	}
	return -1;
}
void verify(int A1[],int A2[],int n,int m){
	int i,j;
	int marked[MAX_SIZE];
	for(i=0;i<m;i++){
		marked[i] = 0;
	}
	for(i=0;i<n;i++){
		j = Bsearch(A2,0,m-1,A1[i]);
		if(j<0){
			printf("%d is not in list 2\n",A1[i]);
		}
		else marked[j] = 1;
	}
	for(i=0;i<m;i++){
		if(!marked[i]){
			printf("%d is not in list 1\n",A2[i]);	
		}
	}
}

int main(){
	int A1[MAX_SIZE];
	int A2[MAX_SIZE];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&A1[i]);
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&A2[i]);
	}
	verify(A1,A2,n,m);
}
