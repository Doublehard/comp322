//
// Created by Wendy Wu on 2022-02-23.
//
#include <iostream>
#include <exception>

using namespace std;

class ZeroException: public exception{
    // first const is for return type;
    // second const is for method what():
    // -- telling compiler the method will not alter the state of the object
    // throw():
    // -- this method guarantee not to throw exceptions
    // -- can be replaced with noexcept (since c++ 11)
    virtual const char* what() const throw(){
        return "Warning: Division by Zero.";
    }
};

class SomeOtherException:public exception{
public:
    virtual const char* what() const noexcept{
        return "Some other exception";
    }
};

ZeroException divideByZeroException;
SomeOtherException someOtherException;

double getRatio(double  a, double  b){
    if(b==0){
        throw divideByZeroException;
    }
    return a/b;
}

//int main(){
//    try {
//        try{
//            double ratio1 = getRatio(5,15);
//            double ratio2 = getRatio(5,0);
//        } catch (exception& e){
//            cout << e.what() << endl;
//            throw someOtherException;
//        }
//    } catch (exception& e){
//        cout << "Other catch:" << e.what() << endl;
//    }




    return 0;
}

