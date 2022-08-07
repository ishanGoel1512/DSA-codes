// DELETION OF DYNAMICALLY ALLOCATED MEMORY
// WHENEVER MEMORY IS DYNAMICALLY ALLOCATED WE HAVE TO DELTE THE MEMORY CREATED DYNAMICALLY ELSE IT WILL OCCUPY ALL THE MEMORY , HENCE APPS CRASHES
#include<iostream>
using namespace std;
int main(){
	
	/*while(true)     ////    accessing same  memory evrytime 
	{
		int i=10;
	}
	while(true)
	{
		int *p = new int;      /////// creating new memory every time
		
	}*/
	int *p=new int;
	delete p;
	p = new int ;
	delete p;              // single element deletion
	p= new int[100];
	delete [] p;           // array deletion
	
	
	
	
}
