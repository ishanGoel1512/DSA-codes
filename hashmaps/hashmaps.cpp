#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int> ourMap ;
    //INSERT
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["dfe"]=2;     //// if we put a key in "[]" which doesnt exist then it takes its value as 0 and insert it in our map

    
    //ACCESSS
 
}