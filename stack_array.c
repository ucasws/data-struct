#include <iostream>
#include <stdlib.h>
#define ERROR 0
#define OK 1
using namespace std;
typedef struct stack
{
	int data[1000];
	int top;
}stack;
int push(stack *L,int e){
	if (L->top==999)
	{
		return	ERROR;
	}
	L->data[++L->top]=e;
	return OK;
}
int init_stack(stack *L){
	if (L==NULL)
	{
		return ERROR;
	}
	L->top=-1;
	return OK;
}
int pop(stack *L,int *e){
	if (L->top==-1)
	{
		return ERROR;
	}
	*e=L->data[L->top--];
	return OK;
}
int print_stack(stack *L){
	int i=0;
	while(i!=L->top+1){
		cout<<L->data[i++]<<endl;
	}
}
int main(int argc, char const *argv[])
{
	stack *p=(stack*)malloc(sizeof(stack));
	int e=0;
	init_stack(p);
	push(p,2);
	pop(p,&e);
	print_stack(p);
	cout<<e<<endl;
	return 0;
}
