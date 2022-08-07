#include<iostream>
using namespace std;
#include "node.cpp"
Node *insert_recursive(Node *head , int i,int data)
{     
     Node *newNode=new Node(data);
     if (head==NULL)
     {
         return head;
     }
    
    
       if(i==0)
     {  
         newNode->next=head;
         head=newNode;
         return head;
        
    }
    
    Node *temp=insert_recursive(head->next,i-1,data);
    head->next=temp;
    return head;
    

}
Node *input_better()
{  
     int data;
     cin>>data;
     Node *head=NULL;
     while(data!=-1)
     {
        Node *newNode= new Node(data);
         if (head==NULL)
         {
             head=newNode;
         }
         else{
             Node *temp=head;
             while(temp->next!=NULL)
             {
                 temp=temp->next;
             }
             temp->next=newNode;
         }cin>>data;
     }
    return head;
}
void print(Node *head)
{  Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
int main()
{

    Node *head=input_better();
    Node *head_new;
    int i,data;
    cin>>i>>data;
    head_new=insert_recursive(head,i,data);
    print(head_new);
}