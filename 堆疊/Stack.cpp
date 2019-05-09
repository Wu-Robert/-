#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	
	int data;
	node *next;
	
}Node;

void Push(Node *);
void Pop(Node *);
void List(Node *);


int main(){
	
	char choice;
	Node *head=(Node *)malloc(sizeof(Node));
	head->next=NULL;
	
	while(1){
		
		printf("��ܥ\\��:\n1.Push\n2.Pop\n3.List\n4.Exit\n\t\t\t\t");
		scanf(" %c",&choice);
		fflush(stdin);
		
		switch (choice){
			case '1':
			    Push(head);
			    break;
			case '2':
				Pop(head);
				break;
			case '3':
				List(head);
				break;
			case '4':
				printf("�����{��");
				return 0;
				break;
			default:
				printf("���~��J");
		}
		printf("-----------------------------------\n");
	}
	
}

void Push(Node *head){

	Node *ptr=head;
	Node *newNode=(Node *)malloc(sizeof(Node));
	newNode->next=NULL;
	int count=0;
	
	while(ptr->next!=NULL){
		count++;
		ptr=ptr->next;
	}
	
	ptr->next=newNode;
	newNode->data=count;

}

void Pop(Node *head){
	
	Node *ptr=head;
	
	if(ptr->next==NULL){
		printf("��C����\n");
	}
	
	else{
	    while(ptr->next!=NULL){
		    if(ptr->next->next==NULL){
		    	ptr->next=NULL;
	    		break;
		    }
	    	ptr=ptr->next;
		    
	    }
   	}
}

void List(Node *head){
	
	Node *ptr=head;
	
	if(head->next==NULL){
		printf("��C����");
	}
	else{
		printf("head");
	
	    while(ptr->next!=NULL){
		ptr=ptr->next;
		printf(" -> %d",ptr->data);
	    }
	}
	
	printf("\n");
}
