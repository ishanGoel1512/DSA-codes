#include<iostream>
using namespace std; 
#include<string>
int subsequences(string input , string output[]){
    // base case 
    if(input.size()==0){
        output[0] = "";
        return 1 ; 
    }

    // recursive call
     int smallAns = subsequences(input.substr(1) , output);
        
    //small calculation
    for(int i = 0 ; i < smallAns ; i++){
        output[smallAns + i ] = input[0] + output[i];
    }
    return 2 * smallAns;
}
int main(){
    string input ; 
    cin>> input ; 
    string *output =new string[1000];
    int length = subsequences(input , output);
    for(int i = 0 ; i <  length;i++){
        cout<< output[i] <<endl;
    }
}