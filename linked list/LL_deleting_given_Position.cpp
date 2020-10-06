//Deleting at a given position
#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
//Declaring global head pointer
Node *head_ref = NULL;
//Function to push elements in LinkedList
void Push(Node **head_ref,int data){
	Node *new_node = new Node();
	new_node->data=data;
	new_node->next=(*head_ref);
	*head_ref=new_node;
}
//Function to delete the element at given position
void DeletePosition(Node **head_ref, int position)
{
    if(*head_ref==NULL)
	return;
	Node* temp=*head_ref;
	if(position==0)
	{
		*head_ref=temp->next;
		return;
	}           
	for(int i=0;i<position-1 && temp!=NULL;i++)       //Finding previous node of the node t be deleted
		temp=temp->next;
    if(temp==NULL || temp->next == NULL)              //If position is more than no. of nodes
    	return;                                       //node temp->next is the node to be deleted                         //store pointer to the next of the node to be deleted
    temp->next=temp->next->next;                      //Node *next=temp->next->next;
cout<<"List after Deleting node at position "<<position <<"  :";  //	free(temp->next);
	}	
//  Function to print the LinkedList
void PrintList(Node *head){
	while(head != NULL){
		cout<<" "<<head->data;
		head=head->next;
	}
	cout<<endl;
}
//Driver Function
int main(){
	Node *head=NULL;
	Push(&head,2);PrintList(head);
	Push(&head,4);Push(&head,5);Push(&head,8);Push(&head,30);Push(&head,76);
	PrintList(head);
	DeletePosition(&head,2);
	PrintList(head);
	DeletePosition(&head,3);
	PrintList(head);
	DeletePosition(&head,2);
	PrintList(head);
	return 0;
}
