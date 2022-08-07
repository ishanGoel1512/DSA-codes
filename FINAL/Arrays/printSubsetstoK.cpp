#include<iostream>
using namespace std;
void printSubsetstoK(int input[] , int n , int output[] , int m , int k ){
    if(n==0){
        if(k==0){
            for(int i = 0 ; i < m ; i++){
            cout << output[i] <<" ";
        }
            cout<<endl;
            return;
        }
        else{
            return;
        }
    }

    printSubsetstoK(input + 1 , n - 1, output , m , k );
    int newOutput[m + 1];
    for(int i = 0 ; i < m ; i++){
        newOutput[i] = output[i];
    }
    newOutput[m] = input[0];
    printSubsetstoK(input + 1, n-1, newOutput, m+1, k-input[0]);

}
int main(){
     int n ; 
     cin>>n;
    int *input = new int[n];
    for(int i = 0 ; i <  n ; i++)
    {
        cin>>input[i];
    }
    int k;
    cin>>k;
    int m ; 
    int* output = new int[m];

    printSubsetstoK(input , n  , output , 0 , k);
}