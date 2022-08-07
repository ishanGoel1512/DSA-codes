#include<iostream>
#include<queue>
using namespace std;
void KSmallestELements(int *a , int n ,int k){
    priority_queue<int> pq;
    for(int i = 0 ; i < k ;i++){
        pq.push(a[i]);
    }
    for(int i = k ; i < n ;i++){
        if(a[i] < pq.top()){
            pq.push(a[i]);
            pq.pop();
        }
        else{
            continue;
        }
    }

    for(int i = 0 ; i < k ;i++){
    cout<<pq.top()<<" ";   
     pq.pop(); 
    }
}

int main(){
    int a[]={8,5,12,10,0,1,6,9};
    KSmallestELements(a,8,4);
}