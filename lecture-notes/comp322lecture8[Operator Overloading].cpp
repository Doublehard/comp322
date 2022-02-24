//
// Created by Wendy Wu on 2022-02-23.
//

#include <iostream>

using namespace std;

class myVector{
public:
    myVector():x(0),y(0),z(0){}
    myVector(int a, int b, int c):x(a),y(b),z(c){}
    void display(){
        cout << x << ", " << y << ", "<< z <<endl;
    }
    myVector operator+(const myVector& v){
        myVector result;
        result.x = x+v.x;
        result.y = y+v.y;
        result.z = z+v.z;
        return result;
    }
    // member method
    ostream& operator<< (ostream& os){
        os << x << ", " << y << ", " << z;
        return os;
    }
    // friend method (preferred)
    friend ostream& operator <<(ostream& os, const myVector& vec);
private:
    int x,y,z;
};

ostream &operator<<(ostream &os, const myVector &vec) {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}


//int main(){
//    myVector v1(2,4,6);
//    myVector v2(3,5,7);
//    v1.display();
//    v2.display();
//
//    myVector v3 = v2+v1;
//    cout << v3;
//
//    return 0;
//};

