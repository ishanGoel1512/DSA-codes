#include<iostream>
using namespace std;
int staircase3(int n){           /// Dynamic Programming
 
    int *ans = new int[n+1];
    ans[0] = 1 ; 
    ans[-1] = 0 ; 
    ans[1] = 1 ;
    for(int i = 2 ;  i <=n;i++){
        ans[i]= ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[n];

}
int staircase_helper(int n , int *ans){  // Memoization
    if(n < 0 ){
        return 0;
    }
    else if(n==0){
        return 1;
    }

    /// check if output already exists 
    if(ans[n] != -1){
        return ans[n];
    }

    ans[n] = staircase_helper(n-1 , ans)+staircase_helper(n-2,ans)+staircase_helper(n-3,ans);
    return ans[n];
}
int staircase2(int n){  // Using Memoization
    int *ans = new int[n+1];
    for(int i = 0 ; i <=n;i++){
        ans[i] = -1;
    }
    return staircase_helper(n,ans);
}
int stairCase(int n){ 
                      /// Using Brute Force
    if(n<0){
        return 0 ;
    }
    else if(n==0){
        return 1;
    }

    return   stairCase(n-1) + stairCase(n-2) + stairCase(n-3);
}
int main(){
    int n ; 
    cin >>n;
    cout << staircase3(n) <<endl;
}