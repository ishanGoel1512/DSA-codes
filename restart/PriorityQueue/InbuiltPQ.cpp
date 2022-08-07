#include<iostream>
#include<queue>
using namespace std;
//// By default inbuilt pq is max Priority Queue
int main(){
    //priority_queue<int> p ; /// MAX HEAP INITIALIZATION
    priority_queue<int ,vector<int>, greater<int>> p; /// MIN HEAP INTIALIZATION
    p.push(100);
    p.push(145);
    p.push(123);
    p.push(112);
    p.push(11);
    cout<<"size : "<<p.size()<<endl;
    cout<<"Top :"<<p.top()<<endl;
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
    
}