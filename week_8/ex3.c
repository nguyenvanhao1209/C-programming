#include <stdio.h>
#include <stdlib.h>
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
node *searchNode(node *t,int x){
  if(t == NULL) return NULL;
  else if(t->data == x) return t;
  else if(t->data < x) return searchNode(t->right,x);
  else return searchNode(t->left,x);
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
  node *p;
  do{
    printf("Enter key to search (-1 to quit):");
    scanf("%d",&x);
     p = searchNode(t,x);
    if (p!=NULL) printf("Key %d found on the tree",n);
    else printTree(p);
  }while(n != -1);
  return 0;
}
