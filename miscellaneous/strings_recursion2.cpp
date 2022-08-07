//WAP  to remove x from te string and print the new string 
#include<iostream>
using namespace std;
void removeX(char s[])
{
	if (s[0]=='\0'){
		return;
	}
	if (s[0]!='x'){
	 removeX(s+1);
	}
	
	else {
	
	int i=1;
	for(;s[i]!='\0';i++)
	{
		s[i-1]=s[i];
	}
	
	s[i-1]=s[i];  ////  moving the null character also
	removeX(s); //// taking the finalstring
}
}
int main()
{
	char str[100];
	cin>>str;
	
	removeX(str);
	cout<<str<<endl;
	
}
