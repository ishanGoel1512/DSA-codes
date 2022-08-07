#include<iostream>
using namespace std;
#include<string>
class Mapping{
    string s ; 
    string e ;
};
Mapping codes(string s){

    int  num = stoi(s);
    string e = num + 'a' - 1;
}
int main(){
    string input ; 
    cin>> input ; 
    string *output =new string[1000];
    int length = returnallCodes(input , output);
    for(int i = 0 ; i <  length;i++){
        cout<< output[i] <<endl;
    }
}