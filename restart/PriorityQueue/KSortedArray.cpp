#include<iostream>
#include<queue>
using namespace std; 
void KSortedArray(int *a ,int size,int k ){
    priority_queue<int> pq;
    for(int i = 0 ; i < k ;i++){
        pq.push(a[i]);
    }
     //// after this we will get a n-k sorted array 
    /// the remaining array need to be sorted 
    int j = 0 ; 
    for(int i = k ; i < size ; i++){
        a[j++] = pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    // remaining k array 
    while(!pq.empty()){
        a[j++] = pq.top();
        pq.pop();
    }

}
int main(){
    int a[]={12,15,7,4,9};
    KSortedArray(a,5,3);
    for(int i = 0 ; i < 5 ;i++){
        cout<<a[i]<<" ";
    }
    
}