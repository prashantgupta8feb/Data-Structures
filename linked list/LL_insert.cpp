#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public :
	int data;
	node* next;
};

void push(node** head_ref,int new_data){
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printlist(node *Node)
{
	while(Node != NULL){
	cout<<" "<<Node->data;
	Node = Node->next;
    } 
}
int main() 
{
node* head = NULL;
push(&head,7);
cout<<"Created linked list is : ";
printlist(head);
push(&head,8);
push(&head,99);
cout<<"\nCreated linked list is : ";
printlist(head);
return 0;	
}
