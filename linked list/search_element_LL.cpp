//progrm to find the element in LL
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};
void push(node **head_ref,int data){
    node* newnode = new node();
    newnode->data = data;
    newnode->next = (*head_ref);
    (*head_ref) = newnode;
}
bool search_element(node **head_ref,int x){
	node* temp = (*head_ref);
	while(temp != NULL){
		if(temp->data == x)
		return true;
		temp = temp->next;
	}
	return false;
}
void print(node *head){
   node *temp = head;
    while(temp!=NULL){
        cout<<" "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
	node *head = NULL;
	push(&head,2); print(head);
    push(&head,4); push(&head,5);push(&head,41); push(&head,15); print(head);
    search_element(&head,4) ? cout<<"element found\n" : cout<<"not found\n";
    search_element(&head,40)? cout<<"element found\n" : cout<<"not found\n";   
    return 0;
}
