#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};
void push(node **head_ref,int data){
	node newnode = newnode new();
	newnode->data = data;
	newnode->next=(*head_ref);
	(*head_ref)=newnode;
}
void DeleteList(node **head_ref){
	if(head_ref == NULL)
	cout<<"Linked list is empty\n";
	return;
}  
