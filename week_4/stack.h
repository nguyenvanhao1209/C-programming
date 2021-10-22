#include<stdio.h>
#include<stdlib.h>
struct StackNode{
	int item;
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
	if(s == NULL) return NULL;
	s->top = NULL;
	return s;
}
void StackDestroy(Stack *s){
	while(!StackEmpty(s)){
		StackPop(s);
	}
	free(s);
}
int StackEmpty(Stack *s){
	return (s->top == NULL);
}
int StackPush(Stack *s,int item){
	StackNode *node;
	node = (StackNode *)malloc(sizeof(StackNode));
	node->item = item;
	node->next = s->top;
	s->top = node;
	return 0;
}
int StackPop(Stack *s){
	int item;
	StackNode *node;
	if(StackEmpty(s)){
		return NULL;
	}
	node = s->top;
	item = node->item;
	s->top = node->next;
	free(node);
	return item;
}
