#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;struct node *next;
}
struct node *head=NULL,*ptr,*temp,*preptr,*new_node;
struct node *createnode(int item){
	new_node=(struct node*)malloc(sizeof(sytuct node));
	new_node->data=item;
	return new_node;
}
void display(){
	ptr=head;
	if(head==NULL)
		printf("Empty list");
	else{
		do{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}while(ptr!=head);
	}
}
void insert_beg(int item){
	new_node=createnode(item);
	ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=head;
	head=new_node;
	printf("The new list after insertion is: ");
	display();
}
void insert_end(int item){
	new_node=createnode(item);
	ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=head;
	printf("The new list after insertionis: ");
	display();
}
void insert_before(int val,int item){
	new_node=createnode(item);
	ptr=head;
	while(ptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	printf("The new list after insertion is: ");
	display();
}
void insert_after(int val,int item){
	new_node=createnode(item);
	ptr=head;
	preptr=ptr;
	while(preptr->data!=val){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	printf("The new list after insertion is: ");
	display();
}
void delete_beg(){
	ptr=head;
	while(ptr->next!=head)
		ptr=ptr->next;
	ptr->next=head->next;
	free(head);
	printf("The new list after deletion is: ");
	display();
}
void delete_end(){
	ptr=head;
	while(ptr->next!=head){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	printf("The new list after deletion is: ");
	display();
}
void delete_node(int item){
	ptr=head;
	if(ptr->data==item)
		delete_beg();
	else{
		while(ptr->data!=item){
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
	printf("The new list after deletion is: ");
	display();
}
int main(){
	int option,item,val;
	do
	{
		printf("\n\n*****MAIN MENU*****");
		printf("\n 1:Display list");
		printf("\n 2:Insert a node at beginning");
		printf("\n 3:Insert a node at last");
		printf("\n 4:Add a node before a given node");
		printf("\n 5:Add a node after a given node");
		printf("\n 6:Delete a node from beginning");
		printf("\n 7:Delete a node from end");
		printf("\n 8.Delete a node");
		printf("\n 9.Exit");
		printf("\n Enter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:display();
				   break;
			case 2:printf("Enter the item to be inserted: ");
				   scanf("%d",&item);
				   insert_beg(item);
				   break;
			case 3:printf("Enter the item to be inserted: ");
				   scanf("%d",&item);
				   insert_end(item);
				   break;
			case 4:printf("Enter the item: ");
				   scanf("%d",&item);
				   printf("Enter the item before which you want to insert: ");
				   scanf("%d",&val);
				   insert_before(val,item);
				   break;
			case 5:printf("Enter the item to be inserted: ");
				   scanf("%d",&item);
				   printf("Enter the item after which you want to insert: ");
				   scanf("%d",&val);
				   insert_after(val,item);
				   break;
			case 6:delete_beg();
				   break;
			case 7:delete_end();
			       break;
			case 8:printf("Enter the item to be deleted: ");
				   scanf("%d",&item);
				   delete_node(item);
				   break;
		}
	}while(option!=9);
	return 0;
}
