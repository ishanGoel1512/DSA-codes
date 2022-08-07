#include<iostream>
using namespace std;
int coinChange2(int *arr , int n  ,int w){ /// space optimization 
    int *table = new int[w+1];
    for(int i = 0 ; i < w+1 ;i++)
    {
        table[i] = 0;
    }

    table[0] = 1;
    for(int j = 0 ; j < n;j++){
        for(int i = 1; i < w+1;i++){
            if((i - arr[j]) >= 0){
                 table[i] = table[i-arr[j]] + table[i];   
            }
    }
    }
    return table[w];
    delete [] table;
}
int coinChange1(int *arr , int n  , int w){
        if(w==0){
            return 1;
        }
        if(w<0){
            return 0;
        }
        if(n<=0){
            return 0;
        }
        int smallAns1 = coinChange1(arr,n,w-arr[n-1]);
        int smallAns2 = coinChange1(arr,n-1,w);
        
        return smallAns1 + smallAns2;
}
int main(){

    int n ; 
    cin>>n;
    int * arr = new int[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    int w ;
    cin>>w;
    cout<< coinChange2(arr,n,w);
}