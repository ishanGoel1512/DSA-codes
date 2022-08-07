#include<iostream>
using namespace std; 
int staircase(int n){
    if(n <=3){
        return n; 
    }
        int a = staircase(n-1);
        int b = staircase(n-2);
        int c = staircase(n-3);

        return a + b + c + 1;

}
int main(){

    int n ; 
    cin>>n;
    cout << staircase(n);
}