#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tu{
    char word[20];
    int tanso;
};
typedef struct tu tu;
struct node{
    tu data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
typedef char chuoi[25];
node *insertNode(node *t, tu x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(strcmp(x.word,t->data.word)<0){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
node *searchNode(node *t,tu x){
  if(t == NULL) return NULL;
  else if(strcmp(x.word,t->data.word)==0) return t;
  else if(strcmp(x.word,t->data.word)<0) return searchNode(t->left,x);
  else return searchNode(t->right,x);
}
void printTree(node *t){
  if(t != NULL){
    printTree(t->left);
    printf("%-20s%-10d\n",t->data.word,t->data.tanso);
    printTree(t->right);
  }
}
int main(){
    char cau[100];
    fflush(stdin);
    gets(cau);
    char *token = strtok(cau," ");
    tu str[100];
    int n = 0;
	while(token != NULL){
		strcpy(str[n].word,token);
		n++;
		token = strtok(NULL," ");
    }
    node *t = NULL;
    int i;
    for(i=0;i<n;i++){
        str[i].tanso = 0;
    }
    for(i=0;i<n;i++){
        node *p = searchNode(t,str[i]);
        if(p == NULL){
            str[i].tanso++;
            t = insertNode(t,str[i]);
        }
        else{
            p->data.tanso++;
        }
    }
    printTree(t);
}