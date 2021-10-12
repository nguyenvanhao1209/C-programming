#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char address[100];
struct Address_List{
	address addr;
	struct Address_List *next;
};
typedef struct Address_List AddressLis;
AddressLis *createAdd(address x){
	AddressLis *temp;
	temp = (AddressLis *)malloc(sizeof(AddressLis));
	temp->next = NULL;
	strcpy(temp->addr,x);
	return temp;
}
AddressLis *Insert(AddressLis *cur, address x){
	AddressLis *temp = createAdd(x);
	strcpy(temp->addr,x);
	cur->next = temp;
	return temp;
}
void printlist(AddressLis *root){
	AddressLis *temp;
	temp = root;
	while(temp != NULL){
		printf("%s\n",temp->addr);
		temp = temp->next;
	}
}
char *Delete_add(AddressLis *cur){
	char *x;
	AddressLis *temp;
	temp = cur->next;
	cur->next = cur->next->next;
	strcpy(x,temp->addr);
	free(temp);
	return x;
}
AddressLis *addHead(AddressLis *root, address x){
	AddressLis *temp;
	temp = (AddressLis *)malloc(sizeof(AddressLis));
	strcpy(temp->addr,x);
	temp->next = root;
	root = temp;
	return root;
}
AddressLis *addAt(AddressLis *root,int k,address x){
	AddressLis *p = root;
	int i;
	for(i=0;i<k-1;i++){
		p = p->next;
	}
	AddressLis *temp;
	temp = (AddressLis *)malloc(sizeof(AddressLis));
	strcpy(temp->addr,x);
	temp->next = p->next;
	p->next = temp;
	return root;
}
AddressLis *addTail(AddressLis *root,address x){
	AddressLis *p = root;
	while(p->next != NULL){
		p = p->next;
	}
	AddressLis *temp;
	temp = (AddressLis *)malloc(sizeof(AddressLis));
	strcpy(temp->addr,x);
	temp->next = NULL;
	p->next = temp;
	return root;	
}
AddressLis *insert(AddressLis *root, address x, int k,int n){
	if(n==0) addHead(root,x);
	else if(k == n) addTail(root,x);
	else addAt(root,k,x);
}
AddressLis *deleteHead(AddressLis *root){
	AddressLis *p = root;
	p = p->next;
	free(root);
	return p;	
}
AddressLis *deleteTail(AddressLis *root){
	AddressLis *p = root;
	while(p->next->next != NULL){
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	return root;
}
AddressLis *deleteAt(AddressLis *root,int k){
	AddressLis *p = root;
	int i;
	for(i=0;i<k-1;i++){
		p = p->next;
	}
	AddressLis *temp = p->next;
	p->next = p->next->next;
	free(temp);
	return root;
}
AddressLis *deletes(AddressLis *root,int k,int n){
	if(k==0) deleteHead(root);
	else if(k==n) deleteTail(root);
	else deleteAt(root,k);
}
int main(){
	int n;
	address x;
	scanf("%d",&n);
	gets(x);
	AddressLis *root = createAdd(x);
	AddressLis *p = root;
	int i;
	for(i=1;i<n;i++){
		gets(x);
		p = Insert(p,x);
	}
	printlist(root);
	return 0;
}
