#include <iostream>
#include <stdlib.h>
#define ERROR 0
#define OK 1
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}node;
typedef struct stack
{
	node *top;
	int count;
}stack;
int init_stack(stack *L){
	if (L==NULL)
	{
		return ERROR;
	}
	L->top=(node*)malloc(sizeof(node));
	L->top->next=NULL;
	L->top->data=0;
	L->count=0;
	return OK;
}
int push(stack *L,int e){
	if (L==NULL)
	{
		return ERROR;
	}
	node* s=(node*)malloc(sizeof(node));
	if (s==NULL)
	{
		return ERROR;
	}
	s->data=e;
	s->next=L->top->next;
	L->top->next=s;
	L->count++;
	return OK;
}
int pop(stack *L,int *e){
	if (L==NULL || e==NULL)
	{
		return ERROR;
	}
	node *s=L->top->next;
	*e=s->data;
	L->top->next=L->top->next->next;
	free(s);
	s=NULL;
	L->count--;
	return OK;
}
int print_stack(stack *L){
	if (L==NULL)
	{
		return ERROR;
	}
	node* i=L->top->next;
	while(i!=NULL){
		cout<<i->data<<endl;
		i=i->next;
	}
	cout<<"stack count:"<<L->count<<endl;
	return OK;
}
int main(int argc, char const *argv[])
{
	stack *p=(stack*)malloc(sizeof(stack));
	if (p==NULL)
	{
		return ERROR;
	}
	int e=0;
	init_stack(p);
	push(p,1);
	push(p,4);
	//pop(p,&e);
	print_stack(p);
	cout<<endl;
	cout<<e<<endl;
	return 0;
}
