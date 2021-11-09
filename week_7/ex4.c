#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct infomation{
	char id[20];
	char name[20];
	float grade;
};
typedef struct infomation infomation;
int Bsearchgrade(infomation A[],int start,int finish,float b){
	int middle = (start + finish)/2;
	if(start == finish){
		if(A[middle].grade==b) return middle;
		else return -1;
	}
	if(A[middle].grade==b){
		return middle;
	}
	if(A[middle].grade<b){
		return Bsearchgrade(A,middle+1,finish,b);
	}
	else Bsearchgrade(A,start,middle-1,b);
}
int Bsearchname(infomation A[],int start,int finish,char b[]){
	int middle = (start + finish)/2;
	if(start == finish){
		if(strcmp(A[middle].name,b)==0) return middle;
		else return -1;
	}
	if(strcmp(A[middle].name,b)==0){
		return middle;
	}
	if(strcmp(A[middle].name,b)<0){
		return Bsearchname(A,middle+1,finish,b);
	}
	else Bsearchname(A,start,middle-1,b);
}
void timkiemdiem(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	infomation A[100];
	int n = 0;
	infomation value;
	while(!feof(f)){
		fscanf(f,"%s\t",value.id);
		printf("%s\t",value.id);
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%f\n",&value.grade);
		printf("%f\n",value.grade);
		A[n] = value;
		n++;
	}
	fclose(f);
	float diem;
	printf("nhap diem can tim: ");
	scanf("%f",&diem);
	int irc;
	irc = Bsearchgrade(A,0,n-1,diem);
	if(irc<0){
		printf("khong co trong danh sach\n");
	}
	else{
		printf("%-20s%-20s%-20.2f",A[irc].id,A[irc].name,A[irc].grade);
	}
}
void timkiemten(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	infomation A[100];
	int n = 0;
	infomation value;
	while(!feof(f)){
		fscanf(f,"%s\t",value.id);
		printf("%s\t",value.id);
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%f\n",&value.grade);
		printf("%f\n",value.grade);
		A[n] = value;
		n++;
	}
	fclose(f);
	char name[20];
	printf("nhap ten can tim: ");
	fflush(stdin);
	gets(name);
	int irc;
	irc = Bsearchname(A,0,n-1,name);
	if(irc<0){
		printf("khong co trong danh sach\n");
	}
	else{
		printf("%-20s%-20s%-20.2f",A[irc].id,A[irc].name,A[irc].grade);
	}
}
void menu(){
	printf("1. timtheoten\n");
	printf("2. timtheodiem\n");
	printf("3. Thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<4) return n;
	else return chonmenu();
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1: 
		    printf("1.timtheoten\n");
		    timkiemten();
		break;
		case 2:
			printf("2. timtheodiem\n");
			timkiemdiem();
			break;
		case 3:
			printf("3. Thoat\n");
			exit(1);
			break;		
	}
}
int main(){
	menu();
	while(1){
		xulymenu();
		printf("\n");
		menu();
	}
	return 0;
}
