//
// Created by Wendy Wu on 2022-02-23.
//
#include <iostream>
#include <list>

using namespace std;

// typename and class are interchangeable
template <typename T>
T getmax(T a, T b){
    return (a>b)?a:b;
}

// =double: DEFAULT is double value
template <typename T,typename U=double >
void printValues(T t, U u){
    cout << "first value: " << t
         << ", and second value: " << u << endl;
}

template<typename T>
T subtract(T a, T b){
    return a - b;
}

template <>
string subtract(string a, string b){
    size_t pos = a.find(b);
    string str = a.substr(0,pos);
    return str;
}

template <typename T, int scale = 1>
class Coordinates{
        T x,y,z;
public:
        Coordinates(T a, T b, T c){
            x = a*scale;
            y = b*scale;
            z = c*scale;
        }
        T getX(){
            return x;
        }
        T getY();
    };

template<typename T, int scale>
T Coordinates<T,scale>::getY() {
    return y;
}

//int main(){
//    float myFloatMax = getmax<float>(12.1,120.3);
//    int myIntMax = getmax<int>(15,7);
//    double myDoubleMax = getmax<double>(12.1,120.3);
//
//    string a = "Hello World";
//    string b = "World";
//    cout << subtract<string>(a,b) << endl;
////    printValues<int>(9,12.11);
//
//    Coordinates<int> pointi(2,4,-3);
//    Coordinates<float,2> pointf(2.1,4.9,-3.7);
//    cout << pointf.getX() << endl;
//
//    list<int> intList;
//    list<int>::iterator it;
//    intList.push_front(12);
//    intList.push_front(22);
//    intList.push_front(46);
//
//    for (it=intList.begin();it!=intList.end();++it) {
//        cout << *it << endl;
//    }
//
//    return 0;
//}


