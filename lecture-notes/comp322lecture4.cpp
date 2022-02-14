//
//  comp322lecture4.cpp
//  coursera-c++
//
//  Created by Wendy Wu on 2022-02-10.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int getProduct(int x, int y);
int getProduct_2(int& x, int& y);
int getProduct_3(int* x, int* y);

//int main(){
////    int a =7,b = 9;
////    int *ptr1;
////    int *ptr2 = &b;
////    ptr1 = &a;
////    
////    *ptr1  = 15;
////    *ptr2 = *ptr1;
////    
////    cout << a << "\n";
////    cout << b << "\n";
////    int value = 100;
////    int* pValue = &value;
////    cout << "Value is equal to: " << *pValue << endl;
////    cout << "Address of value = "<<pValue<<endl;
//    
//    int value = 100;
//    int* pValue = &value;
//    cout << "Value is equal to: " << *pValue <<endl;
//    cout << "Address of Value = "<<pValue <<endl;
//    cout << ++*pValue << endl;
//    cout << *++pValue << endl;
//    cout << ++pValue << endl;
//    
//    int x;
//    int& y = x;
//    
//    int a = 100;
//    int& b = a;
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    b = 12;
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    
//    cout << "------------------------" << endl;
//    
//    int c = 4;
//    int d = 5;
//    int product = getProduct(c,d);
//    cout <<product<<endl;
//    
//    int e = 4;
//    int f = 5;
//    int product2 = getProduct_2(e,f);
//    cout << product2 <<endl;
//    
//    int g = 4;
//    int h = 5;
//    int product3 = getProduct_3(&g,&h);
//    cout << product3 <<endl;
//    
//    int *p = NULL;
//    int i=7; i++;
//    for (int j=0;j<=2;j++){
//        i = j;
//    }
//    p = &i;
//    if (p != NULL){
//        (*p) *= (*p);
//    }
//    if (p != NULL){
//        cout << (*p)++ << endl;
//        cout << i << endl;
////        cout << (*p) << endl;
//    } else {
//        cout << "pointer is NULL" << endl;
//    }
//    
//    
//    return 0;
//}

int getProduct(int x, int y){
    return x * y;
}

int getProduct_2(int& x, int& y){
    return x*y;
}

int getProduct_3(int* x, int* y){
    return (*x)*(*y);
}
