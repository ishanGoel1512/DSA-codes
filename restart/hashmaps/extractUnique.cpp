#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std; 
string extractUnique(string a , int size){
   string ans ; 
    unordered_map<char,int> m;  /// when accessing single elements they are considered character 
    for(int i = 0 ; i < a.length();i++){
        if(m.count(a[i])>0){
            m[a[i]]+=1;
        }
        else{
            m[a[i]] = 1;
        }
    }
    for(int i = 0 ; i < a.length();i++){
        if(m[a[i]]!=0){
            ans+= a[i];
            m[a[i]] = 0 ; 
        }
        else{
            continue ;
        }

    }

    return ans;
}
int main(){
    string a = "ababacd";
    cout<< extractUnique(a,a.length());
}