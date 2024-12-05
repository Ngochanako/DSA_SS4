#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
//ham tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	return newNode;
}
//them node vao cuoi danh sach
void insertToTail(Node** head,int n){
	Node* newNode=createNode(n);
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
//ham duyet danh sach
void printList(Node** head){
	if(*head==NULL){
		return;
	}
	Node* tmp=*head;
	while(tmp!=NULL){
		printf("%d->",tmp->data);
		tmp=tmp->next;
	}
	printf("NULL");
}
//dao nguoc danh sach
void reverseLink(Node* head){
    if(head->next==NULL){
    	printf("%d", head->data);
    	return;
	}
	reverseLink(head->next);
	printf("->%d",head->data);
}
int main(){
	int n,x;
	scanf("%d",&n);
	Node* head=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
	    insertToTail(&head,x);
	}
	printList(&head);
	printf("\n mang dao nguoc:");
    reverseLink(head);
}
