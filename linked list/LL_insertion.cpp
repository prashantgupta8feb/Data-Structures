#include<iostream>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
};

void push(node** head_ref,int new_data){
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	}
void addafter(node* prev,int new_data){
	 if (prev == NULL)  
    {  
        cout<<"the given previous node cannot be NULL";  
        return;  
    }  
	node* new_node = new node();
	new_node->data = new_data;
	new_node->next = prev->next;
	prev->next = new_node;
}
void append(node** head_ref,int new_data){
	node* new_node = new node();
	node* last = *head_ref;
	new_node->data =new_data;
	new_node->next = NULL;
	if(head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL)
	last = last->next;
last->next = new_node;
return;
}
void print(node *node){
	while(node != NULL){
		cout<<" "<<node->data<<" ";
		node = node->next;
		// cout<<"\n";
	}
	
}
 int main()
{
	node* head = NULL;
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
    print(head);
    cout<<"\n";
	addafter(head->next,800 );
	append(&head,10);
	append(&head,20);
	print(head);
	cout<<"\n";
	addafter(head,1000);
	print(head);
	
}

