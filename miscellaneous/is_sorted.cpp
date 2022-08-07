#include<iostream>
using namespace std;
bool is_sorted( int a[], int size )
{
	if (size==0||size==1)
	{
		return true;
	}
	if (a[0]>a[1])
	{
		return false;
	}
	bool is_smallsorted=is_sorted(a+1, size-1);
	return is_smallsorted;
}
int main(){
	int a[]= {11,2,4,5,6};
	is_sorted(a,5);
	
	
}
