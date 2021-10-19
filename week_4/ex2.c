#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Address{
	char name[20];
	char tele[10];
	char email[20];
}Addr;
struct StackNode{
	Addr item;
	struct StackNode *next;
};
typedef struct StackNode StackNode;
struct Stack{
	StackNode *top;
};
typedef struct Stack Stack;

Stack *StackConstruct(){
	Stack *s;
	s = (Stack *)malloc(sizeof(Stack));
	if(s == NULL){
		return NULL;
	}
	s->top = NULL;
	return s;
}
int StackEmpty(Stack *s){
	return (s->top == NULL);
}
int StackPush(Stack *s,Addr value){
	StackNode *node;
	node = (StackNode*)malloc(sizeof(StackNode));
	node->item  = value;
	node->next = s->top;
	s->top = node;
	return 0;
}
Addr StackPop(Stack *s){
	Addr value;
	StackNode *node;
	if(StackEmpty(s)){
		return ;
	}
	node = s->top;
	value = node->item;
	s->top = node->next;
	free(node);
	return value;
}
int main(){
	FILE *f,*f1;
	f = fopen("new.txt","r");
	Stack *ST;
	ST = StackConstruct();
	Addr value; 
	while(!feof(f)){
		fgets(value.name,255,f);
		value.name[strlen(value.name)-1] = '\0';
		printf("%s\n",value.name);
		fgets(value.tele,255,f);
		value.tele[strlen(value.tele)-1] = '\0';
		printf("%s\n",value.tele);
		fgets(value.email,255,f);
		value.email[strlen(value.email)-1] = '\0';
		printf("%s\n",value.email);
		StackPush(ST,value);
	}
	fclose(f);
	f1 = fopen("test.txt","w");
	while(!StackEmpty(ST)){
		value = StackPop(ST);
		fprintf(f1,"%s\n",value.name);
		fprintf(f1,"%s\n",value.tele);
		fprintf(f1,"%s\n",value.email);
	}
	fclose(f1);
	return 0;
}
