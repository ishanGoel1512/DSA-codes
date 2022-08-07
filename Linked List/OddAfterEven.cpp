#include<iostream>
using namespace std;
#include "node.cpp"
void OddAfterEven(Node *head)
{        
     if(head==NULL || head->next==NULL)
        {
            return head ; 
        }
        ListNode* OddH  = NULL ;
        ListNode* OddT  = NULL ;
        ListNode* EvenH = NULL ;
        ListNode* EvenT = NULL ; 
        
        while(head!=NULL)
        {    
            
            if((head->val)%2!=0){
            if(OddH==NULL)
            {
                OddH = head ;
                OddT = head ;
            }
            else
            {
                OddT->next = head ;
                OddT = OddT->next ; 
            }
            }
            if((head->val)%2==0)
            {
                if(EvenH==NULL)
            {
                EvenH = head ;
                EvenT = head ;
            }
            else
            {
                EvenT->next = head ;
                EvenT = EvenT->next ;
            }
            }
            head= head->next ; 
            }
         if(OddH == NULL)
        {
            return EvenH ; 
        }
        if(EvenH == NULL)
        {
            return OddH ; 
        }
        OddT->next = NULL ;
        EvenT->next = NULL ; 
        OddT->next = EvenH ; 
      
        return OddH ; 
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
  Node *head_new = OddAfterEven(head);
  print(head_new);
 

   
}