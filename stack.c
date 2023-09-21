#include<stdio.h>
int max=7,stack[7],top=-1;
void push(int data)
{
	if(top==max-1)
	printf("\nStack Overflow");
	else
	{
		top++;
		stack[top]=data;
	}
}
void pop()
{
	int data;
	if(top==-1)
		printf("\nStack underflow");
	else
	{
		data=stack[top];
		top--;
		printf("\nDeleted data element: %d",data);
	}
}
void peek(int data)
{
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		data=stack[top];
		printf("\nThe topmost element is: %d",data);
	}
}
void display()
{
	int i;
	if(top==-1)
		printf("\nStack is empty");
	else
	{
		for(i=top;i>0;i--)
		{
			printf(" %d ",stack[i]);
			printf("\n");
		}
	}
}
int main()
{
	printf("Enter the element: ");
	scan
	push(60);
	display();
	pop();
	display();
	return 0;
}
