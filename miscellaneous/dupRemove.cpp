#include<iostream>
using namespace std;
void dupRemove(char s[])
{
	if(s[0]=='\0')
	{
		return;
	}
	
	if (s[0]!=s[1])
	{
		dupRemove(s+1);
	}
	else {
	
	int i=1;
	for (;s[i]!='\0';i++)
	{
		s[i-1]=s[i];
	}
	s[i-1]=s[i];   
	dupRemove(s);
}
}
int main()
{
	char str[100];
	cin>>str;
	dupRemove(str);
	cout<<str<<endl;
}
