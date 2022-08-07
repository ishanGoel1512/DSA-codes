#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> ourMap ; ///keep values and keys in form of pair 
    //insert
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"] = 2 ; 
    //find or access
    cout<< ourMap["abc"]<<endl;
    cout<<"size :" <<ourMap.size()<<endl;
    cout<<ourMap.at("abc")<<endl;
    //cout<<ourMap.at("def")<<endl; //give error 
    cout<<ourMap["ghi"]<<endl; // if not present inserts in the map 
      cout<<"size :" <<ourMap.size()<<endl;
    //check presence
    if(ourMap.count("ghi") > 0 ){
        cout<<"ghi is present"<<endl ;
    }
    ///erase 
    ourMap.erase("ghi");
     if(ourMap.count("ghi") > 0 ){
        cout<<"ghi is present"<<endl ;
    }

}