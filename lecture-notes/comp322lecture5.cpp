//
//  comp322lecture5.cpp
//  coursera-c++
//
//  Created by Wendy Wu on 2022-02-11.
//

#include <stdio.h>
#include <iostream>

using namespace std;
int* getIntArray(int size);


int* getIntArray(int size){
    int* ptr = new int[size];
//    cout << ptr <<endl;
    return ptr;
}

struct Element {
    int data;
    Element* next;
};

void appendElement(Element** list, Element** tail, int data){
    Element* e = new Element;
    e->data = data;
    e->next = NULL;
    
//    if list is empty
    if (!(*list)){
        *list = e;
        *tail = e;
    } else {
        (*tail)->next = e;
        *tail = e;
    }
}

void printList(Element* node){
    while(node){
        cout << node->data << " ";
        node = node->next;
    }
}

void deleteList(Element** list){
    Element* next;
    while(*list){
        next = (*list)->next;
        delete* list;
        *list = next;
    }
}
//int main(){
//    Element* list = NULL;
//    Element* tail = NULL;
//    
//    appendElement(&list, &tail, 5);
//    appendElement(&list, &tail, 10);
//    appendElement(&list, &tail, 15);
//    
//    printList(list);
//    
//    deleteList(&list);
//    
//    return 0;
//    
////    int* x = NULL;
////    int a = 12;
////    if (a<22){
////        int y = 13;
////        x = &y;
////    }
////    cout << *x;
//    
////    int* a = new int;
////    *a = 5;
////    cout << *a << endl;
////    delete a;
////
////    int* x = getIntArray(5);
//////    for (int i=0;i<5;i++){
//////        *(x+i) = i;
//////    }
////    for (int i=0;i<5;i++){
////        x[i] = i;
////    }
////    for (int i=0;i<5;i++){
////        cout << x[i] <<endl;
////    }
//////    for(int i=0;i<5;i++){
//////        cout << *(x+i) << endl;
//////    }
//////    cout << x <<endl;
////    delete[] x;
////
////    int c = 5;
////    int* v = &c;
////    cout << v << endl;
////
////
////    int d[3] = {1,2,3};
////    int* pt;
////    pt = d;
////    cout << d << endl;
////    cout << pt[1] << endl;
//////    cout << &d[1] << endl;
////    return 0;
//}
