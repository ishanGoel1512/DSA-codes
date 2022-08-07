#include<iostream>
using namespace std;
#include "PriorityQueue.h"
int main(){


    PriorityQueue p ; 
    p.insert(10);
    p.insert(5);
    p.insert(12);
    p.insert(6);
    p.insert(8);
    p.insert(5);

    // for(int i = 0 ; i < p.; i++){
    //     cout << p.RemoveMax()<<endl;;
    // }
        
    cout<<p.getMax()<<endl;
    cout<<p.getSize()<<endl;
    while(!p.isEmpty()){
        cout<< p.RemoveMax()<<" ";
    }
    cout<<endl;
}