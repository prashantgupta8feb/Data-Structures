
/* A complete working C++ program to demonstrate all insertion methods on Linked List 
functions in this program :
1)Push
2)AddAfter
3Append
4)SwapNodes
5)PrintMiddle
6)PrintList
7)ListCount
8)SearchElement
9)FrequencyCounter
10)Get nth Node
11)Reverse the linked list
12)Deletion
13)Remove Loop*/
#include <bits/stdc++.h> 
using namespace std;                                                         
// A linked list node  
class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
/*1) Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
}  
/* 2)Given a node prev_node, insert a new node after the given  
prev_node */
void insertAfter(Node* prev_node, int new_data)  
{  
    if (prev_node == NULL)  
    {  
        cout<<"the given previous node cannot be NULL";  
        return;  
    }  
    Node* new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = prev_node->next;  
    prev_node->next = new_node;  
}  
/*3) Given a reference (pointer to pointer) to the head  
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)  
{  
    Node* new_node = new Node(); 
    Node *last = *head_ref; 
    new_node->data = new_data;  
    new_node->next = NULL;  
    if (*head_ref == NULL){  
        *head_ref = new_node;  
        return;
        }  
    while (last->next != NULL)  
    last = last->next;  
    last->next = new_node;  
    return;  
}  
//4)function to swap two nodes in linked list  .....not working
void swapnodes(Node **head_ref,int x,int y){
	int flagx=-1,flagy=-1;
	Node* node=(*head_ref);
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
		 int count=0;
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
        count++;
    }  
    cout<<"\n\n"<<"No. of nodes in list :"<<count;
		return ;
		
}
//5)function to find the middle node 
void printMiddle (Node *head)  
{  
     Node *slow_ptr = head;  
     Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        cout<<"\nMiddle Node : "<<slow_ptr->data;  
    }  
}  
  
//6) This function prints contents of 
// linked list starting from head
void printList(Node *node)  
{  
  int count=0;
    while (node != NULL)  
    {  
        cout<<" "<<node->data;  
        node = node->next;  
//        count++;
    }  
//    cout<<"\n\n"<<"No. of nodes in list :"<<count<<"\n";
}
//7)function to count no. of nodes  
void listcount(Node *head){
  int count=0;
  if(head==NULL)
  cout<<"Empty List"<<endl;
  while(head!=NULL){
    count++;
    head=head->next;
    
  }
  cout<<"Node counting by listcount function is :"<<count<<"\n\n";
}
//8)function to search an element
bool searchkey(Node* head,int key){
  Node* temp = head;
  while(temp!=NULL){
    if(temp->data==key)
    return true;
    temp=temp->next;
  }
  return false;
  
}
//9)element frequency counter 
void NodeFrequency(Node *head,int element){
	int counter=0;
	Node *temp = head;
	while(temp != NULL){
		if(temp->data == element){
			counter++;
		} 
		temp = temp->next;
	} 
	cout<<"\n\nNode Frequency of "<<element<<" : "<<counter<<"\n"; 
}
//10)function to get nth node 
void nthnode(Node** head_ref,int n){
	Node* temp = (*head_ref);
	int count = 0;
	while(temp != NULL){
		temp = temp->next;
		count++;
		if(count == n)
		cout<<"\n\n"<<n<<"th node : "<<temp->data<<endl;
	}	
}
//11)function to reverse the linked list
void reverse_iterative(Node* head)
{
    Node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
//12) function to delete node from linkedlist
Node *head; 
void deletenode(Node *prev_node,int key){
	Node *temp = head;
    Node *prev;
	while(temp !=NULL && temp->data == key)
	    {
	    	head = temp->next;
	    	return;
		}
	while(temp != NULL && temp->data != key){
			prev = temp;
			temp = temp->next;
		}
	if(temp == NULL)
		return;
	prev->next = temp->next;
	cout<<"Hi ";
	} 
//13) function to remove loop from a linkedlist
void removeloop(Node* loopnode,Node* head)
{
    Node* ptr1=head;
    Node* ptr2=NULL;
    while(1)
    {
        ptr2=loopnode;
        while(ptr2->next!=loopnode && ptr2->next!=ptr1)
        ptr2=ptr2->next;
        if(ptr2->next==ptr1)
        break;
        ptr1=ptr1->next;
    }
    ptr2->next=NULL;
}
int detect_and_remove_loop(Node* head)
{
    Node* slowptr=head;
    Node* fastptr=head;
    while(slowptr->next)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr)
        {
            removeloop(slowptr,head);
            return 1;                    //loop found
        }
    }
    return 0;                           //loop not found

}


/* Driver code*/
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
    append(&head, 6);                 // Insert 6. So linked list becomes 6->NULL  
    push(&head, 7);                   // Insert 7 at the beginning.  So linked list becomes 7->6->NULL 
    push(&head, 1);push(&head, 1);
	push(&head, 1);push(&head, 1); 
	push(&head,420);                  // Insert 1 at the beginning.  So linked list becomes 1->7->6->NULL   
    append(&head, 4);                 // Insert 4 at the end. So  linked list becomes 1->7->6->4->NULL 
    insertAfter(head->next, 8);       // Insert 8, after 7. So linked   list becomes 1->7->8->6->4->NULL   
    cout<<"Created Linked list is: ";   
	printList(head);  
    cout<<"\n\n";
   listcount(head);
   cout<<"\nSearch key Present in List :";
   searchkey(head,4) ? cout<<"yes" : cout<<"no";
   cout<<"\n \n";
   cout<<"\nSearch key Present in List :";
	searchkey(head,555) ? cout<<"yes\n" : cout<<"no\n"<<"\n";
	cout<<"\nNow Linked List Is : ";	  
	printList(head);
	nthnode(&head,4);
	printMiddle(head);
	NodeFrequency(head,1);
	printList(head);
    cout<<"\nLinkedList after Reversal :";
	reverse_iterative(head);
    head->next->next->next->next->next->next->next->next = head->next->next;  
    detect_and_remove_loop(head); 
    cout<<"\nLinkedList after Loop removal : ";
    printList(head);
   // deletenode(head,8);
   // cout<<"Linked List after deleting node: ";
	//printList(head);
	return 0; 	 
}  
