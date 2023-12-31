
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
	printf("%d",temp->data);
}
void insert_beg(int item){
	new_node=createnode(item);
	if(head==NULL){
		head=new_node;
		new_node->prev=new_node;
		new_node->next=head;
	}
	else{
		new_node->next=head;
		head->prev->next=new_node;
		new_node->prev=head->prev;
		head->prev=new_node;
		head=new_node;
	}
	printf("The new list after insertion is: ");
	display();
}
void insert_end(int item){
	new_node=createnode(item);
	if(head==NULL){
		head=new_node;
		new_node->prev=new_node;
		new_node->next=head;
	}
	else{	
		head->prev->next=new_node;
		new_node->next=head;
		head->prev=new_node;
	printf("The new list after insertion is: ");
	display();
}
}
void insert_before(int val, int item) {
    new_node = createnode(item);
    if (head == NULL) {
        printf("Empty list");
        return;
    }
    ptr = head;
    while (ptr->data != val) {
        ptr = ptr->next;
        if (ptr == head) {
            printf("Node doesn't exist");
            return;
        }
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    printf("The new list after insertion is: ");
    display();
}
void insert_after(int val, int item) {
    new_node = createnode(item);
    if (head == NULL) {
        printf("Empty list");
        return;
    }
    ptr = head;
    while (ptr->data != val) {
        ptr = ptr->next;
        if (ptr == head) {
            printf("Node doesn't exist");
            return;
        }
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    printf("The new list after insertion is: ");
    display();
}
void delete_beg(){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	if (head->next == head) {
		free(head);
        head = NULL;
    } 
    else{
	(head->prev)->next=head->next;
	(head->next)->prev=head->prev;
	del=head;
	head=head->next;
	free(del);
	printf("The new list after deletion is: ");
}
	display();
}
void delete_last() {
    if (head == NULL) {
        printf("Empty list");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head->prev;  
        head->prev = temp->prev;        
        temp->prev->next = head;        
        free(temp);                     
    }

    printf("The new list after deletion is: ");
    display();  
}
void delete_node(int val){
	if(head==NULL){
		printf("Empty list");
		return;
	}
	ptr=head;
	if(ptr->data==val){
		delete_beg();
		return;
	}
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
	printf("The new list after deletion is: ");
	display();
}
void delete_before(int val) {
	if(ptr->data==val)
		delete_last();
	else{
		while(ptr->data!=val)	
			ptr=ptr->next;
		temp=ptr->prev;
		if(temp==head)
			delete_beg();
		else
		{
			ptr->prev=temp->prev;
			temp->prev->next=ptr;
		}
		free(temp);
	}
    printf("The new list after deletion is: ");
    display();
}
void delete_after(int val) {
    ptr = head;
    while (ptr->data != val) {
        ptr = ptr->next;
    temp=ptr->next;
    if (temp == head) 
		delete_beg();
	else{
		ptr->next = temp->next;
    	(temp->next)->prev = ptr;
    	free(temp);
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
		printf("\n 9: Delete before a given node");
        printf("\n 10: Delete after a given node");
        printf("\n 11: Exit");
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
			case 9:
                printf("Enter the value before which you want to delete: ");
                scanf("%d", &val);
                delete_before(val);
                break;
            case 10:
                printf("Enter the value after which you want to delete: ");
                scanf("%d", &val);
                delete_after(val);
                break;
		}
	}while(option!=11);
	return 0;
}
