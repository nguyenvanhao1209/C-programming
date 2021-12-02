#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct phoneaddress{
  char name[20];
  char tel[11];
  char email[25];
};
typedef struct phoneaddress phoneaddress;
struct node{
  phoneaddress data;
  struct node *left;
  struct node *right;
};
typedef struct node node;
node *insertNode(node *t, phoneaddress x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(strcmp(x.email,t->data.email)<0){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,phoneaddress x){
  if(t == NULL) return NULL;
  else if(strcmp(x.email,t->data.email)==0) return t;
  else if(strcmp(x.email,t->data.email)<0) return searchNode(t->left,x);
  else return searchNode(t->right,x);
}
void printTree(node *t){
  if(t != NULL){
    printTree(t->left);
    printf("%-20s%-20s%-20s\n",t->data.name,t->data.email,t->data.tel);
    printTree(t->right);
  }
}
int main(){
<<<<<<< HEAD
  FILE *f;
  f = fopen("week_8/phonebook.txt","r");
  node *t = NULL;
  phoneaddress x;
  while(!feof(f)){
    fscanf(f,"%s\t",x.name);
    fscanf(f,"%s\t",x.email);
    fscanf(f,"%s\n",x.tel);
    t = insertNode(t,x);
  }
  fclose(f);
  phoneaddress tim;
  printf("nhap email can tim: ");
=======
  FILE *fp;
  phoneaddress phonearr[MAX];
  TreeType root;
  int i,n;
  int n=10;
  if((fp = fopen("phonebook.txt","r")) == NULL){
    printf("Can not open %s.\n", "phonebook.txt");
  }
  for(i=0;i<n;i++){
    fscanf(fp,"%s\t",phonearr[i].name);
    fscanf(fp,"%s\t",phonearr[i].email);
    fscanf(fp,"%s\n",phonearr[i].tel);
  }
  fclose(fp);
  for (i=0; i<n; i++)
     InsertNode(phonearr[i],root);
  printTree(root);
  char s[25];
>>>>>>> d8818a31d8d1acc7e279ed1938cd9c0ac3f5d843
  fflush(stdin);
  gets(tim.email);
  node *p = searchNode(t,tim);
  if(p != NULL) printf("%-20s%-20s%-20s\n",p->data.name,p->data.email,p->data.tel);
  else printf("khong tim thay\n");
}

