#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
};
void push(Node** head_ref,int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
	}
void swapnodes(Node **head_ref,int x,int y){
	int flagx=-1,flagy=-1;
	Node* temp=(*head_ref);
	Node* tempx=new Node();
	Node* tempy=new Node();
	Node* swap=new Node();
	while(temp->next!=NULL){
		if(temp->data==x)
		flagx=1;
		tempx->next=temp->next;
		}
		while(temp->next!=NULL){
			if(temp->data==y)
			flagy=1;
			tempy->next=temp->next;
		}
		if((flagx==1 && flagy==1)==0)
		return;
		swap->next=tempx->next;
		tempx->next=tempy->next;
		tempy->next=swap->next;
		return ;
		
}
void print(Node *node){
	while(node != NULL){
		cout<<" "<<node->data;
		node = node->next;
		cout<<"\n";
	}
	
}
int main()
{
	Node* head = NULL;
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
    print(head);
    cout<<"\n";
    swapnodes(head,5,6);
    cout<<"Swapnodes compiled!"<<endl;
	print(head);
	
}
