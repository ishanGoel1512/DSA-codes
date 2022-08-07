#include<iostream>
using namespace std;
int main()
{
	// constant variable 
	const int i=10;      
	
	/* 
	
	const int i;    ((((((((   CANT DO THIS COZ IT WILL TAKE A GARBAGE VALUE AS CONSTANT AND WILL NOT ALLOW TO CHANGE ))))))
	i=10;
	*/
	
	//constant refernce from a non constant variabe 
	int j=12;
	const int &k =j;
	//k++;                    When we declare a variable constant , its storage doesnt become constant ; its path become cosntant 
	j++;
	cout<<k<<endl;
	
	
	//constant reference from a constant variable 
	
	      const int j 2=12;
	      const int &k2 = j2;
	      // WE CANT DO ANYHTING 
	      j2++;
	      k2++;
	      
	      //reference from a constant integer
	      int const j3=10;
	      int &k3=j3;  /////       CANT DO THIS AS WE DONT HAVE ACCESS TO WRITE J3 , WE CAN ONLY READ IT
	      k3++;
	
}
