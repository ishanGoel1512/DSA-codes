#include<iostream>
using namespace std;
#include "node.cpp"
int find_node(Node *head,int data)
{  Node *temp = head;
int count=0;

      while(temp!=NULL)
      {
          temp=temp->next;
          count++;
          if (data==temp->data)
          {
              return count;
          }
          else 
          {
              return -1 ;
          }
          
          

      }
     /* if(temp==NULL || data!= temp->data)
      {
          return -1 ;
      }

     */
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
  int data;
  cin>>data;
  int index =find_node(head, data);
  cout<<index;
 

   
}