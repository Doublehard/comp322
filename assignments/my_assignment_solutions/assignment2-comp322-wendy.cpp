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

class DLLstrcture{
public:
    DLLstrcture():head(nullptr),tail(nullptr),size(0),max(0),min(0){}
    ~DLLstrcture(){
        int counter = 0;
        while(head!= nullptr){
            Node* temp = head->next;
            delete head;
            head = temp;
            counter++;
        }
        cout << "destructor called for deleting " << counter << " nodes." << endl;
    }
    DLLstrcture(int array[], int size){
        cout << "constructor for Double Linked List is called" << endl;
        max = min = array[0];
        head = tail = NULL;
        for(int i=0;i<size;i++){
            updateMaxMin(array[i]);
            addNodeToTail(array[i]);
        }
        this->size = size;
    }
    void insertAfter(int valueToInsertAfter, int valueToBeInsert);
    void insertBefore(int valueToInsertBefore, int valueToBeInsert);
    void addNodeToHead(int n);
    void addNodeToTail(int n);
    void printDLL();
    void Delete(int value);
    void Sort();
    bool IsEmpty();
    int GetHead();
    int GetTail();
    int GetSize();
    int GetMax();
    int GetMin();
    DLLstrcture(DLLstrcture& list);

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
void DLLstrcture::insertAfter(int valueToInsertAfter, int valueToBeInsert) {
    Node* temp = head;
    while(temp->data!=valueToInsertAfter && temp!=tail){
        temp = temp->next;
    }
    if(temp->data == valueToInsertAfter){
        Node* new_node = new Node(valueToBeInsert,temp->next,temp);
//        cout << "tail = " << tail->data << endl;
    } else{
        // not found, insert at the end
//        cout << "add to tail~~" << endl;
        addNodeToTail(valueToBeInsert);
    }
    size++;
    updateMaxMin(valueToBeInsert);
}

void DLLstrcture::insertBefore(int valueToInsertBefore, int valueToBeInsert) {
    Node* temp = tail;
//    cout << "temp data = " << temp->data << endl;
    while(temp->data!=valueToInsertBefore && temp!=head){
        temp = temp->prev;
    }
    if(temp->data==valueToInsertBefore){
        insertAfter(temp->prev->data,valueToBeInsert);
    }else{
//        insert at head
//        cout << "add to head~~" << endl;
        addNodeToHead(valueToBeInsert);
    }
    size++;
    updateMaxMin(valueToBeInsert);
}

void DLLstrcture::addNodeToTail(int n){
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
void DLLstrcture::addNodeToHead(int n) {
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

void DLLstrcture::printDLL() {
    Node* temp = head;
//    cout << "printing linked list:" << endl;
    while (temp!=NULL){
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << endl;
}

void DLLstrcture::Delete(int value) {
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

void DLLstrcture::Sort() {
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


bool DLLstrcture::IsEmpty() {
    if(size==0){
        cout << "LL is empty" << endl;
        return true;
    }
    cout << "LL is not empty" << endl;
    return false;
}

int DLLstrcture::GetHead() {
    if(size!=0){
        return head->data;
    }
    return 0;
}

int DLLstrcture::GetTail() {
    if(size!=0){
        return tail->data;
    }
    return 0;
}

int DLLstrcture::GetSize() {
    return size;
}

void DLLstrcture::updateMaxMin(int n) {
    if(n>max){
        max = n;
    }
    if(n<min){
        min = n;
    }
}

int DLLstrcture::GetMax() {
    return max;
}

int DLLstrcture::GetMin() {
    return min;
}

void DLLstrcture::reFindMax() {
    max = min;
    Node* ptr = head;
    while(ptr!=NULL){
        if(ptr->data>max){
            max = ptr->data;
        }
        ptr = ptr->next;
    }
}

void DLLstrcture::reFindMin() {
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
DLLstrcture::DLLstrcture(DLLstrcture &list) {
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

    int array[] = {6,5,3,1,9,10,100,0,-1};
    DLLstrcture myLL(array,9);
//    myLL.printDLL();
//    myLL.insertAfter(3,0);
//    myLL.printDLL();
//    myLL.insertAfter(6,100);
//    myLL.printDLL();
//    myLL.insertAfter(6,6);
//    myLL.printDLL();
//    myLL.insertBefore(100,6);
//    myLL.printDLL();
//    myLL.insertBefore(8,-1);
    myLL.printDLL();
//    myLL.Delete(0);
//    myLL.printDLL();

//    myLL.Sort();
//    myLL.printDLL();

//    cout << "Head = "<<myLL.GetHead()<<"; Tail = "<<myLL.GetTail()<<endl;
//    cout << "LL has size = "<<myLL.GetSize()<<endl;
//    cout << "Max value = "<<myLL.GetMax()<<"; Min value = "<<myLL.GetMin()<<endl;


    cout << "Default copy constructor only does shallow copy."
         << "Since the object DLLstructure has pointers, I need to write a user-defined copy constructor."
         << endl;
    DLLstrcture myLL_copy(myLL); // copy constructor called
//
//    myLL.Sort();
    myLL.printDLL();
//
    myLL_copy.Sort();
    myLL_copy.printDLL();

    myLL.printDLL();

    return 0;
}

