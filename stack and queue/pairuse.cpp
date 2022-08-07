#include<iostream>
using namespace std;
#include "templates.cpp"
int main()
{
    Pair<Pair <int,int>,int> p1;
    p1.sety(10);
    Pair<int,int> p4 ;
    p4.setx(15);
    p4.sety(16);
    p1.setx(p4);
     cout<<p1.gety();
     cout<<p1.getx().getx();

    


}