#include<iostream>
using namespace std;
void printSubsets(int input[] , int n , int output[] , int m){

    // base case
    if(n==0){
        for(int i = 0 ; i < m ; i++){
            cout << output[i] <<" ";
        }
        cout<<endl;
        return;
    }

    // recursive callls
    printSubsets(input + 1 , n-1 , output , m);

    int newOutput[m + 1];
        for(int i = 0 ; i < m  ; i++){
        newOutput[i] = output[i];
    }

    newOutput[m] = input[0];
    printSubsets(input + 1 , n-1,newOutput,m+1);



}
int main(){
    int n ; 
    cin>>n;
    int *input = new int[n];
    for(int i = 0 ; i <  n ; i++)
    {
        cin>>input[i];
    }

    int m ; 
    int* output = new int[m];
    printSubsets(input , n  , output , 0);
}