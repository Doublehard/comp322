//
// Created by Wendy Wu on 2022-02-15.
//
#include <iostream>

using namespace std;

class Node{
public:
    Node(): data(0), next(nullptr), prev(nullptr){}
    ~Node(){}
    Node(int data, Node* next, Node* prev): data(data), next(next), prev(prev){
        if(next){
            next->prev = this;
        }
        if(prev){
            prev->next = this;
        }
    }
    int data;
    Node* next;
    Node* prev;
};

class DLLStructure{
public:
    DLLStructure(): head(nullptr), tail(nullptr), size(0), max(0), min(0){}
    ~DLLStructure(){
        int counter = 0;
        while(head!= nullptr){
            Node* temp = head->next;
            delete head;
            head = temp;
            counter++;
        }
        cout << "destructor called for deleting " << counter << " nodes." << endl;
    }
    DLLStructure(int array[], int size){
        cout << "constructor for Double Linked List is called" << endl;
        max = min = array[0];
        head = tail = NULL;
        for(int i=0;i<size;i++){
            updateMaxMin(array[i]);
            addNodeToTail(array[i]);
        }
        this->size = size;
    }
    void InsertAfter(int valueToInsertAfter, int valueToBeInsert);
    void InsertBefore(int valueToInsertBefore, int valueToBeInsert);
    void addNodeToHead(int n);
    void addNodeToTail(int n);
    void printDLL();
    void Delete(int value);
    void Sort();
    bool IsEmpty();
    int getHead();
    int getTail();
    int getSize();
    int getMax();
    int getMin();
    DLLStructure(DLLStructure& list);

private:
    void updateMaxMin(int n);
    void reFindMax();
    void reFindMin();
    Node* head;
    Node* tail;
    int size;
    int max;
    int min;
};
void DLLStructure::InsertAfter(int valueToInsertAfter, int valueToBeInsert) {
    Node* temp = head;
    while(temp->data!=valueToInsertAfter && temp!=tail){
        temp = temp->next;
    }
    if(temp->data == valueToInsertAfter){
        Node* new_node = new Node(valueToBeInsert,temp->next,temp);
        size++;
        //        cout << "tail = " << tail->data << endl;
    } else{
        // not found, insert at the end
//        cout << "add to tail~~" << endl;
        addNodeToTail(valueToBeInsert);
    }

    updateMaxMin(valueToBeInsert);
}

void DLLStructure::InsertBefore(int valueToInsertBefore, int valueToBeInsert) {
//    Node* temp = tail;
    Node* temp = head;
//    cout << "temp data = " << temp->data << endl;
//    while(temp->data!=valueToInsertBefore && temp!=head){
//        temp = temp->prev;
//    }

    while(temp->data!=valueToInsertBefore && temp!=tail){
        temp = temp->next;
    }

    if(temp->data==valueToInsertBefore){
        InsertAfter(temp->prev->data, valueToBeInsert);
    }else{
//        insert at head
//        cout << "add to head~~" << endl;
        addNodeToHead(valueToBeInsert);
    }
    updateMaxMin(valueToBeInsert);
}

void DLLStructure::addNodeToTail(int n){
    Node* node = new Node();
    node->data = n;
    if(tail!=NULL){
//        cout << tail->data<<endl;
        node->prev = tail;
        tail->next = node;
        tail = node;
    }else{
        head = tail = node;
    }
    size++;
    updateMaxMin(n);
}
void DLLStructure::addNodeToHead(int n) {
    Node* node = new Node();
    node->data = n;
    if(head){
        node->next = head;
        head->prev = node;
        head = node;
    }else{
        head = tail = node;
    }
    size++;
    updateMaxMin(n);
}

void DLLStructure::printDLL() {
    Node* temp = head;
//    cout << "printing linked list:" << endl;
    while (temp!=NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

void DLLStructure::Delete(int value) {
    Node* temp = head;
    while (temp->data!=value && temp!=tail){
        temp = temp->next;
    }
    if (temp->data == value){
        // remove this node
        Node* temp_prev = temp->prev;
        Node* temp_next = temp->next;
        temp_prev->next = temp_next;
        temp_next->prev = temp_prev;
        delete temp;
        // update max min
        if(max==value){
            reFindMax();
        }
        if(min==value){
            reFindMin();
        }
        size--;
    }
    // else do nothing

}

void DLLStructure::Sort() {
    // insertion sort O(n^2)
    Node* cur = head->next;
    while(cur!=NULL){
        Node* c = cur;
        while(c!=NULL&&c->prev!=NULL&&c->data<=c->prev->data){
            // swap
            int temp = c->data;
            c->data = c->prev->data;
            c->prev->data = temp;
            c = c->prev;
        }
        cur = cur->next;
    }

}


bool DLLStructure::IsEmpty() {
    if(size==0){
        cout << "LL is empty" << endl;
        return true;
    }
    cout << "LL is not empty" << endl;
    return false;
}

int DLLStructure::getHead() {
    if(size!=0){
        return head->data;
    }
    return 0;
}

int DLLStructure::getTail() {
    if(size!=0){
        return tail->data;
    }
    return 0;
}

int DLLStructure::getSize() {
    return size;
}

void DLLStructure::updateMaxMin(int n) {
    if(n>max){
        max = n;
    }
    if(n<min){
        min = n;
    }
}

int DLLStructure::getMax() {
    return max;
}

int DLLStructure::getMin() {
    return min;
}

void DLLStructure::reFindMax() {
    max = min;
    Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->data>max){
            max = ptr->data;
        }
        ptr = ptr->next;
    }
}

