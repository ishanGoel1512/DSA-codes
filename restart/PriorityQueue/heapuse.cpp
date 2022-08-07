#include<iostream>
using namespace std;
#include "PriorityQueue.h"

int main(){
    PriorityQueue p;
      p.insert(10);
      p.insert(17);
      p.insert(19);
      p.insert(14);
      p.insert(112);
      p.insert(0);
      p.insert(187);
    
    cout<<p.getMin()<<endl;
    cout<<p.getSize()<<endl;
    while(!p.isEmpty()){
        cout<< p.RemoveMin()<<" ";
    }
    cout<<endl;
}