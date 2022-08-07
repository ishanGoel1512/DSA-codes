#include<iostream>
using namespace std;
///// Approach using recursion earlier took O(2^n) complexity 
/// in order to improve the complexity ,we save the 
/// the values which we are calculating multiple times
/// Memoization 
int fibo(int n ){    /// Brute Force
    if(n<=1){
        return n; 
    }

    return fibo(n-1) + fibo(n-2); /// Bad Approach 
}
int fibo_helper(int n , int* ans){

    if(n <=1){
        return n;
    }

    // check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
        int a = fibo_helper(n-1,ans);
        int b = fibo_helper(n-2,ans);

       ans[n] = a + b ; 
       return ans[n]; 
}
int fibo_2(int n){     //// Memoization 
                       //// Top-Down Approach 
  
    int *ans = new int[n+1];
    for(int i = 0 ; i <= n ;i++){
        ans[i] = -1;
    }
    return fibo_helper(n,ans);
}
int fibo_3(int n ){    //// Dynamic Programming
                       //// Bottom up approach 

    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1]= 1; 
    for(int i = 2 ; i <=n ; i ++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}
int main()
{
int n ; 
cin>>n;
cout<<fibo_3(n)<<endl;

}