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
//tim phan tu giua
int find(Node** head){
   Node* i=*head;
   Node* j=*head;
   while(i!=NULL&&i->next!=NULL){
   	   i=i->next->next;
   	   j=j->next;
   }
   return j->data;
}
int main(){
	int n,x;
	printf("Nhap so phan tu mang :");
	scanf("%d",&n);
	Node* a=NULL;
	printf("Nhap mang :");
	for(int i=0;i<n;i++){
		scanf("%d",&x);
	    insertToTail(&a,x);
	}
	printf("\nPhan tu giua mang:%d",find(&a));
}
