#include<iostream>
using namespace std;
template <typename T>
class Node
{
    public:
    T data;
    Node<T> *next;
    

    Node(T data)
    {
        this->data=data;
        next=NULL;
      
    }
};
template <typename T>
class Stack
{
  Node<T> *head ; 
  T element ; 
  int size ; 
  public:
  Stack()
  {
      head=NULL;
      size = 0 ; 
  }



  public:

  void push(T element)
  {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head ; 
        head = newNode ; 
        size++;
  }
  int getSize()
  {  
      return size; 

  }
  bool is_Empty()
  {
      return size==0;
  }
  T pop()
  {
     
      if(is_Empty())
      {
         
          return 0;
      }
      
          T ans = head->data ; 
          Node<T> *temp = head ;
          head = head ->next ;
          delete temp ; 
          size--;
          return ans ; 
      
  }
  T top()
  {    
       if(is_Empty())
      {
         
          return 0 ;
      }
      return head->data ; 
      
  }

};