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
//them node vào dau danh sach
void inserToHead(Node** head,int n){
	Node* newNode=createNode(n);
    newNode->next=*head;
    *head=newNode;
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
	while(tmp->next!=NULL){
		printf("%d->",tmp->data);
		tmp=tmp->next;
	}
	printf("%d->NULL",tmp->data);
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
	printf("\nNhap gia tri chen:");
	scanf("%d",&x);
	inserToHead(&head,x);
	printList(&head);
}
