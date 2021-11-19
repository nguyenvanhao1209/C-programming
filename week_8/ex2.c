#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *insertNode(node *t, int x){
	if(t == NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if(x<t->data){
			t->left = insertNode(t->left,x);
		}
		else{
			t->right = insertNode(t->right, x);
		}
	}
}
void freeTree(node *t){
  if(t != NULL){
    freeTree(t->left);
    freeTree(t->right);
    free(t);
  }
}
void printTree(node *t){
  if(t != NULL){
    printTree(t->left);
    printf("%d ",t->data);
    printTree(t->right);
  }
}
int main(){
	int n;
	scanf("%d",&n);
	int x;
	node *t = NULL;
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&x);
		t = insertNode(t,x);
	}
  printTree(t);
  freeTree(t);
}
