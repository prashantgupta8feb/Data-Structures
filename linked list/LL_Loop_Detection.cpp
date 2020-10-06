//loop detection in LL
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};
//function to push elements in Linked list
void push(node **head_ref,int data){
	node* newnode = new node();
	newnode->data = data;
	newnode->next = (*head_ref);
	(*head_ref) = newnode;
}
//function to detect loop using floyd cycle detection
bool detectLoop(node *head){
	node *slowptr = head;
	node *fastptr = head; node *temp = NULL;
	while(fastptr->next != NULL ){
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if(slowptr == fastptr){
			temp = slowptr;
          return true;
		  }
			}
	}
//	cout<<"\nLoop not exists !!!\n";

//function to print the LL
void print(node *head){
	if(head == NULL)return;
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
//driver progrm
int main(){
	int i = 0;
	node *head = NULL;
	push(&head,1);push(&head,2);push(&head,82);push(&head,72);push(&head,62);  
	print(head);
    head->next->next->next->next->next = head->next->next; 
	(detectLoop(head) == true) ? cout<<"\nLoop Exist ! \n"  : cout<<"\nLoop Not Exist!\n";
//	print(head);                      run this to print the loop
	return 0;
}
