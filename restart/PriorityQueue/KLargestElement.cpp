#include<iostream>
#include<queue>
using namespace std;
int KLargestElement(int *a , int size, int k){
    priority_queue<int> pq;
    for(int i = 0 ; i < size;i++){
        pq.push(a[i]);
    }
    for(int i = 0;i < k-1 ;i++)
{
    pq.pop();
}  
    return pq.top();
}
int main(){
    int a[]={2,6,10,11,13,4,1,20};
    cout<<KLargestElement(a,8,4)<<endl;
}