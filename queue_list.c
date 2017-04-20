#include <iostream>
#include <stdlib.h>
#define ERROR 1
#define OK 0
#define MAX_NUM 5
using namespace std;
typedef struct node
{
	int data;
	node *next;
}node;
typedef struct Queue
{
	node *front;
	node *rear;
}Queue;
int init_queue(Queue *Q){
	node *s=(node*)malloc(sizeof(node));
	s->next=NULL;
	s->data=0;
	Q->front=s;
	Q->rear=s;
	return OK;
}
int push(Queue *Q,int e){
	if (Q==NULL)
	{
		return ERROR;
	}
	node *s=(node*)malloc(sizeof(node));
	s->data=e;
	Q->rear->next=s;
	s->next=NULL;
	Q->rear=s;
	return OK;
}
int pop(Queue *Q,int *e){
	if (Q==NULL)
	{
		return ERROR;
	}
	if (Q->front==Q->rear)
	{
		return ERROR;
	}
	node *s=Q->front->next;
	*e=s->data;
	Q->front->next=Q->front->next->next;
	free(s);
	s=NULL;
	return OK;
}
int print_queue(Queue *Q){
	if (Q==NULL)
	{
		return ERROR;
	}
	if (Q->front==Q->rear)
	{
		return ERROR;
	}
	node *s=Q->front->next;
	while(s!=NULL){
		cout<<s->data<<endl;
		s=s->next;
	}
	return OK;
}
int main(int argc, char const *argv[])
{
	Queue *p=(Queue*)malloc(sizeof(Queue));
	int e=0;
	init_queue(p);
	push(p,1);
	push(p,2);
	push(p,3);
	push(p,4);
	push(p,5);
	push(p,6);
	pop(p,&e);
	pop(p,&e);
	print_queue(p);
	cout<<endl;
	cout<<e<<endl;
	return 0;
}
