#include<stdio.h>
#include<stdlib.h>
int dem = 0;
int Bsearch(int A[],int start,int finish,int b){
	int middle = (start + finish)/2;
	dem++;
	if(start == finish){
		if(A[middle]==b) return middle;
		else return -1;
	}
	if(b==A[middle]){
		return middle;
	}
	if(A[middle]<b){
		return Bsearch(A,middle+1,finish,b);
	}
	else Bsearch(A,start,middle-1,b);
}
int main(){
	int a[10];
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int b;
	scanf("%d",&b);
	printf("%d",Bsearch(a,0,9,b));
	printf("\n%d",dem);
	return 0;
}
