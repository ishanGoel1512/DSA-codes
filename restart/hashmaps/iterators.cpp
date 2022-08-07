#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> ourmap;
     ourmap["abc"] = 1;
     ourmap["abc1"] = 1;
     ourmap["abc2"] = 1;
     ourmap["abc3"] = 1;
     ourmap["abc4"] = 1;

     unordered_map<string,int> ::iterator it = ourmap.begin();
     while(it!=ourmap.end()){
         cout<<"key:"<<it->first<<" Value : "<<it->second<<endl;
         it++;
     }

////find  -> gives an iterator 
    unordered_map<string,int>::iterator it2 = ourmap.find("abc");
    ourmap.erase(it2);

     vector<int> v;
     v.push_back(1);
     v.push_back(2);
     v.push_back(3);
     v.push_back(4);
     v.push_back(5);
     vector<int> ::iterator it1 = v.begin();
     while(it1!=v.end()){
         cout<<*it1<<endl;
         it1++;
     }
 
}