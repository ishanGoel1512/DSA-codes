#include<iostream>
using namespace std;
#include "student.cpp"
int main()
{
 //// creating objects statically
 Student s1,s2;
s1.Age=24;
s2.RN=101;
s1.display();


 //// creating objects dynamically
 Student *s3 =new Student ;
 
 (*s3).Age =24;////// BOTH ARE THE SAME THING
 s3->Age=24;
s3->display();

}