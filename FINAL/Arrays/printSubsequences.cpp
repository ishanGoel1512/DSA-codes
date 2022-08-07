#include<iostream>
using namespace std;
#include<string>
void printSubsequences(string input , string output){
    // Base case
    if(input.empty()){
        cout<<output<<endl;;
        return;
    }

    // recursive calls
    printSubsequences(input.substr(1) ,output );
    printSubsequences(input.substr(1) , output + input[0] );


}
int main(){
    string s ; 
    cin>>s;
    string output; 
    printSubsequences(s , output);


}