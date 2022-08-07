#include<iostream>
using namespace std;
int minSteps3(int n )
{
    int *ans = new int[n+1];
    ans[1]=0;
    int x ,y , z ; 
   
    for(int i = 2 ;i<=n;i++)
    { 
         x = INT16_MAX;
         y = INT16_MAX;
         z = INT16_MAX;
        if(i%2==0)
        {
            x = 1 + ans[i/2];
        }
        if(i%3==0)
        {
            y = 1 + ans[i/3]; 
        }
         z = 1 + ans[i-1];
        ans[i] = min(x, min(y,z));
}
return ans[n];
}
int minSteps1_helper(int n , int *a)  //// memoization
{
    if(n<=1)
    {
        return 0 ; 
    }
    if(a[n]!=-1)
{
    return a[n];
}
int step1 = minSteps1_helper(n-1,a);
    int step2 = INT16_MAX;
    int step3 = INT16_MAX;
    if(n%2==0 )
    {

        step2 = minSteps1_helper(n/2,a);
    
    }
    if(n%3==0)
    {
        
        step3 = minSteps1_helper(n/3,a);
        
    }
    int ans = min(step1,min(step2,step3)) + 1;
    return ans;
    
 
    


}
int minSteps1(int n )
{
    int *a = new int[n+1];
    for(int i=0 ;i<=n;i++)
    {
        a[i] = -1 ;
    }
    return minSteps1_helper(n,a);
}
int minSteps(int n )   //// BRUTE FORCE 
{
    if(n<=1)
    {
        return 0 ; 
    }
    int step1 = minSteps(n-1);
    int step2 = INT16_MAX;
    int step3 = INT16_MAX;
    if(n%2==0 )
    {

        step2 = minSteps(n/2);
    
    }
    if(n%3==0)
    {
        
        step3 = minSteps(n/3);
        
    }
    int ans = min(step1,min(step2,step3)) + 1;
    return ans;
    
 
    

}
int main()
{
    int n ; 
    cin>>n;
    int steps = minSteps3(n);
    cout<<steps<<endl; 
}