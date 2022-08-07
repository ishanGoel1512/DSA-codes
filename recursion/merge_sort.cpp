#include<iostream>
using namespace std;
void merge_sort(int a[],int si, int ei)
{
	if (si>=ei)
	{
		return;
	}
	int mid= (si+ ei)/2;
	
	
	
	void m1[100]=merge_sort(a,si,mid);
	void m2[100]=merge_sort(a,mid+1,ei);
	void m3[100];
	int i=0;
	for(;i<=sizeof(m1);i++)
	{
		m1[i]=m3[i];
	}
	int j=i;
	for(i=0;i<=sizeof(m2);i++)
	{
		m2[i]=m3[j];
		j++;
	}
    
}

int main(){
	
	int a[]={1,7,5,3,6,9,3,8,0};
	int si, ei;
	cin>>si>>ei;
	merge_sort(a,si,ei );
	cout<<a<<endl;
}
