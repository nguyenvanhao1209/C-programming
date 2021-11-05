#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
struct StackNode{
	char item;
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

void StackPush(Stack *s,char item){
	StackNode *node;
	node = (StackNode *)malloc(sizeof(StackNode));
	node->item = item;
	node->next = s->top;
	s->top = node;
}
void StackPop(Stack *s){
	StackNode *node;
	if(s->top == NULL){
		return;
	}
	node = s->top;
	s->top = node->next;
	free(node);
}
void StackDestroy(Stack *s){
	while(s->top != NULL){
		StackPop(s);
	}
	free(s);
}
int thutu(char x){
	if(x == '(') return 0;
	if(x == '+' || x == '-') return 1;
	if(x == '*' || x == '/') return 2;
	if(x == '^') return 3;
}
int main(){
	Stack *s;
	s = StackConstruct();
	char infix[] = "1+(-5)/(6*(7+8))";
	char postfix[] ="";
	char c;
	char x;
	char y;
	int i=0;
	int j=0;
	int dem = 0;
	while(i < strlen(infix)){
		c = infix[i];
		if(c != ' '){
			if(c - '0' >= 0 && c -'0' <= 9 || isalpha(c)) {
				postfix[j++] = c; printf("%c",c);
			}
			else{
				if(c == '(') {
					StackPush(s,c);
					dem++;
				}
				else{
					if(c == ')'){
						while(s->top->item != '('){
							postfix[j++] = s->top->item;
							printf("%c",s->top->item);
							StackPop(s);
						}
						StackPop(s);
						
					}
					else{
						while(s->top != NULL && thutu(c) <= thutu(s->top->item)){
							postfix[j++] = s->top->item;
							printf("%c",s->top->item);
							StackPop(s);
						}
						StackPush(s,c);
						
					}
				}	
			}
		}
		i++;
	}
	while(s->top != NULL){
		if(s->top->item == '(' || s->top->item == ')' || isdigit(s->top->item)){
			continue;
		}
		postfix[j++] = s->top->item;
		for(i=0;i<dem;i++){
			postfix[strlen(postfix)-1] = '\0';
		}
		printf("%c",s->top->item);
		StackPop(s);
	}
	printf("\n");
	postfix[strlen(postfix)-1] = '\0';
	puts(postfix);
}
