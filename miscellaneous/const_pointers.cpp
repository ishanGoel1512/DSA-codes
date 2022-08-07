#include<iostream>
using namespace std;
void g(int const &j)    
{
	j++;   ////// ERROR 
}
void f(int const *p){
	(*p)++;    ///////ERROR
}
int main()
{
	int const i=10;
	int const *p=&i;  /// a pointer of a constant integer has to be constant 
	
	// CONSTANT POINTER
	
	int k=10;
	int l=20;
	int const *p =&i;    // p is a pointer to a constant ineteger
	p=&j;            
	
	int * const p=&i;    //// p is a constant pointer to an integer
	(*p)++;      // I CAN DO THIS 
	p=&j;                 /// therefore it will give error
	
	int const * const p3=&i;
	//(*p3)++;      BOTH WILL GIVE ERROR
	//p3=&j ;

}
