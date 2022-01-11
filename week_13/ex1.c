#include<stdio.h>
#include<string.h>

int bruteforcematch(char T[], char P[],int n, int m){
	int j = 0;
	int count = 0;
	int i;
	for(i=0;i<(n-m);i++){
		for(j=0;j<m && P[j] == T[i+j];j++);
		if(j>=m){
			count++;
		}
	}
	return count;
}

int main(){
	char P[] = "aadbf";
	char T[] = "baadbfcadacaeeeffaadbfacddedcedfbaadbfecaadbfcaeaadbf";
	int n = strlen(T);
	int m = strlen(P);
	int solan = bruteforcematch(T,P,n,m);
	printf("mau xuat hien %d lan trong chuoi",solan);
}
