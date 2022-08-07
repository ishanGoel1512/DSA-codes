#include<iostream>
using namespace std;
int main()
{
	int i= 65;
	char c=i;// implicit typecasting(system do on its own)
	cout<<c<<endl;
	
	int *p = &i;
	char *pc =(char*) p;// explicit typecasting
	
	cout<<p<<endl;
	cout<<pc<<endl;//output
	
	cout<<*p<<endl;
	cout<<*pc<<endl;
	cout<<*(pc + 1 )<<endl;
	cout<<*(pc + 2 )<<endl;
	cout<<*(pc + 3 )<<endl;
	  
	/*when we run this program , we find tht we get our integer value at *pc only , coz int is not stored in a serial order , it is stored 
	in a reverse order.
	1.Little Endian(last byte is put at first)( Most systems are of this type )
	2. Big Endian
	*/
	
	
}




