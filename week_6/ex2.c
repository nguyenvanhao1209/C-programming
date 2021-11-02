#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10];
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int b;
	scanf("%d",&b);
	int dem = 0;
	for(i=0;i<10;i++){
		if(a[i]==b){
			printf("%d ",i+1);
			dem++;
		}
	}
	if(dem==0){
		printf("0");
	}
	return 0;
}
