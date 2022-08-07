#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
 vector<int> factorial(int N){
        vector<int> sum;
        sum[0] = 1 ; 
        sum[1] = 1 ; 
        for(int i = 2 ; i <=N ; i++){
            sum[i] = sum[i-1]*i ; 
        }
        
        int top = sum[N];
        vector<int> ans ; 
          while(top!=0 ){
              
            ans.push_back(top % 10);
            top = top/10;
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }
int main(){
    int n ;
     cin>>n;
     vector<int> output = factorial(n);
     for(int i = 0 ; i < output.size() ; i++){
            cout << output[i];
     }
}