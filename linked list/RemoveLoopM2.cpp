//method 2 for removing loop in LL
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};
void RemoveLoop(node*,node*);
void push(node **head,int data){
	node *newnode = new node();
	newnode->data = data;
	newnode->next =*head;
	*head = newnode;
}
int DetectLoop(node *head){
	node *slowptr = head;
	node *fastptr = head;
	while(head != NULL){
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if(slowptr == fastptr){
			RemoveLoop(slowptr,head);
			return 1;
		}
	}
	return 0;
}
void RemoveLoop(node *loopnode,node *head){
	node *ptr1 = head;
	node *ptr2 = head;
	while(1){
		node *ptr2 = loopnode;
		while(ptr2->next != loopnode && ptr2->next!=ptr1)
		ptr2= ptr2->next;
	}
}
