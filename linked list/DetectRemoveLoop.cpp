//removing loop using check one by one method
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};
void RemoveLoop(node*, node* );           //function prototype
void push(node **head_ref,int data){      //fuunction to pudh ne elements in node
    node* newnode = new node();
    newnode->data = data;
    newnode->next = (*head_ref);
    (*head_ref) = newnode;
}
int Detect_and_Loop(node *head){               //function to detect loop
node *slowptr = head;                     //two pointters fast and slow moving forward and traverse the LL if they meet it means loop exixts in LL
node *fastptr = head;
while(slowptr && fastptr && fastptr->next){             //traverse the LL till the end
	slowptr = slowptr->next;                            //slowptr incremented by 1 position at a time
	fastptr = fastptr->next->next;                      //fastptr incremented by two pointers at a time
	if(slowptr == fastptr){                             //if loop exists then remove loop using removeloop function
		RemoveLoop(slowptr,head);             
		return 1;                 //loop found!
	}
  }
  return 0;                 //no loop!
}
void RemoveLoop(node* loop_node, node* head){            
    node *ptr1 = head;                                   //take two pointers ptr1 points to the head of LL and ptr2 points the
	node *ptr2 = NULL;                                  
	while(1){                                           //keep repeating this process until loop breaks
		ptr2 = loop_node;                               //loopnode that we detects in the DetectLoop function
		while(ptr2->next != loop_node && ptr2->next != ptr1 )   //run this loop until it completes the loop or detect *ptr1 in its path
		ptr2 = ptr2->next;
		if(ptr2->next == ptr1)
		break;
		ptr1 = ptr1->next;                             //once loop is traversed , move *ptr1 to next node
	}
	ptr2->next = NULL;                                 //disconnect *ptr1 from *ptr2 and remove the loop by setting ptr2->next = NULL
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
	push(&head,1);push(&head,2);push(&head,82);push(&head,72);push(&head,62);  
	cout<<"\nLL before creating loop : ";
	print(head);
	cout<<"\nIf you want to see loop then comment the next instruction in code !\n";
    head->next->next->next->next->next = head->next->next;   //here creating loop
    Detect_and_Loop(head);                                   //now removing loop
    cout<<"\nLL after removing loop : ";
    print(head);
    return 0;
}
