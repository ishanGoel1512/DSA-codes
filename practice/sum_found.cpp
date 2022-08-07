#include<iostream>
using namespace std;
/*int dup_Remove(int *p,int sum ,int t)
{    int temp[100];
    if[t==0]
    {
        return;
    }
    if(p==p+1)
    {p= temp;
    return temp;
    }
    else{
        p=temp;
        temp=[];
    }    
    return temp;
    dup_Remove(p+1,sum,t-1);
}*/
int main()
{
    int sum,t;
    int *p=new int[t];
    cin>>"No. of elements =">>t>>endl;
    cin>>"Sum">>sum>>endl;
    cin>>"Elements of array =">>*p>>endl;
    //dup_Remove(p,sum,t);
    cout<<"Sorted Array = "<<*p<<endl;
}