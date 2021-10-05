#include<stdio.h>
#include<ctype.h>
enum {SUCCESS, FAIL, MAX_LEN = 81};
int main(int argc, char *argv[]){
	FILE *fptr;
	char filename[]= "lab.txt";
	char s[100];
	int i=0;
	int reval = SUCCESS;
	if ((fptr = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", filename);
		reval = FAIL;
	}else {
		while(!feof(fptr)){
			fgets(s,100,fptr);
			printf("%d %s\n",++i,s);
		}
		fclose(fptr);
	}
	return reval;
}
