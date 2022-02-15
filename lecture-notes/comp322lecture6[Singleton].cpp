//
// Created by Wendy Wu on 2022-02-14.
//

#include <iostream>

using namespace std;

class Singleton{
public:
    static Singleton& getUniqueInstance(){
        static Singleton instance;
        return instance;
    }
    void doSomething(){
        cout<<"Ahhhhh"<<endl;
    }

private:
    Singleton();
    ~Singleton();
    Singleton(Singleton &);
    Singleton operator= (Singleton &);
};

//int main(){
//    Singleton& mySingleton = Singleton::getUniqueInstance();
//    mySingleton.doSomething();
//
//    return 0;
//}