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
	char a[] = "5 4 + 6 *";
	int i;
	N = strlen(a);
	STACKinit(N);
	for (i = 0; i < N; i++){
		if (a[i] == '+') STACKpush(STACKpop()+STACKpop());
		if (a[i] == '*') STACKpush(STACKpop()*STACKpop());
		if ((a[i] >= '0') && (a[i] <= '9')) STACKpush(0);
		while ((a[i] >= '0') && (a[i] <= '9')) STACKpush(10*STACKpop() + (a[i++]-'0'));	
	}
	printf("%d \n", STACKpop());
}

