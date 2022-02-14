//
//  comp322lecture2.cpp
//  coursera-c++
//
//  Created by Wendy Wu on 2022-02-09.
//

#include <iostream>

using namespace std;

int factorial(int n);
int factorial_tail(int n, int accumulator);
int factorial_iter(int n);
double absV(double n);
int absV(int n);


//int main(){
////    cout << factorial_iter(5);
////    cout << "Please enter a number: "<<endl;
////    double n;
////    cin >> n;
////    cout << n <<"'s abs value = "<<abs(n)<<endl;
//    cout << absV(-4.3) <<endl;
//    return 0;
//}

int absV(int n){
    return (n<0)? -n:n ; 
}

//overloading
double absV(double n){
    return (n<0) ? -n : n;
}

int factorial(int n){
//    base case
    if (n == 1){
        return 1;
    }
    else{
        //    recursice step
        return n*factorial(n-1);
    }

}

int factorial_tail(int n, int accumulator){
//    base case
    if (n==1){
        return accumulator;
    }
    return factorial_tail(n-1, n*accumulator);

}

int factorial_iter(int n){
    int start_n = 1;
    int accumulator = 1;
    while (start_n <= n){
        accumulator = accumulator * start_n;
        start_n ++;
    }
    return accumulator;
}
