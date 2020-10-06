#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
};
void push(node **head_ref,int data){
	node* new_node= new node();
    new_node->data=data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;	
}
void addafter(node *prev_node,int data){
	if(prev_node==NULL){
	cout<<"Previous node can not be NULL\n";
	return;
	}
	else{
		node* new_node = new node();
		new_node->data= data;
		new_node->next=prev_node->next;
		prev_node->next=new_node;
	}
}
void append(node **head_ref,int data){
	node* new_node= new node();
	node *last=(*head_ref);
	new_node->data=data;
	new_node->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new_node;
		return;
		}
		while(last->next!=NULL)
		last=last->next;
		last->next=new_node;
		return;
}
void printlist(node *node){
	while(node!=NULL)
	{
		cout<<node->data<<" ";
		node=node->next;
	}
}
int main(){
	 node* head=NULL;
	 push(&head,7);
	 push(&head,8);
	 push(&head,39);
	 push(&head,76);
	 cout<<"\nCretaed linked list :"<<endl;
	 printlist(head);
	 addafter(head,500);
	 addafter(head->next->next,1000);
	 cout<<"\nCretaed linked list :"<<endl;
	 printlist(head);
	 return 0;
	
}

