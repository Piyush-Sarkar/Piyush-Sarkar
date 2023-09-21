#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
		struct node * link;
	};
	void push( struct node **,int);
	void pop(struct node **);
	void display( struct node *);
	int main ()
	{
		int e,ch;
		struct node*t=NULL;
		while(1)
		{
			printf("\n 1. PUSH 2.POP 3.DISPLAY 4.EXIT");
			printf("\n enter the choice");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
				printf("\n enter the value inserted");
					scanf("%d",&e);
					push(&t,e);
					break;
					case 2:
						pop(&t);
						break;
						case 3:
							display(t);
							break;
							case 4:
								exit(0);
								break;
								default:
									printf("\n invalid choice:");
									break;
								}
							}
						}
						void push(struct node**Top,int num)
						{
							struct node*temp;
							temp=(node*)malloc(sizeof (struct node));
							temp->data=num;
							temp->link=*Top;
							*Top=temp;
						}
						void pop(struct node**Top)
						{
							int item;
							struct node*q;
							if(*Top==NULL)
							printf("\nstack empty");
							else
							{
							q=*Top;
							item=q->data;
							printf("\n value popped=%d",item);
							*Top=q->link;
							free(q);
						}
						}
