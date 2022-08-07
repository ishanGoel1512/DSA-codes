#include<iostream>
using namespace std;
#include "student1.cpp"
int main(){
char name[]="abcd";
    Student1 s1(20,name);
    s1.display();
    name[3]='e';
   /* Student1 s2(20,name);
    s2.display();
    s1.display();*/
    Student1 s2(s1);
    s2.display();
    s1.display();
}