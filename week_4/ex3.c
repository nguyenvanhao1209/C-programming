#include<stdio.h>
#include<stdlib.h>
static char *s;
static int N;
void STACKinit(int maxN){ 
	s = malloc(maxN*sizeof(char));
}
int STACKempty(){
	return N == 0; 
}
void STACKpush(char item){
	s[N++] = item; 
}
char STACKpop(){
	return s[--N];
}
int main(){
	char a[] = "3 + 5 * 4";
	int i;
	N = strlen(a);
	STACKinit(N);
	for (i = 0; i < N; i++){
		if (a[i] == ')') printf("%c ", STACKpop());
		if ((a[i] == '+') || (a[i] == '*')) STACKpush(a[i]);
		if ((a[i] >= '0') && (a[i] <= '9')) printf("%c ", a[i]);
	}
	printf("\n");
}

