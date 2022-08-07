#include<iostream>
using namespace std;
#include<string>
bool checkAB(string input){

    //  base case 
        if(input.size()==0){
            return true;
        }

    // small calculation 
     if(input[0]=='a')
        return true; 
    else
        return false;

    if(input[0]=='b'){
        if(input[1]=='b'){
            return checkAB(input.substr(2)) ;
        }
    }    
    return checkAB(input.substr(1)); 
}
bool checkABHelper(string input){

    if(input[0]=='a'){
        return checkAB(input.substr(1));
    }
    else
    return false;
}
int main(){
    string input; 
    cin>>input; 
    cout<< checkABHelper(input);
}