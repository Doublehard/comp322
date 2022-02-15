//
// Created by Wendy Wu on 2022-02-14.
//
#include <iostream>
using namespace std;

class Person{
//    access modifier
public:
//    considered "inline"
    bool canVote(){
        if(age>=18){
            return true;
        } else{
            return false;
        }
    }
    void setAge(int age){
        this->age = age;
    }
    void setSex(char sex){
        this->sex = sex;
    }
    char getSex();
    int getAge();
    char* getName();
    Person();
    Person(int a, char s);
    Person(int a, char s, char* n);
//    destructor: implicit destructor will NOT delete dynamic allocated memory
    ~Person();
private:
    int age;
    char sex;
    char* name;
};

//define method outside the class, if want inline, need to use keyword
inline char Person::getSex(){
    return this->sex;
}
inline int Person::getAge(){
    return this->age;
}
inline char* Person::getName() {
    return this->name;
}
//constructor
Person::Person() {
    this->age = 0;
    this->sex = 'U';
    this->name = new char[7];
    strcpy(this->name,"UNKNOWN");
}
Person::Person(int a, char s) {
    this->age = a;
    this->sex = s;
    this->name = new char[7];
    strcpy(this->name,"UNKNOWN");
}
Person::Person(int a, char s, char* n) {
    cout << "Constructor got called" << endl;
    this->age = a;
    this->sex = s;
    this->name = new char[strlen(n)];
    strcpy(this->name, name);
}
//initialization list: perferred because of better performance
//Person::Person():age(0), sex('U'){}
//Person::Person(int a,char s):age(a),sex(s){}
Person::~Person() {
    cout << "destructor got called" << endl;
    delete[] this->name;
}



//int main(){
//    Person Mike;
//    Mike.setAge(24);
//    Mike.setSex('M');
//    Person Wendy(24,'F');
//    cout << "Wendy's age = " << Wendy.getAge() <<endl;
//    if (Mike.canVote()){
//        cout <<"Mike is eligible to vote" << endl;
//    } else{
//        cout <<"too bad for Mike" << endl;
//    }
//
//    Person X(100,'M',"Mr. X");
//
//    return 0;
//}

