#include<bits/stdc++.h>
using namespace std;

//-------------------------------------------------Virtual class & function ------------------------------------------------------
// Virtual Func :- virtual function gives you the ability to achieve runtime or dynamic polymorphism 
// the aim of virtual function is to execute the most derived version of the base class function

// Pure Virtual Func :- a virtual function in the base class having no implementation and it says its 
//  derived classes to define the member pure virtual function 
// a class containing at least one pure virtual function is called abstract class
// for example say, there is a instrument class so the instrument doesn't have any physical existance 
// and hence has no actual sound the pure virtual function named MakeSound() is defined without any 
// implementation and says its derived classes such as piano or guiter or flute to define the member 
// pure virtual function
// NOTE : the derived must implement the pure virtual functions of base class 

// abstract class : like java's abstract class or interface here also we cannot create objects of abstract class

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

class Truck : public Vehicle {
    public : 
        void Declare(){
            cout << "I am a Truck." << endl;
        }
};



int main(){
    Vehicle *v = new Car(); // upcasting 
    v->MakeSound(); // peep peep !  // because of early binding without using virtual keyword i.e not a virtual function
    v->MakeSound();// vroom vroom ! // because of late binding using virtual keyword i.e virtual function
    v->Declare();

    Car c;
    c.MakeSound();

    Vehicle *vv; // NOTE : it is not obj it is a pointer, we are allowed to create pointer of abstract class
    Truck c;
    vv = &c;
    vv->MakeSound();

    //Vehicle v; // will give error : "object of abstract class type "Vehicle" is not allowed"
}