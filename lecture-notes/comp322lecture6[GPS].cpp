//
// Created by Wendy Wu on 2022-02-14.
//
#include <iostream>
using namespace std;

class GPS{
public:
    GPS(double altitude, double longitude, double latitude):
    altitude(altitude),longitude(longitude),latitude(latitude)
    {
        cout<<"GPS constructor called"<<endl;
    }
    ~GPS(){
        cout<<"GPS destructor called"<<endl;
    }
private:
    double altitude;
    double longitude;
    double latitude;
};

//int main(){
//    cout << "Program started ... " << endl;
//    GPS* gps;
//    cout << "A GPS pointer was being declared but nor allocated yet." << endl;
//    gps = new GPS(10,45.5017,73.5673);
//    cout << "GPS object was being allocated." << endl;
//    delete gps;
//    cout << "GPS object was being deleted." << endl;
//
//    return 0;
//}