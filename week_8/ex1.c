#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
int EmptyTree(node *t){
	return t==NULL;
}
node *LeftChild(node *t){
	if(t != NULL) return t->left;
	else return NULL;
}
node *RightChild(node *t){
	if(t != NULL) return t->right;
	else return NULL;
}
int Isleaf(node *p){
	if(p != NULL){
		return LeftChild(p) == NULL && RightChild(p) == NULL;
	}
	else return -1;
}
int countNode(node *t){
	if(EmptyTree(t)) return 0;
	else return 1 + countNode(LeftChild(t)+RightChild(t));
}
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
int countLeaf(node *t){
	if(t == NULL) return 0;
	if(t->left == NULL && t->right == NULL) return 1;
	return countLeaf(t->left) + countLeaf(t->right);
}
int height(node *t){
	if(t == NULL) return 0;
	int ld = height(t->left);
	int rd = height(t->right);
	return 1 + (ld > rd ? ld : rd);
}
int countInternal(node *t){
	return countNode(t) - countLeaf(t);
}
int countRight(node *t){
	if(t == NULL) return 0;
	if(t->right != NULL) return 1;
	return 1+ countRight(t->left) + countRight(t->right);
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
	printf("height: %d\n",height(t));
	printf("number of leafs: %d\n",countLeaf(t));
	printf("number of internal nodes: %d\n",countInternal(t));
	printf("number of right children: %d\n",countRight(t));
}
