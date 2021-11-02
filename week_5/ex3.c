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
	work data;
	struct node *next;
};
typedef struct node node;
struct queue{
	node *front;
	node *rear;
};
typedef struct queue queue;
node* newNode(work k){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = k;
	temp->next = NULL;
	return temp; 
}
queue* createQueue(){
	queue* Q = (queue*)malloc(sizeof(queue));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
void EnQueue(work X, queue* Q){
	node* temp = newNode(X);
	if(Q->rear == NULL){
		Q->front = temp;
		Q->rear = temp;
		return ;
	}
	Q->rear->next = temp;
	Q->rear = temp;
}
void DeQueue(queue* Q){
	if(Q->front == NULL){
		Q->rear = NULL;
		return ; 
	}
	node* temp = Q->front;
	Q->front = Q->front->next;
	free(temp);
}
queue* Q;
void adding(){
	work add;
	Q = createQueue();
	printf("time: ");
	fflush(stdin);
	gets(add.time);
	printf("place: ");
	fflush(stdin);
	gets(add.place);
	printf("people: ");
	fflush(stdin);
	gets(add.people);
	printf("description: ");
	fflush(stdin);
	gets(add.description);
	EnQueue(add,Q);
}
void deleting(){
	char s[20];
	printf("Time, Place, People, Description cua cong viec can xoa: ");
	fflush(stdin);
	gets(s);
	while(Q->front != NULL){
		work tmp = Q->front->data;
		if(strcmp(s,tmp.time)==0 || strcmp(s,tmp.place)==0 || strcmp(s,tmp.people)==0 || strcmp(s,tmp.description)==0){
			printf("time: ");
			fflush(stdin);
			gets(tmp.time);
			printf("place: ");
			fflush(stdin);
			gets(tmp.place);
			printf("people: ");
			fflush(stdin);
			gets(tmp.people);
			printf("description: ");
			fflush(stdin);
			gets(tmp.description);
			Q->front->data = tmp;
			printf("da sua");
			return ;
		}
		DeQueue(Q);
		EnQueue(tmp,Q);
	}
	printf("khong tim thay phan tu can xoa");
}
void modifying(){
	char s[20];
	printf("Time, Place, People, Description cua cong viec can xoa: ");
	fflush(stdin);
	gets(s);
	while(Q->front != NULL){
		work tmp = Q->front->data;
		if(strcmp(s,tmp.time)==0 || strcmp(s,tmp.place)==0 || strcmp(s,tmp.people)==0 || strcmp(s,tmp.description)==0){
			DeQueue(Q);
			printf("da xoa\n");
			return ;
		}
		DeQueue(Q);
		EnQueue(tmp,Q);
	}
	printf("khong tim thay phan tu can xoa");
}
void inthongtin(){
	queue* P = Q;
	while(P->front != NULL){
		work temp = Q->front->data;
		printf("%-20s\t%-20s\t%-20s\t%-20s\n",temp.time,temp.place,temp.people,temp.description);
		DeQueue(P);
	}
}
void menu(){
	printf("1. adding\n");
	printf("2. deleting\n");
	printf("3. modifying\n");
	printf("4. print\n");
	printf("5. Thoat\n");
}
int chonmenu(){
	int n=0;
	printf("\nchon chuc nang: ");
	scanf("%d",&n);
	if(n>0 || n<6) return n;
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
			printf("4. print\n");
			inthongtin();
			break;
		case 5:
			printf("5. Thoat\n");
			exit(1);
			break;		
	}
}
int main(){
	menu();
	while(1){
		xulymenu();
		printf("\n");
		menu();
	}
	return 0;
}
