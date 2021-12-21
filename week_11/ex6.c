#include<stdio.h>
void recurTriangle(int n,char ch){
	int i;
	for(i=0;i<n;i++){
		printf("%c",ch);
	}
	n = n-1;
	printf("\n");
	if(n>0){
		recurTriangle(n,ch);
	}
}
int main(){
	int n = 7;
	char ch = '+';
	recurTriangle(n,ch);
}
