#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;
//void push(int item);
//int pop();
//int peek();
//int isEmpty();
//int isFull();
//void display();
void push(int item)
{
    if(isFull())
    {
        printf("\nStack Overflow\n");
        return;
    }
    top=top+1;
    stack[top]=item;
}
int pop()
{
    int item;
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    item=stack[top];
    top=top-1;
    return item;
}
int peek()
{
    if(isEmpty())
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    return stack[top];
}
int isEmpty()
{
	if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if( isEmpty() )
    {
        printf("\nStack is empty\n");
        return;
    }
	printf("\nStack elements :\n\n");
    for(i=top;i>=0;i--)
        printf(" %d\n", stack[i] );
    printf("\n");
}
void main()
{
    int choice,item;
    while(1)
    {
    	printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display the top element\n");
        printf("4.Display all stack elements\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the item to be pushed : ");
                   scanf("%d",&item);
                   push(item);
                   break;
            case 2:item = pop();
                   printf("\nPopped item is : %d\n",item );
                   break;
            case 3:printf("\nItem at the top is : %d\n", peek() );
                   break;
            case 4:display();
                   break;
            case 5:exit(1);
            default:printf("\nWrong choice\n");      
        }
	}
}
