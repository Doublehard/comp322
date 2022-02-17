//
// Created by Wendy Wu on 2022-02-15.
//
#include <iostream>

using namespace std;

class Node{
public:
    Node(): data(0), next(NULL), prev(NULL){}
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
    DLLstrcture():head(NULL),tail(NULL),size(0){}
    ~DLLstrcture(){
        int counter = 0;
        while(head!=NULL){
            Node* temp = head->next;
            delete head;
            head = temp;
            counter++;
        }
        cout << "destructor called for deleting " << counter << " nodes." << endl;
    }
    DLLstrcture(int array[], int size){
        cout << "constructor for Double Linked List is called" << endl;
        for(int i=0;i<size;i++){
            addNodeToTail(array[i]);
        }
    }
    void insertAfter(int valueToInsertAfter, int valueToBeInsert);
    void insertBefore(int valueToInsertBefore, int valueToBeInsert);
    void addNodeToHead(int n);
    void addNodeToTail(int n);
    void printDLL();
    void Delete(int value);
    void Sort();
//    bool IsEmpty();
private:
    Node* head;
    Node* tail;
    int size;
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
}

void DLLstrcture::addNodeToTail(int n){
    Node* node = new Node();
    node->data = n;
    if(tail){
        node->prev = tail;
        tail->next = node;
        tail = node;
    }else{
        head = tail = node;
    }
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


//bool DLLstrcture::IsEmpty() {
//    if(head)
//}

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
    myLL.Sort();
    myLL.printDLL();
    return 0;
}

