#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char address[100];
struct Address_List{
	address addr;
	struct Address_List *next;
};
typedef struct Address_List AddressLis;
AddressLis *Insert(AddressLis *cur, address x){
	AddressLis *temp;
	temp = (AddressLis *)malloc(sizeof(AddressLis));
	strcpy(temp->addr,x);
	temp->next = cur->next;
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
