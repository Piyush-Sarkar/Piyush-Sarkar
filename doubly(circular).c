#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev,*next;
	int data;
};
struct node *head=NULL,*new_node,*ptr,*preptr,*temp,*del;
struct node *createnode(int item){
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=item;
	return new_node;
}
void display(){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	temp=head;
	while(temp->next!=head){
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void insert_beg(int item){
	if(head==NULL){
		new_node->prev=new_node;
		head=new_node;
	}
	else{
		ptr=head;
		while(ptr->next!=head)
			ptr=ptr->next;
		new_node->next=head;
		(head->prev)->next=head->prev;
		head->prev=new_node;
		head=new_node;
	}
	printf("The new list after insertion is: ");
	display();
}
void insert_end(int item){
	new_node=createnode(item);
	if(head==NULL){
		new_node->prev=new_node;
		new_node->next=new_node;
		head=new_node;
	}
	else{
		new_node=head->prev;
		(head->prev)->next=new_node;
		new_node->next=head;
		head->prev=new_node;
	}
	printf("The new list after insertion is: ");
	display();
}
void insert_before(int val,int item){
	new_node=createnode(item);
	if(head==NULL){
		printf("Empty list");
		return;
	}
	ptr=head;
	if(head->data==val){
		insert_beg(item);
		return;
	}
	do{
		ptr=ptr->next;
	}while(ptr!=head && ptr->data!=val);
	if(ptr==head){
		printf("Node doesn't exist");
		return;
	}
	new_node->next=ptr;
	new_node->prev=ptr->prev;
	ptr->prev->next=new_node;
	ptr->prev=new_node;
	printf("The new list after insertion is: ");
	display();
}
void insert_after(int val,int item){
	new_node=createnode(item);
	if(head==NULL)
		printf("Empty list");
	else
		ptr=head;
	do{
		ptr=ptr->next;
	}while(ptr!=head && ptr->data!=val);
	if(ptr==head){
		printf("Node doesn't exist");
		return;
	}
	new_node->prev=ptr;
	new_node->next=ptr->next;
	ptr->next=new_node;
	printf("The new list after insertion is: ");
	display();
}
void delete_beg(){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	(head->prev)->next=head->next;
	(head->next)->prev=head->prev;
	del=head;
	head=head->next;
	free(del);
	printf("The new list after deletion is: ");
	display();
}
void delete_last(){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	((head->prev)->prev)->next=head;
	head->prev=(head->prev)->prev;
	del=head->prev;
	head->prev=head->prev->next;
	free(del);
	printf("The new list after deletion is: ");
	display();
}
void delete_node(int val){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	ptr=head;
	if(ptr->data==val)
		delete_beg();
	else{
		while(ptr->data!=val){
			ptr=ptr->next;
			if(ptr==head){
				printf("Node doesn't exist");
				return;
			}
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
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
		printf("\n 3:Insert a node at end");
		printf("\n 4:Add a node before a given node");
		printf("\n 5:Add a node after a given node");
		printf("\n 6:Delete a node from beginning");
		printf("\n 7:Delete a node at the end");
		printf("\n 8.Delete a given node");
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
				   printf("Enter the value before which you want to insert: ");
				   scanf("%d",&val);
				   insert_before(val,item);
				   break;
			case 5:printf("Enter the item to be inserted: ");
				   scanf("%d",&item);
				   printf("Enter the value after which you want to insert: ");
				   scanf("%d",&val);
				   insert_after(val,item);
				   break;
			case 6:delete_beg();
				   break;
			case 7:delete_last();
			       break;
			case 8:printf("Enter the item to be deleted: ");
				   scanf("%d",&item);
				   delete_node(item);
				   break;
		}
	}while(option!=9);
	return 0;
}
