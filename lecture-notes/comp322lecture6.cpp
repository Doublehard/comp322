//
// Created by Wendy Wu on 2022-02-14.
//
class Person{
public:
    bool canVote(){
        if(age>=18){
            return true;
        } else{
            return false;
        }
    }
    int age;
    char sex;
};

#include <iostream>
using namespace std;

int main(){
    Person Mike;
    Mike.age = 24;
    Mike.sex = 'M';
    if (Mike.canVote()){
        cout<<"Mike is eligible to vote" << endl;
    } else{
        cout<<"too bad for Mike" << endl;
    }


    return 0;
}

