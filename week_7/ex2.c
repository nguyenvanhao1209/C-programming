#include<stdio.h>
int dem = 0;
int Bsearch(int A[],int start,int finish,int b){
	while(start <= finish){
		int middle = (start + finish)/2;
		if(A[middle]<b){
			dem++;
			start = middle + 1;
		}
		else if(A[middle]>b){
			dem++;
			finish = middle - 1;
		}
		else{
			dem++;
			return middle;
		}
	}
	return -1;
}
int main(){
	int i;
	int A[100];
	for(i = 0 ; i < 100 ; i++){
		A[i] = i + 1;
	}
	int b;
	scanf("%d",&b);
	printf("%d",Bsearch(A,0,99,b));
	printf("\n%d",dem);
	return 0;
}
