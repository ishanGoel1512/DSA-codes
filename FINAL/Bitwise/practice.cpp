#include<iostream>
using namespace std;
int main(){
    ///Swapping
    // int a = 5 ; 
    // int b = 7 ;
    // a = a^b;
    // b = a^b; 
    // a = a^b;
    // cout<<a<<" "<<b;
    ///////////////////////////
    ///No. of bits to change from a to b 
    int a = 270;
    int b = 230;
    int temp  = a^b;
    int count = 0; 
    while(temp!=0){
        temp = temp & (temp-1);
        count++;
    }
    cout<< count ;

}