#include<iostream>
using namespace std;
#include "Trie.h"
#include<string>
#include<vector>
int main(){
    vector<string> t;
    t.push_back("abc");
    t.push_back("def");
    t.push_back("ghi");
    t.push_back("cba");
    Trie l ;
   
   cout <<  l.palinPair(t)<< endl;
}