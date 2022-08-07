#include<iostream>
using namespace std;
int lootHouse2(int arr[],int n){

    int ans[n];
    ans[0] = arr[0];
    ans[1] = max(arr[0],arr[1]);

    for(int i = 2; i <n;i++){

        ans[i] = max(ans[i-1] , ans[i-2] + arr[i]);
    }
    return ans[n-1];
}
int lootHouse1(int arr[],int n){

    if(n<=0){
        return 0;
    }
    int sum1 = lootHouse1(arr + 2,n-2);
    int sum2 = lootHouse1(arr+1,n-1);

    return max(arr[0] + sum1,sum2);
}
int main(){

    int n ; 
    cin>>n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
     }

    cout<<lootHouse2(arr,n);
}