#include<iostream>
#include<queue>
using namespace std; 
///// USing the pair class approach fails as the persons are standing in a queue so we have to maintain a queue 
int BuyTicket(int *a , int n , int k )
{   queue<int> l; 
    
    for(int i = 0; i < n ; i++) {
         l.push(i);   // -> Indices of Persons
    }
    
    priority_queue<int> pq;
    
    for(int i = 0 ; i < n ; i++){
        pq.push(a[i]); // -> Priority of persons in maxHeap
    }
    
    int time = 0;
    while(l.front()!=k ||  pq.top()!=a[l.front()]){
        if(pq.top()!=a[l.front()]){
            l.push(l.front());
            l.pop();
            
        }
        else {
            pq.pop();
            l.pop();
            time++;
        }
    }
    return time+1;
}
int main(){
    int a[] = {3,9,4};
    cout<< BuyTicket(a,3,2)<<endl;
}