void DLLStructure::reFindMin() {
    min = max;
    Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->data < min){
            min = ptr->data;
        }
        ptr = ptr->next;
    }
}

// algo from:
// https://github.com/CyC2018/CS-Notes/blob/master/notes/35.%20%E5%A4%8D%E6%9D%82%E9%93%BE%E8%A1%A8%E7%9A%84%E5%A4%8D%E5%88%B6.md
DLLStructure::DLLStructure(DLLStructure &list) {
    // add clone node after each node
    Node* ptr = list.head;
    while(ptr!= nullptr){
        Node* clone =  new Node(ptr->data,ptr->next,ptr);
        ptr->next = clone;
        if(clone->next!= nullptr){
            clone->next->prev = clone;
        }
        if(ptr!=list.tail){
            ptr = ptr->next->next;
        } else{
            break;
        }

//        list.printDLL();
    }

    // seperate two list, copy attributes
    ptr = list.head;
    Node* ptr_clone = list.head->next;



    while (ptr!= nullptr){
        ptr->next = ptr->next->next;
        if(ptr_clone->next!= nullptr){
            ptr_clone->next=ptr_clone->next->next;
        } else {
            break;
        }
        ptr = ptr->next;
        ptr_clone = ptr_clone->next;
    }

    tail = ptr_clone;

    while(ptr_clone!= nullptr){
        ptr_clone->prev = ptr_clone->prev->prev;
        if(ptr!=list.head){
            ptr->prev = ptr->prev->prev;
        } else {
            break;
        }
        ptr_clone = ptr_clone->prev;
        ptr = ptr->prev;
    }

    head = ptr_clone;

    size = list.size;
    max = list.max;
    min = list.min;

}


int main(){

//    int array[] = {6,5,3,1,9,10,100,0,-1};
//    DLLStructure myLL(array,9);
////    myLL.printDLL();
////    myLL.InsertAfter(3,0);
////    myLL.printDLL();
////    myLL.InsertAfter(6,100);
////    myLL.printDLL();
////    myLL.InsertAfter(6,6);
////    myLL.printDLL();
////    myLL.InsertBefore(100,6);
////    myLL.printDLL();
////    myLL.InsertBefore(8,-1);
//    myLL.printDLL();
////    myLL.Delete(0);
////    myLL.printDLL();
//
////    myLL.Sort();
////    myLL.printDLL();
//
////    cout << "Head = "<<myLL.getHead()<<"; Tail = "<<myLL.getTail()<<endl;
////    cout << "LL has size = "<<myLL.getSize()<<endl;
////    cout << "Max value = "<<myLL.getMax()<<"; Min value = "<<myLL.getMin()<<endl;
//
//
//    cout << "Default copy constructor only does shallow copy."
//         << "Since the object DLLstructure has pointers, I need to write a user-defined copy constructor."
//         << endl;
//    DLLStructure myLL_copy(myLL); // copy constructor called
////
////    myLL.Sort();
//    myLL.printDLL();
////
//    myLL_copy.Sort();
//    myLL_copy.printDLL();
//
//    myLL.printDLL();
//
////

    // Q 1, 2, 3 should obviously be implemented successfully
// in order to run the following code
    int array[5] = {11, 2, 7, 22, 4};
    DLLStructure dll(array, 5); // note that 5 is the size of the array
    dll.printDLL(); // the output should be: 11, 2, 7, 22, 4
// Q 4
    dll.InsertAfter(7, 13); // To insert 13 after the first occurence of 7
    dll.printDLL(); // the output should be: 11, 2, 7, 13, 22, 4
    dll.InsertAfter(25, 7); // To insert 7 after the first occurence of 25
    dll.printDLL(); // the output should be: 11, 2, 7, 13, 22, 4, 7
// Q 5
    dll.InsertBefore(7, 26); // To insert 26 before the first occurence of 7
    dll.printDLL(); // the output should be: 11, 2, 26, 7, 13, 22, 4, 7
    dll.InsertBefore(19, 12); // To insert 12 before the first occurence of 19
    dll.printDLL(); // the output should be: 12, 11, 2, 26, 7, 13, 22, 4, 7
// Q 6
    dll.Delete(22);
    dll.printDLL(); // the output should be: 12, 11, 2, 26, 7, 13, 4, 7
// Q 7
    dll.Sort();
    dll.printDLL(); // the output should be: 2, 4, 7, 7, 11, 12, 13, 26
// Q 8
    if (dll.IsEmpty()){
        cout << "The list is empty" << endl;
    }
// Q 9
    cout << "Head element is: " << dll.getHead() << endl;
    cout << "Tail element is: " << dll.getTail() << endl;
// Q 10
    cout << "Number of elements in the list is: " << dll.getSize() <<
         endl;
// Q 11
    cout << "Max element is: " << dll.getMax() << endl;
    cout << "Min element is: " << dll.getMin() << endl;

// Q 11 theory question
// print to the screen the written answer for the theory question
    cout << "Default copy constructor only does shallow copy."
         << "Since the object DLLstructure has pointers, I need to write a user-defined copy constructor."
         << endl;
// Q 12 theory question
// print to the screen the written answer for the theory question
// Q 12
    DLLStructure dll2 (dll);
    dll2.printDLL(); // the output should be: 2, 4, 7, 7, 11, 12, 13, 26
    return 0;
}

