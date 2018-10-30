#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	Node *next;
};
typedef Node* node;
node create(){
	node temp;
	temp=(node)malloc(sizeof(node));
	temp->next=NULL;
	return temp;
}
void addNode(node head,int value){
	node temp,p;
	temp=create();
	temp->data=value;
	p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=temp;
}
void delNode(node head,int index){
	node p,p1;
	p=head;
	for(int i=0;i<index;i++){
		p=p->next;
	}
	p1=p->next;
	p->next=p1->next;
	free(p1);
	head->data--;
}
void insertNode(node head,int index,int value){
	node p,temp,p2;
	p=head;
	for(int i=0;i<index;i++){
		p=p->next;
	}
	temp=create();
	temp->data=value;
	temp->next=p->next;
	p->next=temp;
	head->data++;
}
void modifyNode(node head,int index,int add){
	node p;
	p=head;
	for(int i=0;i<=index;i++){
		p=p->next;
	}
	p->data+=add;
}
node traverse(int index,node head){
	node p=head;
	for(int i=0;i<=index;i++)
	p=p->next;
	return p;
}
void printList(node head){
	node temp=head;
	for(int i=0;i<head->data;i++){
		temp=temp->next;
		cout<<temp->data<<" ";
	}
	cout<<endl;
}
int main (){
	node head=create();
	int n,in;
	cout<<"Enter size of linked list ";
	cin>>n;
	head->data=n;
	for(int i=0;i<n;i++){
		cin>>in;
		addNode(head,in);
	}
	printList(head);
	delNode(head,2);
	printList(head);
	modifyNode(head,0,3);
	printList(head);
	insertNode(head,2,3);
	printList(head);
	return 0;
}
