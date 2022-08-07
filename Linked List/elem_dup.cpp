#include<iostream>
using namespace std;
#include "node.cpp"
void elem_dup(Node *head) 
{    Node *t1 = head;
     Node *t2 = head->next;
    if (head==NULL || head->next==NULL)
    {
        return;
    }
   
while(t2!=NULL)
{
    if(t1 ->data!=t2->data)
    {   t1->next= t2 ; 
        t1 = t1->next;
        t2 = t2 ->next;

    }
    else {    
            
             t2 = t2 ->next ;  
              
    
       

    }

} 
t1->next= t2 ;
    



}
Node *takeInput_better()
{
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;       ///// DONE TO IMPROVE THE COMPLEXITY OF THE PREVIOUS INPUT FUCNTON
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if (head==NULL)
        {
            head=newNode;
            tail=newNode;

        }
        else{
            tail->next=newNode;
            tail=tail->next;
            /*Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;*/


        }
        cin>>data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
       
    }
}
int main()
{

  Node *head=takeInput_better();
  elem_dup(head);
  print(head);
 

   
}