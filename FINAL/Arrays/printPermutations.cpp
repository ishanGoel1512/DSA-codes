#include<iostream>
using namespace std;
#include<string>
void printPermutations(string input , string output){

    //  base case 
    if(input.size()==1)
    {   
        output = output + input[0];
        cout<< output<<endl;
        return;
    }

    // recursive call
    for(int i = 0 ; i < input.size() ; i++){
        printPermutations(input.substr(0,i) + input.substr(i+1,input.size()-i-1) , output + input[i]);
        
    }
    return;
}
int main(){
    string input ; 
    cin >> input;
    string output; 
    printPermutations(input , output);
}