#include<iostream>
using namespace std;
#include<math.h>
int minCount3(int n){

    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for(int i = 4;i<n ; i++){

        if(n == i*i){
            ans[n] = 1;
            return ans[n]
        }
        else {
               int temp = x * x;
            if (temp > i)
                break;
            else
                ans[i] = min(ans[i], 1 +
                                  ans[i - temp]);
        }
    }
    return ans[n];
}
int minCount_helper(int n , int* ans){  /// Memoization 
  if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
   if(n<=3){
       return  n;
   }

        if(ans[n]!=-1){
            return ans[n];
        }
    int res = n;
    for(int i = 1 ; i<=n ;i++){
            if(n >i*i){
               res = min(res,1 + minCount_helper(n - i*i , ans)) ;
               ans[n] = res;
            }
            else{
                break; 
            }
    }
  return ans[n];


}
int minCount2(int n ){
    int* ans = new int[n+1];
    for(int i = 0 ; i <= n;i++){
        ans[i] = -1;
    }
    return minCount_helper(n,ans);
}
int minCount(int n){  //Brute force
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
   if(n<=3){
       return  n;
   }

    int res = n;
    for(int i = 1 ; i<=n ;i++){
            if(n >i*i){
               res = min(res,1 + minCount(n - i*i)) ;
              
            }
            else{
                break; 
            }
    }
  return res;
}
int main(){
     int n ; 
     cin>>n;
     cout<< minCount3(n)<<endl;
}