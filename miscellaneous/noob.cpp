#include<iostream>
using namespace std;
int power(int n )
{
    if(n/10 == 0)
    {
        return 1 ;
    }
    int ctr = 1 + power(n/10);
    return ctr++;
}

int main()
{
    int n;
    cin>>n;
    int ans = power(n);
    cout<<ans<<endl;

}