/// TO MAKE A PROPERTY OF AN OBJECT CONSTANT 
class Student()
{
public:
int age;
int &x; /// age reference variable
const int rollNumber;
Student(int r,int a ):rollNumber(r), age(a),x(this->age); ///// USING  INITIALIZATION LIST
                                             ///// THESE ARE CONSDIDERED TO BE EXECUTED AT THE TIME CREATION
{

}


};