#include <iostream>
using namespace std;
int main()
{
	int m,n ;
	cin>>m>>n;
	int **p=new int *[m];
	for (i=0;i<n;i++)
	{
		p[i]=new int [i];// we can create an array of unequal rows and columns.     new int [i+1]
		for(j=0;j<n;j++)
		{
			cin>>p[i][j];
		}
	}
	for (i=0;i<m;i++)
	{
		delete [] p[i];
	}
	delete [] p;
}
