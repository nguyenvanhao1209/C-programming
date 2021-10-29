#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct work{
	char time[20];
	char place[20];
	char people[20];
	char description[20];
};
typedef struct work work;
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
void EnQueue(work X, queue *Q){
	Q->rear->next = (node*)malloc(sizeof(node));
	Q->rear=Q->rear->next;
	Q->rear->data=X;
	Q->rear->next=NULL;
}
void DeQueue(queue *Q){
	if(!EmptyQueue(Q)){
		node *T;
		T = Q->front;
		Q->front = Q->front->next;
		free(T);
	}
}
queue *Q;
MakeQueue(Q);
void adding(){
	work add;
	printf("tine: ");
	fflush(stdin);
	gets(add.time);
	printf("place: ");
	fflush(stdin);
	gets(add.place);
	print("people: ");
	fflush(stdin);
	gets(add.people);
	printf("description: ");
	fflush(stdin);
	gets(add.description);
	EnQueue(add,Q);
}
void deleting(){
	char s[20];
	print("Time, Place, People, Description cua cong viec can xoa: ");
	fflush(stdin);
	gets(s);
	queue *Q1;
	MakeQueue(Q1);
	while(!EmptyQueue(Q)){
		work tmp = Q->front->data;
		if(strcmp(s,tmp.time)==0 || strcmp(s,tmp.place)==0 || strcmp(s,tmp.people)==0 || strcmp(s,tmp.description)==0){
			DeQueue(Q);
			printf("da xoa");
			return ;
		}
		DeQueue(Q);
		EnQueue(tmp,Q);
	}
	printf("khong tim thay phan tu can xoa");
}
void menu(){
	printf("1. adding\n");
	printf("2. deleting\n");
	printf("3. modifying\n");
	printf("4. Thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<5) return n;
	else return chonmenu();
}
void xulymenu(){
	int chon = chonmenu();
	switch(chon){
		case 1: 
		    printf("1.adding\n");
		    adding();
		break;
		case 2:
			printf("2. deleting\n");
			deleting();
			break;
		case 3:
		    printf("3. modifying\n");
		    
			break;
		case 4:
			printf("4. Thoat\n");
			exit(1);
			break;		
	}
}
int main(){
	menu();
	while(1){
		menu();
		xulymenu();
	}
	return 0;
}
