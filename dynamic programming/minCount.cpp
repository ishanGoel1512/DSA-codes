#include<iostream>
#include "math.h"
using namespace std; 
int minCount(int n )  ///// Brute Force
{    
    if(sqrt(n) - floor(sqrt(n)) == 0)
    {
        return 1;
    }
    if(n<=3)
    {
        return n ;
    }
    int min2 = n ; 
    for(int i = 1 ; i<=n ; i++)
    {    

        int temp = i*i ;
        if(temp>n)
        {break ;}
        else{
        min2 = min(min2 ,1 + minCount(n-temp));
        }
    }
    
     
return min2 ; 
}
int main()
{
    int n ; 
    cin>>n ;
    int ans = minCount(n);
    cout<<ans<<endl; 
}