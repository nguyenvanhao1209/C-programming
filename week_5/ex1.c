#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct address{
	char telephone[20];
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
node* newNode(address k){
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
void EnQueue(address X, queue* Q){
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
int main(){
	queue* Q = createQueue();
	FILE *f;
	f = fopen("C:/Users/Administrator/Desktop/new.txt","r");
	if (f == NULL)
    {
    	perror("Khong the mo tep de doc.\n");
		return 1;
    }
	address value;
	while(!feof(f)){
		fscanf(f,"%s\t",value.name);
		printf("%s\t",value.name);
		fscanf(f,"%s\t",value.telephone);
		printf("%s\t",value.telephone);
		fscanf(f,"%s\n",value.email);
		printf("%s\n",value.email);
		EnQueue(value,Q);
	}
	fclose(f);
	FILE *f1;
	f1 = fopen("C:/Users/Administrator/Desktop/test.txt","w");
	if (f1 == NULL)
    {
    	perror("Khong the mo tep de ghi.\n");
		return 1;
    }
	while(Q->front != NULL){
		value = Q->front->data;
		fprintf(f1,"%s\t",value.name);
		fprintf(f1,"%s\t",value.telephone);
		fprintf(f1,"%s\n",value.email);
		DeQueue(Q);
	}
	fclose(f1);
	return 0;
}	
