#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct address{
	char telephone[20];
	char name[20];
	char email[20];
};
typedef struct address address;
int Bsearch(address A[],int start,int finish,char b[]){
	int middle = (start + finish)/2;
	if(start == finish){
		if(strcmp(A[middle].name,b)==0) return middle;
		else return -1;
	}
	if(strcmp(A[middle].name,b)==0){
		return middle;
	}
	if(strcmp(A[middle].name,b)<0){
		return Bsearch(A,middle+1,finish,b);
	}
	else Bsearch(A,start,middle-1,b);
}
int main(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if (f == NULL){
		perror("Khong the mo tep de doc.\n");
		return 1;
	}
	address A[100];
	int n = 0;
	address value;
	while(!feof(f)){
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%s\t",value.telephone);
		printf("%s\t",value.telephone);
		fscanf(f,"%s\n",value.email);
		printf("%s\n",value.email);
		A[n] = value;
		n++;
	}
	fclose(f);
	FILE *f1;
	f1 = fopen("C:/Users/Administrator/Desktop/test.txt","w");
	if (f1 == NULL){
		perror("Khong the mo tep de ghi.\n");
		return 1;
	}
	char name[20];
	printf("nhap ten can tim: ");
	gets(name);
	int irc;
	irc = Bsearch(A,0,n-1,name);
	if(irc<0){
		printf("khong co trong danh sach\n");
	}
	else{
		printf("%-20s%-20s%-20s",A[irc].name,A[irc].telephone,A[irc].email);
	}
	return 0;
}
