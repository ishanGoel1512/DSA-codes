#include<iostream>
using namespace std;
int minCount(int n){
   
    if(n==0 || n==1 || n==2 || n==3){
        return n;
    }

    int ans = INT16_MAX;
    for(int i = 1;i*i<=n ;i++){
        ans = min(1 + minCount(n - i*i),ans);
    }
    return ans;
}
int main(){

    int n ;
    cin>>n;
    cout<<minCount(n);
}