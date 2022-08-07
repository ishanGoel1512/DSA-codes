#include<iostream>
using namespace std;
#include<string>
int shortSubs(string s, string t){   /// brute force
    if(s.size()==0 ){
        return INT16_MAX;
    }
    if(t.size()<=0){
        return 1;
    }
        int smallAns1 = shortSubs(s.substr(1),t);
        int len = 0;
        for(int i = 0 ; i < t.size();i++){
            if(t[i] == s[0]){
                len = i;
                break;
            }
        }
        int smallAns2 = shortSubs(s.substr(1),t.substr(len + 1));

        return min(smallAns1,1 + smallAns2);
}
int main(){
    string s ,v ;
    cin >> s >> v;
    cout << shortSubs(s,v);
}