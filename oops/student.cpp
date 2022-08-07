#include<iostream>
using namespace std;
class Student()
{//// BY DEFALUT , ACCESS MODIFIER IS PRIVATE SO W NEED TO  MAKE IT PUBLUC
public:
    int Age ;

    private:
    int RN;

    public:
    void display()
        {
            cout<<Age<<" "<<RN<<endl;
        }
        ///Getter fucntions 
    int getRoll()
    {
        return RN;
    }
           //////SETTER FUNCTION
    void setRoll(int a )
    {
            Age=a;
    }
}