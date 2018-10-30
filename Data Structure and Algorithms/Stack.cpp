#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* node;
int size=0;
node head,top;
node createNode(){
	node temp;
	temp=(node)malloc(sizeof(node));
	temp->next=NULL;
	return temp;
}
void push(int data){
	node temp=createNode();
	temp->next=top;
	temp->data=data;
	top=temp;
	size++;
}
void pop(){
	cout << top->data <<endl;
	node temp=top->next;
	free(top);
	top=temp;
	size--;
}
void addFirstNode(int data){
	head=createNode();
	top=createNode();
	head->data=data;
	top=head;
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

