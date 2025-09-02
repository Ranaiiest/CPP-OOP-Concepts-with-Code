#include<bits/stdc++.h>
using namespace std;


//-----------------------------------------------------------------OOP Concepts-----------------------------------------------------

// 1.------------------------------------------------------------- class and obj--------------------------------------------------
// class -> class is a user defined data type that works as a blueprint
// to create obj that shares similar properties (data) and behaviours (function)
// object -> instance of a class


class Human1 {

    public : // access modifier
    int age;
    string name;
    
    Human1(int age,string name){
        this->age = age;
        this->name = name;
    }
    Human1(){
        cout<<"Arise !"<<endl;
    }

    ~Human1(){
        // destructor
        cout<<"this object is destroyed !"<<endl;
    }
    
    void sleeping(){
        cout<<"I am sleeping !"<<endl;
    }

    void eating(){
        cout<<"I am eating !"<<endl;
    }
};

// can we create class inside a class as a member of it in cpp ?
// -> yes

// why do we need class when there is already struct ?
/*
-> while both class and struct can be used to create user-defined
data types and support inheritance 
1. Intensions : classes are generally used to implement more complex
data types but structs are more suitable for simpler data types.

2. Default member access: classes have private members by default,
while structs have public members by default.

3. Default Inheritance access : class inheritance is private by
default but struct inheritance is public by default.
while both classes and structs can be used to implement user 
defined data type but classes prioritize more on data abstraction
principle than others.

*/





// 2.--------------------------------------------------------------------Access modifiers ----------------------------------------------------
// there is 3 types of access modifiers :-
/*

by setting access modifiers we can control the visibility of members
of class  
1. Public : Members declared as public are accessible from outside the class.
2. Private : Members declared as private are accessible only within the class.
3. Protected : Members declared as protected are accessible within the class 
and its derived subclasses.

NOTE : the private members can also be accessed outside the class via 
friend class or functions.

*/



// 3. -----------------------------------------------------Encapsulation-----------------------------------------------------
/*
defn : Encapsulation means combining data and the functions that work on that 
data into a single unit, like a class

Encapsulation is implemented using class 
*/



// 4. ----------------------------------------------------------------Abstraction-----------------------------------------------------------------------
/*
defn : Abstraction is a technique to hide complex inner implementation 
details from the user and expose only the necessary parts.

there is 2 ways to achieve abstraction : 
 -> abstraction using access modifier or specifier
 -> abstraction using abstract keyword
*/

// -> Abstraction using access specifier
/*
the data members declared as private and the functions (getter & setter)
are declared as public. 
*/
class Calculator{
    private :
        int a,b;
    public :
        void setValues(int x, int y){
            a = x;
            b = y;
        }
        int add(){
            return a + b;
        }
        int subtract(){
            return a - b;
        }
};

// -> abstraction using abstract keyword
/*
    by creating abstract class and pure virtual function we can hide the confedential data and expose
    only the necessary parts or behaviours.
*/
class Vehicle { // as it has atleast one pure virtual function hence it is a abstract class
    public: 
        virtual void MakeSound(){ // virtual function 
            // It says : "Hey, if there is implementation in my derived class then pls execute that"
            // "else execute this !"
            cout<<" peep peep !"<<endl;
        }

        virtual void Declare() = 0; // pure virtual function
};

class Car : public Vehicle {
    
    public:
        void MakeSound(){
            cout<<" vroom vroom !"<<endl;
        }

        void Declare() {
            cout << "I am a Car." << endl;
        }
};


// 5. ---------------------------------------------------------------Constructor---------------------------------------------------------
// there is 3 types of constructor :
/*
    default constructor : a public constructor which is provided by the compiler to create
        objects.
    parameterized constructor : a constructor that takes arguments
    copy constructor : a constructor that creates a new object as a copy of an existing object
*/

// code 
class SmartPhone{
    public :
        string brand;
        string model;
        // we don't need to write default construct it is automatically provided by the compiler
        SmartPhone(); // default constructor
        SmartPhone(string brand, string model){ // parameterized constructor
            this->brand = brand;
            this->model = model;
        }
        SmartPhone(const SmartPhone &sp){ // copy constructor
            this->brand = sp.brand;
            this->model = sp.model;
        }
};





// 5.------------------------------------------------------------Inheritance---------------------------------------------------------
// there is 3 types of inheritance :
/*
    single inheritance : a class (derived class) inherits from one base class
    multiple inheritance : a class (derived class) inherits from multiple base classes
    multilevel inheritance : a class (derived class) inherits from another derived class
*/

/*
Inheritance Table (Access Modifiers)
-----------------------------------
Base Class Member Access 	Public Inheritance	Protected Inheritance	Private Inheritance
public	                    public	            protected	            private
protected	                protected	        protected	            private
private	                    Not accessible	    Not accessible	        Not accessible

constructor of base class vs constructor of derived :-
case 1 : the base class doesn't have any explicit constructor created in it or it has the default constructor provided by compiler at runtime not compile time
         then we this default constructor will be called automatically if no constructor is created for the derived class.

case 2 : now if the derived class have a constructor explicitly mentioned then compiler doesn't call the default constructor of base class automatically in this 
         case we need to write explicit constructor for the derived class to call the base class constructor.

*/


// code
class Animal {
    private:
        string species;
    public:
        Animal(string species ){
            this->species = species;
        }
        void Eat() {
            cout << "Animal is eating." << endl;
        }
};

class Dog : public/*here this access modifier means whatever public in base class that will be also public in derived class (public Inheritance)*/ Animal {
    
