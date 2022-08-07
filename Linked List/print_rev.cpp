#include<iostream>
using namespace std;
#include "node.cpp"
 Node* reverseList(Node* head) {
        if(head==NULL || head->next==NULL){
            return head ;
        }
        Node* full = reverseList(head->next);
        Node* temp = head->next;
        temp->next = head;
        head->next = NULL ;
        
        return full;
        

    }
    
    bool isPalindrome(Node* head) {
            int count = 0;
            int c=0,d=0;
            int length = 0 ; 
            Node* temp1 = head ; 
            while(temp1!=NULL)
            {
                length++ ;
                temp1=temp1->next ; 
            }
            cout<<length ; 
         
            Node *temp = head;
            Node *second = reverseList(head);
            cout<<second->data<<endl;
            bool small = second->data == temp->data ;
            cout<<small;
            for(int i=0 ; i<length;i++){
                c++;
                cout<<c<<".";

                if(second->data != temp->data){
                     count = 1; 
                     break;
                   
                }
                else{
                     temp = temp->next ; 
                    second = second->next;
                    d++;
                    cout<<d<<"..";
                
                   
                    cout<<"u";
                }
                cout<<count ; 
            }
            
            if(count == 1){
                
                return false;
            }else{
                 cout<<"u1";
                return true;
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
        cout<<temp->data<<" ";
        temp=temp->next;
       
    }
}
int main()
{

  Node *head=takeInput_better();
  print(head);
  cout<<endl;
  /*Node* temp = reverseList(head);
  print(temp);*/
  cout<<isPalindrome(head)<<endl;

  

   
}