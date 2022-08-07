/*    Two types of memory :
      1. Stack ( created at RUN -TIME )
         a. small memory 
         b.created  at compile time
         c.automatcally erased on basis of scope
      2.Heap ( created at COMPILE-TIME )
         a. large memory 
         b. created at run time 
         c. we have to earse it manually
         Memory in  Heap cant be created directly so we use ' new' keyword which doesnt have any name and always returns the 
         ADDRESS of the dynamically allocated memory
         e.g
         int a[200000];   (((   CREATED IN STACK AT COMPILE TIME )))))) it will work propely as satck will take the requied memory 
         
         int n;   HERE STACK  will start with less memory ; if user gives a very big integer,  it might happen tht stack memory doesnt have
                    tht much space 
         cin>>n;
         int a[n]; 
        
*/
#include<iostream>
using namespace std;
int main()
{
	int *p =new int;
	*p=10;
	cout<<*p<<endl;
	int *pa= new int[50] ;// creating an array in heap
	//max no. in an array
	int n;
	cout<<"enter the no. of elements= ";
	cin>>n;
    int * pa2= new int[n];
    for(i=0; i<n; i++)
    {
    	cin>>pa2[i];
    	
	}
	int max=-1;
	for(i=0; i<n; i++)
	{
		if (max< pa[i]){
			max=pa[i];
		}
		cout<<max<<endl;
		
	}
   		
	
}
