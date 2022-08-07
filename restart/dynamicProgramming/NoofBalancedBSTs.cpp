#include<iostream>
using namespace std;
#include<math.h>
#define mod 1000000007
int BalancedBSTCount(int n){
    if(n <= 1){
        return 1 ;
    }
    int x = BalancedBSTCount(n-1); /// Mulitplication  because of independent events
    int y = BalancedBSTCount(n-2);

    int temp1 = ((int)(( (long)(x) * x ) % mod ));
    int temp2 = ((int)(( 2 *(long)(x) * y ) % mod ));
    int ans = (temp1 + temp2) % mod;
   // int ans = (x*x + 2*x*y) % mod;/// this also may go out of bound separately also 
    return ans;
}       
int main(){

    int n ; 
    cin>>n;
    cout<< BalancedBSTCount(n) <<endl;

}