#include <iostream>
#include <stdlib.h>
#define ERROR 1
#define OK 0
#define MAX_NUM 5
using namespace std;
struct Queue
{
	int data[MAX_NUM];
	int front;
	int rear;
};
int init_queue(Queue *Q){
	if (Q==NULL)
	{
		return ERROR;
	}
	Q->front=0;
	Q->rear=0;
	return OK;
}
int push(Queue *Q,int e){
	if (Q==NULL)
	{
		return ERROR;
	}
	if ((Q->rear+1)%MAX_NUM==Q->front)
	{	
		return ERROR;
	}
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAX_NUM;
	return OK;
}
int pop(Queue *Q,int *e){
	if (Q==NULL)		
	{
		return ERROR;
	}
	if (Q->rear==Q->front)
	{
		return ERROR;
	}
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAX_NUM;
	return OK;
}
int print_Queue(Queue *Q){
	if (Q==NULL || Q->front==Q->rear)
	{
		return ERROR;
	}
	int i=Q->front;
	while(i!=Q->rear){
		cout<<Q->data[i]<<endl;
		i=(i+1)%MAX_NUM;
	}
	return OK;
}
int main(int argc, char const *argv[])
{
	Queue *p=(Queue*)malloc(sizeof(Queue));
	int e=0;
	init_queue(p);
	push(p,1);
	pop(p,&e);
	push(p,2);
	push(p,3);
	push(p,4);
	push(p,5);
	push(p,6);
	pop(p,&e);
	print_Queue(p);
	cout<<endl;
	cout<<e<<endl;
	return 0;
}
