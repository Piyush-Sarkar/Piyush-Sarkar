#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev,*next;
	int data;
};
struct node *new_node,*ptr,*temp,*preptr,*head=NULL;
struct node *createnode(int item){
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=item;
	return new_node;
}
void display(){
	if(head==NULL)
		printf("Empty list");
	else
		ptr=head;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("end");
}
void insert_beg(int item){
	new_node=createnode(item);
	head->prev=new_node;
	new_node->next=head;
	new_node->prev=NULL;
	head=new_node;
	printf("\nThe new list after insertion: ");
	display();	
}
void insert_end(int item){
	new_node=createnode(item);
	ptr=head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	printf("\nThe new list after insertion: ");
	display();
}
void insert_before(int val,int item){
	new_node=createnode(item);
	ptr=head;
	while(ptr->data!=val)
		ptr=ptr->next;
	new_node->next=ptr;
	new_node->prev=ptr->prev;
	ptr->prev->next=new_node;
	ptr->prev=new_node;
	printf("\nThe new list after insertion: ");
	display();
}
void insert_after(int val,int item){
	new_node=createnode(item);
	ptr=head;
	while(ptr->data!=val)
		ptr=ptr->next;
	new_node->prev=ptr;
	new_node->next=ptr->next;
	ptr->next=new_node;
	printf("\nThe new list after insertion: ");
	display();
}
void delete_beg(){
	if(head==NULL)
		printf("Empty list");
	else{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
	}
	printf("\nThe new list after deletion: ");
	display();
}
void delete_end(){
	if(head==NULL)
		printf("Empty list");
	else{
		ptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->prev->next=NULL;
		free(ptr);
	}
	printf("\nThe new list after deletion: ");
	display();
}
void delete_node(int item){
	ptr=head;
	if(ptr->data==item)
		delete_beg();
	else{
		while(ptr->data!=item){
			ptr=ptr->next;
		}
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
	}
	printf("\nThe new list after deleting the node: ");
	display();
}
void delete_before(int item){
	if(head==NULL)
		printf("Empty list");
	else{
		ptr=head;
		while(ptr->data!=item)
			ptr=ptr->next;
		temp=ptr->prev;
		if(temp==head)
			delete_beg();
		else{
			ptr->prev=temp->prev;
			temp->prev->next=ptr;
		}
		free(temp);
	}
	printf("\nThe new list after deleting the node: ");
	display();
}
void delete_after(int item){
	if(head==NULL)
		printf("Empty list");
	else{
		ptr=head;
		while(ptr->data!=item)
			ptr=ptr->next;
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
	}
	printf("\nThe new list after deletion: ");
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
		printf("\n 9.Delete a node before a given node");
		printf("\n 10.Delete a node after a given node");
		printf("\n 11.Exit");
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
			case 7:delete_end();
			       break;
			case 8:printf("Enter the item to be deleted: ");
				   scanf("%d",&item);
				   delete_node(item);
				   break;
			case 9:printf("Enter the item before which you want to delete: ");
				   scanf("%d",&item);
				   delete_before(item);
				   break;
			case 10:printf("Enter the item after which you want to delete: ");
					scanf("%d",&item);
					delete_after(item);
					break;
		}
	}while(option!=11);
	return 0;
}
