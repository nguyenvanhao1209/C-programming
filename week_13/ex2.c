#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
 
#define MAX 256
 
void badcharheuristic(char P[], int m, int badchar[MAX]){
	int i;
	for(i=0;i<MAX;i++){
		badchar[i] = -1;
	}
	for(i=0;i<m;i++){
		badchar[(int) P[i]] = i;
	}
}
int max(int a,int b){
	return (a >= b) ? a : b; 
}
void boyermoore(char T[], char P[], int n, int m){
	int badchar[MAX];
	badcharheuristic(P,m,badchar);
	int i = 0;
	while(i <= (n-m)){
		int j = m - 1;
		while(j >= 0 && P[j] == T[i+j]) j--;
		if(j<0){
			printf("mau xuat hien o vi tri %d\n",i);
			i += (i + m < n) ? m - badchar[T[i+m]] : 1;
		}
		else{
			i += max(1, j - badchar[T[i+j]]);
		}
	}
}
int main(){
	char T[] = "abcadacaeeeffabcdefaadbfacddedcedfbeabcdefccaeabcdef";
	char P[] = "abcdef";
	int n = strlen(T);
	int m = strlen(P);
	boyermoore(T,P,n,m);
}
