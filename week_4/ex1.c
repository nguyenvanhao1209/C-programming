#include<stdio.h>
#include<string.h>
#define Max 50
typedef struct StackRec{
	char storage[Max];
	int top;
};
typedef struct StackRec StackType;
void Initialize(StackType *stack){
	(*stack).top=0;
}
int isempty(StackType stack){
	return stack.top == 0;
}
int isfull(StackType stack){
	return stack.top == Max;
}
void pushS(char el, StackType *stack){
	if(isfull(*stack))
		printf("stack overflow");
	else (*stack).storage[(*stack).top++]=el;
}
char popS(StackType *stack){
	 if (isempty(*stack))
	 	printf("stack underflow");
	else return (*stack).storage[--(*stack).top];
}
int main(){
	char s[50];
	fflush(stdin);
	gets(s);
	StackType st;
	Initialize(&st);
	int i;
	for(i=0;i<strlen(s);i++){
		pushS(s[i],&st);
	}
	while(!isempty(st)){
		printf("%c",popS(&st));
	}
	return 0;
}
