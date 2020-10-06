#include<iostream>
using namespace std;
class node{
	public :
		int data;
		node *next;
};
void push(node **head_ref,int data){
   node* newnode = new node();
	newnode->data = data;
	newnode->next = (*head_ref);
	(*head_ref) = newnode;	
}
bool isPalindrome(node *head){
	int stack[100], n=100, top=-1;
void push(int x){
	if(top==n-1)
	cout<<"Stack Overflow!\n";
	else{
	    top++;
		stack[top]=x;
//		cout<<"Element "<<x<<" is pushed.\n";
	}
}
void pop(){
	if(top==-1)
	cout<<"Stack underflow !\n";
	else{
//		cout<<"Element "<<stack[top]<<" is popped !\n";
		top--;
		}
}
	while (node != NULL){
	    push(node->data);
		head = head->next;
	}
    while(head != NULL){
		pop()
	}
}
void print(node *head){
	if(head == NULL)return;
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
int main(){
	
}
