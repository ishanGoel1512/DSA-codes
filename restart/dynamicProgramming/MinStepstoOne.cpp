#include<iostream>
using namespace std;
int minStepsToOne3(int n){

    int *ans = new int[n+1];
    ans[1] = 0 ; 
    ans[2] = 1 ; 
    ans[3] = 1 ;
    for(int i = 4 ; i<=n;i++){
        int x = 0 ; 
        int y = INT16_MAX , z = INT16_MAX;
        if(i%2 == 0 ){
            y = ans[i/2];
        }
        if(i%3 == 0 ){
            z = ans[i/3];
        }
        ans+= 1 + min(x,min(y,z));
    }
    return ans[n];

}
int minStepsToOne_helper(int n , int *ans){   ///Memoization 

    if(n<=1){
        return 0 ; 
    }

    /// check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
     int x = minStepsToOne_helper(n-1,ans);
        int y = INT16_MAX;
        int z = INT16_MAX;
        if(n%2 == 0){
            y = minStepsToOne_helper(n/2,ans);
        }
        if(n%3 == 0){
            z = minStepsToOne_helper(n/3,ans);
        }
    
    ans[n] = 1 +  min(x,min(y,z)); 
    return ans[n];

}
int minStepsToOne2(int n){
 
    int *ans = new int[n+1];
    for(int i = 0 ; i <=n;i++){
        ans[i] = -1;
    }
    return minStepsToOne_helper(n,ans);
}
int minStepstoOne(int n){  // Brute Force
    
    if(n<=1)
    {
        return 0;
    }
        int x = minStepstoOne(n-1);
        int y = INT16_MAX;
        int z = INT16_MAX;
        if(n%2 == 0){
            y = minStepstoOne(n/2);
        }
        if(n%3 == 0){
            z = minStepstoOne(n/3);
        }

       return 1 +  min(x,min(y,z)); 
}
int main(){
    int n ; 
    cin>>n;
    cout<< minStepsToOne3(n)<<endl;
}