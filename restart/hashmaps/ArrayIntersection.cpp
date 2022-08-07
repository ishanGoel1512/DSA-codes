#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void ArrayIntersection(int *a ,int *b , int n , int m ){
    unordered_map<int,int> m1 ;  
    for(int i = 0 ; i < n;i++){
        if(m1.count(a[i])>0){
            m1[a[i]]+=1;
        }
        else{
            m1[a[i]]=1;
        }
    }
     for(int i = 0 ; i < m ;i++)
     {
         if(m1[b[i]]>=1){
             cout<<b[i]<<" ";
             m1[b[i]]--; 
         }
     }
    
}
int main(){
int a[]= {2,6,1,2};
int b[]={1,2,3,4,2};
ArrayIntersection(a,b,4,5);
}