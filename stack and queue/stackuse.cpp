#include<iostream>
using namespace std;
#include "StackUsingLL.cpp"
int main()
{
   Stack<int> s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);
   cout<<s.top()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.getSize()<<endl;
cout<<s.is_Empty()<<endl;


}