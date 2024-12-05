#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
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
//gop danh sach lien ket
void merge(Node** a,Node** b){
    Node* i=*a;
    Node* j=*b;
    while(i!=NULL&&j!=NULL){
    	if(i->data<=j->data){
    		printf("%d->",i->data);
    		i=i->next;
		}else{
			printf("%d->",j->data);
			j=j->next;
		}
	}
	while(i!=NULL){
		printf("%d->",i->data);
    	i=i->next;
	}
	while(j!=NULL){
		printf("%d->",j->data);
    	j=j->next;
	}
	printf("NULL");
}
int main(){
	int n,x;
	printf("Nhap so phan tu mang 1:");
	scanf("%d",&n);
	Node* a=NULL;
	printf("Nhap mang 1:");
	for(int i=0;i<n;i++){
		scanf("%d",&x);
	    insertToTail(&a,x);
	}
	printf("Nhap so phan tu mang 2:");
	scanf("%d",&n);
	Node* b=NULL;
	printf("Nhap mang 2:");
	for(int i=0;i<n;i++){
		scanf("%d",&x);
	    insertToTail(&b,x);
	}
	printf("\nMang sau khi gop:\n");
	merge(&a,&b);
}
