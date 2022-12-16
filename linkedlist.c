//Program of linked list using c++ 
#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype{
	int data;
	struct nodetype *next;
}node;

void insert_at_beg(node **start,int item){             
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->next=*start;
	*start=ptr;
}

void insert_at_end(node **start,int item){             
	node *ptr,*last;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=item;
	ptr->next=NULL;
	if(*start==NULL){
		*start=ptr;
		printf("Linked List is Empty");
	}
	else{
		last=*start;
		while(last->next!=NULL){
			last=last->next;
		}
	}
	last->next=ptr;
}

void display(node *start){                        
	if(start==NULL){
		printf("\n Linked list empty");
		return ;
	}
	while(start!=NULL){
		printf("%d  ",start->data);
		start=start->next;
	}
}

void insert_after_loc(node **head, int item,int dataafter){
	node *temp,*ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->data=item;
	temp=*head;
	while(temp->data!=dataafter){
		temp=temp->next;
	}
	ptr->next=temp->next;
	temp->next=ptr;
}

void delete_at_beg(node **head){
	node *temp;
	temp=*head;
	printf("Deleted Value : %d",temp->data);
	*head= temp->next;
	free(temp);
}

void delete_at_end(node **head){
	node *temp;
	temp=*head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	printf("%d",temp->next->data);
	free(temp->next);
	temp->next=NULL;
}

void delete_after_pos(node **head,int pos){
	pos--;
	node *ptr;
	ptr=*head;
	while(pos>1){
		ptr=ptr->next;
		pos--;
	}
	node *temp=ptr->next;
	ptr->next=ptr->next->next;
	free(temp);
}

int main() {
	int item,ch,after;
	node *head;
	head = NULL;
		printf(" Menu is\n1.Insert element at beg ");
		printf("\n2.Insert element at end ");
		printf("\n3.Display element ");
		printf("\n4.After location");
		printf("\n5.delete at begin");
		printf("\n6.delete at end");
		printf("\n5.Delete at location");
		
	while(1){
	    printf("\nSelect case:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\n.Enter element:");
				scanf("%d",&item);
				insert_at_beg(&head,item);
			break;
			case 2:
				printf("\n.Enter element at end:");
				scanf("%d",&item);
				insert_at_end(&head,item);
			break;
			case 3:
			    printf("\n.Display element:");
				display(head);
			break;
			case 4:
				printf("\n.Enter element: ");
				scanf("%d",&item);
				printf("Element after which you have to insert: ");
				scanf("%d",&after);
				insert_after_loc(&head,item,after);
			break;
			case 5:
			    delete_at_beg(&head);
			break;
			case 6:
			    delete_at_end(&head);
			break;
			case 7:
				printf("\n.Enter position :");
				scanf("%d",&item);
				delete_after_pos(&head,item);
			break;
		default:exit(1);
		}
	}

}
