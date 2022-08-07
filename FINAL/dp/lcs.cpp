#include<iostream>
using namespace std;
#include<string>
int lcs2(string s,string t){
    
}
int lcs(string s, string t){   /// brute force
 // Base case
    if (s.length() == 0 || t.length() == 0)
    {
        return 0;
    }
    // recursive calls
    if (s[0] != t[0])
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
    else
    {

        return 1 + lcs(s.substr(1), t.substr(1));
    }
}
int main(){
    string s ,v ;
    cin >> s >> v;
    cout << lcs(s,v);
}