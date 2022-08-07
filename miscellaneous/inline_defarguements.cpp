#include<iostream>
using namespace std;

inline int max(int a , int b)// making fucntion inline 
{
	return (a>b)?a:b
}
	//DEFAULT ARGUEMENTS
	//sum of array from any index
	int sum(int a[], int size ,int si=0)// putting si=0 means if we not pass the value of si in the fnc arguement , it will take value 0
	{
		int ans=0;
		for (i=si;i<size;i++)
		{
			ans+=a[i];
		}
		return ans;
	}
int sum2(int a, int b,int c=0, int d=0)//// equivalent to the creation of 3 functions
{
	return a+b+c+d;
}



int main()
{    
/*if  we have to use same fucntion multiple times in a code , then to decrease the run time of the code ; we use 'inline' keyword .
'inline'  copies the body of the declared fucntion at the location where the fucntion is called .

*/

	int a ,b;
	cin>>a>>b;
	int c=max (a,b);
	
	
	int x,y;
	cin>>x>>y;
	int z=max(x,y);
	

	
}
