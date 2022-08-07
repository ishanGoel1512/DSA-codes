//static properties are those whose copiies are not created when an object is created
// static properties are only accessed by scope resolution operator
// its initialisation is done outsie the class with the help of scope resolution
//if we access these properties using object , it is allowed by compiler BUT WE SHLD NOT ACCESS IT LIKE THIS
//STATIC FUCNTION DOESNT HAVE ACCESS TO THIS KEYWORD
class Student(){


    int age;
    static int total_students;
}
int Student::total_students=0;