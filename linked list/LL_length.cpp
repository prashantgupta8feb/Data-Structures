//program to count the no. of nodes in the linked list
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
int nodecount(node **head_ref){
    int count = 0;
    node *temp = *head_ref;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count; 
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
    int counting = nodecount(&head);
    cout<<"Node count :"<<counting;
    return 0;
}
