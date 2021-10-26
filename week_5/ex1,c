#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct address{
	char tele[20];
	char name[20];
	char email[20];
};
typedef struct address address;
struct node{
	address data;
	struct node *next;
};
typedef struct node node;
struct queue{
	node *front;
	node *rear;
};
typedef struct queue queue;
void MakeQueue(queue *Q){
	node *header;
	header = (node*)malloc(sizeof(node));
	header->next = NULL;
	Q->front = header;
	Q->rear = header;
}
int EmptyQueue(queue *Q){
	return Q->front == Q->rear;
}
void EnQueue(address X, queue *Q){
	Q->rear->next = (node*)malloc(sizeof(node));
	Q->rear=Q->rear->next;
	Q->rear->data=X;
	Q->rear->next=NULL;
}
address DeQueue(queue *Q){
	if(!EmptyQueue(Q)){
		node *T;
		address temp;
		T = Q->front;
		temp = T->data;
		Q->front = Q->front->next;
		free(T);
		return temp;
	}
}
int main(){
	FILE *f;
	f = fopen("new.txt","r");
	queue *Q;
	MakeQueue(Q);
	address value;
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
		EnQueue(value,Q);
	}
	fclose(f);
	FILE *f1;
	f1 = fopen("test.txt","w");
	while(!EmptyQueue(Q)){
		value = DeQueue(Q);
		fprintf(f1,"%s\n",value.name);
		fprintf(f1,"%s\n",value.tele);
		fprintf(f1,"%s\n",value.email);
	}
	fclose(f1);
	return 0;
}
