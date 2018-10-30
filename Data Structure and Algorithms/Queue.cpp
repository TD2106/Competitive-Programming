#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* node;
int size=0;
node head,cur;
node createNode(){
	node temp;
	temp=(node)malloc(sizeof(node));
	temp->next=NULL;
	return temp;
}
void push(int data){
	node temp=createNode();
	cur->next=temp;
	temp->data=data;
	cur=temp;
	size++;
}
void pop(){
	cout << head->data <<endl;
	node temp=head->next;
	free(head);
	head=temp;
	size--;
}
void addFirstNode(int data){
	head=createNode();
	head->data=data;
	cur=head;
	size++;
}
bool isEmpty(){
	return size==0;
}
int main (){
	addFirstNode(1);
	push(2);
	push(3);
	push(4);
	push(5);
	pop();
	pop();
	pop();
	return 0;
}

