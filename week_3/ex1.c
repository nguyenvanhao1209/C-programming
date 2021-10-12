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
