#include<iostream>
using namespace std;
#include "node.cpp"
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

Node *insertNode(Node *head, int i, int data)
{
     Node *newNode = new Node(data);
     int count=0;
     Node *temp = head;
     if(i==0)
     {
         newNode->next=head;
         head=newNode;
         return head;
     }
     while(temp!=NULL && count<i-1)
     {
         temp = temp->next;
         count++;

     }
     if(temp!=NULL){
     newNode->next=temp->next;
    temp->next= newNode;
     }
     return head;
     /*Node *a=temp->next;
     temp->next=newNode;
     newNode->next=a;
*/
}

void print(Node *head)
{
    Node *temp=head;
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
  int i,data;
  cin>>i>>data;
  head=insertNode(head,i,data);
  print(head);


    // statically creating objects 
   /* Node n1(1) ;
    Node *head=&n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    print(head);



    n1.next=&n2;
    
   // cout<<n1.data<<" "<<n2.data<<endl;
   //DYNAMICALLY 
   Node *n3 = new Node(10);
   Node *head=n3;
   Node *n4 = new Node(20);
   n3->next=n4;
   */
}