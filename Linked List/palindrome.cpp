#include<iostream>
using namespace std;
#include "node.cpp"
bool palindrome(Node *head)
{    if(head==NULL)
{
    return true; 
}
    
    
    Node *temp= head;
     int count = 0 ;
     while(count<(Node::j/2))
     {  
         temp = temp->next;
         count ++ ; 

     }
     Node *h2 = temp->next;
     Node *t2=h2  ; 
     int i = 0;
     while(i<(Node::j)/2)
     { 
         t2 = t2 ->next;
         i++;  

     }
     while (h2!=NULL)
     {
         t2->next=h2 ;

     }
     for(int k = 0 ; k<(Node::j/2);k++)
     {      
         while(head!=temp || t2!=NULL){
         if(t2->data ==head->data)
         {
             t2=t2 ->next;
             head=head->next;
         }
         }
          
     }
     






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
  print(head);
  bool is_true = palindrome(head);
  cout<<is_true;

   
}