#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct address{
	char name[20];
	char telephone[20];
	char email[20];
};
typedef struct address address;
void timtheoten(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if (f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return 1;
    }
    address M[100];
    address value;
    int n=0;
    while(!feof(f)){
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%s\t",value.telephone);
		printf("%s\t",value.telephone);
		fscanf(f,"%s\n",value.email);
		printf("%s\n",value.email);
		M[n] = value;
		n++;
	}
	fclose(f);
	int i;
	char s[20];
	printf("nhap ten can tim: ");
	fflush(stdin);
	gets(s);
	FILE *f1;
	f1 = fopen("C:/Users/Administrator/Desktop/test.txt","w");
	if (f1 == NULL)
    {
    	perror("Khong the mo tep de ghi.\n");
		return 1;
    }
	for(i=0;i<n;i++){
		if(strcmp(M[i].name,s)==0){
			fprintf(f1,"%s\t",M[i].name);
			printf("%s\t",M[i].name);
			fprintf(f1,"%s\t",M[i].telephone);
			printf("%s\t",M[i].telephone);
			fprintf(f1,"%s\n",M[i].email);
			printf("%s\n",M[i].email);
		}
	}
	fclose(f1);
}
void timtheosdt(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if (f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return 1;
    }
    address M[100];
    address value;
    int n=0;
    while(!feof(f)){
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%s\t",value.telephone);
		printf("%s\t",value.telephone);
		fscanf(f,"%s\n",value.email);
		printf("%s\n",value.email);
		M[n] = value;
		n++;
	}
	fclose(f);
	int i;
	char s[20];
	printf("nhap ten can tim: ");
	fflush(stdin);
	gets(s);
	FILE *f1;
	f1 = fopen("C:/Users/Administrator/Desktop/test.txt","w");
	if (f1 == NULL)
    {
    	perror("Khong the mo tep de ghi.\n");
		return 1;
    }
	for(i=0;i<n;i++){
		if(strcmp(M[i].telephone,s)==0){
			fprintf(f1,"%s\t",M[i].name);
			printf("%s\t",M[i].name);
			fprintf(f1,"%s\t",M[i].telephone);
			printf("%s\t",M[i].telephone);
			fprintf(f1,"%s\n",M[i].email);
			printf("%s\n",M[i].email);
		}
	}
	fclose(f1);
}
void timtheoemail(){
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if (f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return 1;
    }
    address M[100];
    address value;
    int n=0;
    while(!feof(f)){
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%s\t",value.telephone);
		printf("%s\t",value.telephone);
		fscanf(f,"%s\n",value.email);
		printf("%s\n",value.email);
		M[n] = value;
		n++;
	}
	fclose(f);
	int i;
	char s[20];
	printf("nhap ten can tim: ");
	fflush(stdin);
	gets(s);
	FILE *f1;
	f1 = fopen("C:/Users/Administrator/Desktop/test.txt","w");
	if (f1 == NULL)
    {
    	perror("Khong the mo tep de ghi.\n");
		return 1;
    }
	for(i=0;i<n;i++){
		if(strcmp(M[i].email,s)==0){
			fprintf(f1,"%s\t",M[i].name);
			printf("%s\t",M[i].name);
			fprintf(f1,"%s\t",M[i].telephone);
			printf("%s\t",M[i].telephone);
			fprintf(f1,"%s\n",M[i].email);
			printf("%s\n",M[i].email);
		}
	}
	fclose(f1);
}
void menu(){
	printf("1. timtheoten\n");
	printf("2. timtheosdt\n");
	printf("3. timtheoemail\n");
	printf("4. Thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<5) return n;
	else return chonmenu();
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1: 
		    printf("1.timtheoten\n");
		    timtheoten();
		break;
		case 2:
			printf("2. timtheosdt\n");
			timtheosdt();
			break;
		case 3:
		    printf("3. timtheoemail\n");
		    timtheoemail();
			break;
		case 4:
			printf("4. Thoat\n");
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
