#include<iostream>
using namespace std;
#include "node.cpp"
Node * Appendlast(Node *head,int n )
{   Node * temp = head;
int count = 0 ;
   while(count<(Node::j)-n-1 )
   {   
          temp =temp->next;
          count++;
   }
    Node * a =temp-> next ; 
    temp ->next= NULL;
    Node * h2 = a; 
    Node *temp_2 = h2 ; 
    Node *tail =NULL;
    while(temp_2!=NULL)
    {
        tail = temp_2 ;
        temp_2 = temp_2 ->next;
    }
        
        tail->next=head;
        return h2 ;
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
  int n;
  cin>>n;
  head =Appendlast(head, n);
  print(head);
  
 

   
}