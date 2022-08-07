//// THINK EVERY PROBLEM OF RECURSION AS THE PROBLEM OF PMI ( PRICNIPLE OD MATHEMATICAL INDUCTION )
#include<iostream>
using namespace std;
int factorial(int n)
{
	if (n==0)    /// BASE CASE 
	{return 1;
	}
	int smallOutput= factorial(n-1);  /// INDUCTION HYPOTHESIS
	return n*smallOutput ;             //// INDUCTION STEP
}
int main()
{
	int n;
	cin>>n;
	int output=factorial(n);
	cout<<output<<endl;
}