    public:
        Dog(string species) : Animal(species) { // here we taking argument and call the base class i.e animal class constructor
            // Constructor body (if needed)
        }
        void Bark() {
            cout << "Dog is barking." << endl;
        }
};




// ----------------------------------------------------Destructor--------------------------------------------------------------------
// it is used to destroy or free up the space allocated to a object.
// code : 
class Human {
public: // access modifier
    int age;
    std::string name;

    Human(int age, std::string name) {
        this->age = age;
        this->name = name;
    }
    Human() {
        std::cout << "Arise !" << std::endl;
    }

    ~Human() {
        // destructor
        std::cout << "this object is destroyed !" << std::endl;
    }

    void sleeping() {
        std::cout << "I am sleeping !" << std::endl;
    }

    void eating() {
        std::cout << "I am eating !" << std::endl;
    }
};

void scope_example() {
    std::cout << "--- In scope_example() ---" << std::endl;
    Human stackHuman; // Statically allocated
    std::cout << "--- End of scope_example() ---" << std::endl;
} // Destructor for stackHuman is called here.

void f() {
    std::cout << "--- In main() ---" << std::endl;

    // Static object (on the stack)
    Human h1; // Uses the default constructor "Arise !"
    h1.age = 25;
    h1.name = "Alice";
    
    // Dynamic object (on the heap)
    Human* h2 = new Human(30, "Bob");
    
    std::cout << "h1 is on the stack." << std::endl;
    std::cout << "h2 is on the heap." << std::endl;
    
    // Calls a function that creates a stack object
    scope_example();

    // Destroy the dynamically allocated object
    delete h2; // Destructor for the object h2 points to is called here.

    std::cout << "--- End of main() ---" << std::endl;
    
} // Destructor for h1 is called here.

// output : 
/*
--- In main() ---
Arise !
h1 is on the stack.
h2 is on the heap.
--- In scope_example() ---
Arise !
--- End of scope_example() ---
this object is destroyed !
this object is destroyed !
--- End of main() ---
this object is destroyed !
*/


//--------------------------------------------------Polymorphism--------------------------------------------------------------------
// polymorphism means many forms, As the name suggests it allows methods or function with same name having multiple forms in different context.
// Types : 1. compile time or early binding ( where which function form is to be invoked is done at compile time )
//               -> Function Overloading ( overload the function having same names with different arguments or return types )
//               -> Operator Overloading (overload the standard operators like +,-,*,/ to work differently in diff context)
//         2. Run time or dynamic binding ( where which function form is to be invoked is done at run time )
//              It is achieved with the help of virtual function and inheritance

// Function Overloading----------------------------
class AddClass {
public:
    
    // Function to add two integers
    void add(int a, int b) {
        cout << "Integer Sum = " << a + b
        << endl;
    }
    
    // Function to add two floating point values
    void add(double a, double b) {
        cout << "Float Sum = " << a + b
        << endl ;
    }
};

// Operator Overloading-----------------------------
class Complex {
public:
    int real, imag;
    
    Complex(int r, int i) :
    real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real,
        imag + obj.imag);
    }
};

void test_Operator_overloading() {
    Complex c1(10, 5), c2(2, 4);
    
    // Adding c1 and c2 using + operator
    Complex c3 = c1 + c2;  
    cout << c3.real << " + i" << c3.imag;
}

// Function Overriding 

class Base {
public:

    // Virtual function
    virtual void display() {
        cout << "Base class function";
    }
};

class Derived : public Base {
public:

    // Overriding the base class function
    void display() override {
        cout << "Derived class function";
    }
};

void test_Function_overriding() {
    
    // Creating a pointer of type Base to point to derived class address
    Base* basePtr;

    // Creating an object of Derived class
    Derived derivedObj;

    // Pointing base class pointer to derived class object
    basePtr = &derivedObj;
    
    // Calling the display function 
    // using base class pointer
    basePtr->display(); // o/p -> Derived class function ( with virtual function )
                        // o/p -> Base class function ( without virtual function )
}



//------------------------------------------------------Friend function & classes ---------------------------------------------------------
// friend functions are functions that can access private and protected members of a class
// even though they are not members of that class
// friend function
class Box {
    private:
        double width;
    public:
        Box(double w) : width(w) {}
        
        // Declaring a friend function
        friend void printWidth(Box box);
        friend class Test; // friend class
};

void printWidth(Box box) {
    cout << "Width of box: " << box.width << endl;
}

// friend class
class Test {
    public:
        void displayWidth(Box box) {
            cout << "Width of box (from friend class): " << box.width << endl;
        }
};



int main(){

    // -----------------------------Working with Human class ---------------------------------------
    // method 1 to create objects in cpp 
    // create a pointer obj to the class 
    Human1 *objP = new Human1(); // dynamic obj created in the heap memory using  a pointer (dynamic allocation )
    objP->sleeping();
    objP->eating();

    // method 2 
    // create object
    Human1 obj; // static object created in the stack ( static allocation )
    obj.sleeping();
    obj.eating();

    // method 2.1
    Human1 obj2(25, "John");// this will automatically call
    // the parameterized constructor
    obj2.sleeping();
    obj2.eating();

    // as the pointer obj objP is dynamically allocated hence we can deallocate them using delete keyword
    delete objP;// destructor will be called 

    // -----------------------------Working with Animal class(For Inheritance) ---------------------------------------
    Dog d("Canine");
    d.Eat();
    d.Bark();

}