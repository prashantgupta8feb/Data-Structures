// Merge two given sorted linked list in O(1) auxiliary space


// today I started with merge two arrays and later on starts another easy stuff on LL as to check 
// if I can do easy things on LL or not and the answer is still not 100% yes!

/* push,
   delete_node,  
   delete alternate elements, 
   display, 
   merge two sorted linked list,
   detect loop, delete loop M1, 
   remove duplicates,
   reverse LL by iterative & recursive method,  */

#include<iostream>
#include<algorithm>

using namespace std;
struct node
{
    int data;
    node* next;
};
void push(node* *headref,int data)
{
    
    node* newnode = new node();
    newnode->data = data;
    newnode->next = (*headref);
    (*headref) = newnode;
    
}
void delete_key(node** head,int key)
{
    node* temp=*head;
    node* prev=NULL;
    if(temp!=NULL && temp->data==key)
    {
        *head = temp->next;
        delete temp;
        return;
    }   
    while(temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    return;

    prev->next=temp->next;
    delete temp;
}
void deleteAlt(struct node *head){             //function to delete alternate key in a LL
    // Code here
    node* alter;
    int count=0;
    while(head!=NULL)
    {
     count++;
     if(count%2!=0)
     {
        alter = head->next->next;
        delete(head->next);
        head->next = alter;
     }
     if(count%2==0)
     {
         continue;
     }
     head=head->next;
    }
}
void display(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

node* merge_two_sorted_LL(node* l1,node* l2)            //using recursion merge two sorted LL
{
    node* result=NULL;
    if(l1 == NULL)
        return(l2);
    else if(l2 == NULL)
        return(l1);

    if(l1->data <= l2->data)
    {
        result=l1;
        result->next = merge_two_sorted_LL(l1->next,l2);   
    }
    if(l1->data > l2->data)
    {
        result = l2;
        result->next = merge_two_sorted_LL(l1,l2->next);
    }
    
    return result;
    
}

void remove_loop_M2(node* loopnode,node* head)          //loop removal method 2
{
    node* ptr1=loopnode;
    node* ptr2=loopnode;
    unsigned int  count = 1;int i;
    while(ptr1->next!=ptr2)
    {
        ptr1=ptr1->next;
        count++;
    }
    ptr1=head;ptr2=head;
    for(i=0;i<count;i++)
    ptr2=ptr2->next;

    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    while(ptr2->next!=ptr1)
    ptr2=ptr2->next;
    ptr2->next=NULL;
}
void remove_loop_M1(node* loopnode,node* head)           //check by 1 method of loop removal
{
    node* ptr1=head;
    node* ptr2=NULL;
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

void detect_loop(node* head)                              //To delete detected loop
{
    int count=0;
    node* slowptr=head;
    node* fastptr=head;
    int flag=1;
    while (slowptr!=NULL)
    {
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr)
        {
            flag=0;
            cout<<" Loop Detected at "<<slowptr->data<<" !";
            // remove_loop_M1(slowptr,head);
            remove_loop_M2(slowptr,head);
            break;
        }
    }
    if(flag==1)
        cout<<" No loop detected!";
    
}

node* remove_duplicate(node* head)                       //remove duplicate keys from sorted LL
{
    node* current=head;
    node* next_next;
    if(head->next==NULL) return head;
    while(current->next!=NULL)
    {
        if(current->data==current->next->data)
        {
            next_next=current->next->next;
            free(current->next);
            current->next=next_next;
        }
        else
         current=current->next;
 }
    return head;
}

node* reverse_iter(node* head)                    //Reverse LL iteratively
{
    node *prev,*current,*next;
    prev=NULL;next=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
    /*while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;*/
}

 node* reverse_recursive(node* head)                   //Reverse LL recursively
{
    if(head==NULL || head->next==NULL)
    return head;
    node* rest = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main()
{
    //MERGING
   /* node* merge1 = NULL;
    push(&merge1,4);push(&merge1,2);push(&merge1,1);
    cout<<"List1 before merge :";
    display(merge1);
    node* merge2 = NULL;
    push(&merge2,4);push(&merge2,3);push(&merge2,1);
    cout<<"\nList2 before merge :";
    display(merge2);
    node* res=merge_two_sorted_LL(merge1,merge2);
    cout<<"\nResultant LL after merge :";
    display(res);*/
    
    
    //REMOVE DUPLICATES FROM SORTED LL
   /* node* head=NULL;
    push(&head,20);push(&head,13);push(&head,13);push(&head,11);push(&head,11);
    display(head);
    node* dup=remove_duplicate(head);
    display(dup);*/
    

    //LOOP DETECTION AND DELETION
    node* to_check_loop=NULL;
    push(&to_check_loop,50);push(&to_check_loop,20);
    push(&to_check_loop,15);
    push(&to_check_loop,4);push(&to_check_loop,10);
    cout<<"\nBefore loop :";
    display(to_check_loop);
    to_check_loop->next->next->next->next->next = to_check_loop->next->next;
    // display(to_check_loop);
    cout<<"\nNow detecting loop :";
    detect_loop(to_check_loop);
    cout<<"\nLL after loop removal : ";
    display(to_check_loop);

    //DELETING NODE
   /* cout<<"\nLinked List before deleting key :";
    display(head);
    delete_key(&head,30);
    cout<<"\nLinked List after deleting node :";
    display(head);*/

    //REVERSE LL ITERATIVELY
    /*cout<<"\nReverse LL by Iterative method :";
    node* iter_head = reverse_iter(head);
    display(iter_head);*/

    //REVERSE LL RECURSIVELY
    /*cout<<"\nRverse LL by Recursive method :";
    node* rec_head = reverse_recursive(head);
    display(rec_head);*/

    //DELETE ALTERNATE ELEMENTS FROM LL
   /* node* alternate_del=NULL;
    push(&alternate_del,1);push(&alternate_del,2);push(&alternate_del,3);
    push(&alternate_del,4);push(&alternate_del,5);push(&alternate_del,6);
    display(alternate_del);
    deleteAlt(alternate_del);
    display(alternate_del);*/

}