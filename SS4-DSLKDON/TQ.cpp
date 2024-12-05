#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
typedef struct Node Node;
//tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	return newNode;
}
//them node vao dau danh sach
void insertAtHead(Node** head,int value){
	Node* newNode=createNode(value);
	newNode->next=*head;
	*head=newNode;
}
//them node vao cuoi danh sach
void insertAtTail(Node** head,int value){
	Node* newNode=createNode(value);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=newNode;
}
//them node vao giua danh sach
void insertAtPosition(Node** head,int value,int p){
	Node* newNode=createNode(value);
	//neu p=1
	if(p==1){
		newNode->next=*head;
		*head=newNode;
		return;
	}
	Node* tmp=*head;
	for(int i=0;i<p-1&&tmp!=NULL;i++){
		tmp=tmp->next;
	}
	//neu p ko hop le
	if(tmp==NULL){
		free(newNode);
		return;
	}
	//chen
	newNode->next=tmp->next;
	tmp->next=newNode;
}
//xoa nut dau danh sach
void deleteAtHead(Node** head){
	if(*head==NULL){
		return;
	}
	Node* tmp=*head;
	*head=(*head)->next;
	free(tmp);
}
//xoa nut cuoi danh sach
void deleteAtTail(Node** head){
	if(*head==NULL){
		return;
	}
	if((*head)->next==NULL){
		free(*head);
		*head=NULL;
	}
	Node* tmp=*head;
	while(tmp->next->next!=NULL){
		tmp=tmp->next;
	}
	free(tmp->next);
	tmp->next=NULL;	
}

//duyet danh sach
void printList(Node** head){
	Node* tmp=*head;
	while(tmp->next!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
}
int main(){
	Node* head=NULL;
}
