//
// Created by Wendy Wu on 2022-02-23.
//
#include <iostream>

using namespace std;

class SomeAwesomeClass{
    // 6 methods:
    // 1) constructor
    // SomeAwesomeClass sac1;
    // 2) destructor
    // ~SomeAwesomeClass();
    // 3) copy constructor:
    // SomeAwesomeClass sac2(sac1)
    // 4) copy assignment operator =
    // SomeAwesomeClass sac3;
    // sac3 = sac2
    // ----------- Since C++ 11 ---------------
    // 5) move constructor
    // 6) move assignment operator

};

class Aircraft{
public:
    Aircraft(){cout<<"Aircraft ctor"<<endl;}
    Aircraft(int n){
        capacity=n;
        cout << "Aircraft ctor with parameters" << endl;
    }
    // always make desturctor virtual if class is meant to be inherited
    virtual ~Aircraft(){cout<<"Aircraft~dtor"<<endl;}
    void setCapacity(int i){capacity = i;}
    // mark polymorphic method virtual
    virtual void fly(){cout<<"Aircraft flying: "<<capacity<<endl;}
    // pure virtual method should necessarily be implemented in the derived class
    // classes w/ virtual method are called abstract class
    virtual void land() = 0;
protected:
    int capacity;
};

// public --> remains public
// private --> public and protected becomes private
// protected --> public and protected becomes protected
class Boeing: public Aircraft{
public:
    Boeing(){cout<<"Boeing ctor"<<endl;}
    // assign default constructor
    Boeing(int n):Aircraft(n)
    {
        capacity=n;
        cout << "Boeing ctor with parameters" << endl;
    }
    ~Boeing(){cout<<"Boeing ~dtor"<<endl;}
    void fly() {cout << "Boeing flying: "<<capacity<<endl;}
    void land(){cout << "Boeing is landing."<<endl;}
};

//int main(){
////    Aircraft a;
////    a.setCapacity(50);
////    a.fly();
////
////    Boeing b;
////    b.setCapacity(100);
////    b.fly();
//
//
////    Boeing c(300);
////    c.fly();
//
//   Aircraft* af;
//   af = new Boeing(300);
//   af->fly();
//   delete af;
//
//
//    return 0;
//}

