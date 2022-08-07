
class Student1{
    public:
int age ;
char *name;


Student1(int age , char *name )
{
    this->age=age;
    ////SHALLOW COPY (COPY THE ADDRESS OF THE ARRAY)
    //this->name = name ;

    //DEEP COPY  (CREATING A NEW ARRAY  DYNAMICALLY SO THAT CHANGES DO NOT REFLECT IN OUR VARIABLE )
    this->name = new char[strlen(name) + 1];
    strcpy(this->name , name );// COPYING OLD ARRAY TO NEW ARRAY SO THT CHANGES CAN BE REFLECTED
}
//MANIPULATING COPY CONSTRUCTOR
Student1(Student1 const &s)          ///// IT IS PASSED BY REFERENCE AS IT WLL GO INTO LOOP COZ WE HAVE MADE OUR OWN COPY CONSTR. 
{                                    //// NOW WHEN COPY CONSTR. IS CALLED , AS WE HAVE PASSED BY REFERENCE AND MADE IT  CONSTANT SO THT IT DOEANT ALLOW AN ILLEGAL CHANGES

    this->age=s.age;

    this->name=new Student1[strlen(s.name)+1];
    strcpy(this->name,s.name);
}
void display()
{
    cout<<name <<" "<<age;
}
};

