//decaring variable as reference means it will share the same address of the variable passed to the reference
#include<iostream>
using namespace std;
void increment (int &n)//passing by reference
{
n++;	
}
// BAD PRACTICE
int &f(int n)//returning by refernce 
{
	int a =n;
	return a;
}
// BAD PRACTICE
int *f2()//
{
	int i=10;
	return &i;
}

int main()
{
	int *p=f2();//(( BAD PRACTICE )) as variable we are trying to use are not declared in the scope of the function main so it might give error
	int i=20;
	increment(i);
	cout<<i<<endl;
	
	int &k1=f(i);//catching by reference (((  BAD PRACTICE !!!!!!!)))
	int &j=i;//declaring j as refernce variable means no new memory will be created for j .
	i++;
	cout<<j<<endl;
	/*  int i;
	i=10;
	int &j;
	j=i;    this doesnt work coz when a reference variable is created its memory should be initialized at the time of creation else it 
	        will give an error    
	*/
	
	int k=100;
	j=k;
	cout<<i<<endl;
	
}
