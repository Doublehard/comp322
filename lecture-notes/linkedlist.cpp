////
//// Created by Wendy Wu on 2022-02-13.
////
//#include <iostream>
//
//using namespace std;
//
//struct Node{
//    int data;
//    Node* next;
//};
//
//void addElement(int value, Node** head, Node** tail){
//    Node* n = new Node;
//    n->data = value;
//    n->next = NULL;
////    check head
//    if (!(*head)){
//        *head = n;
//        *tail = n;
//    }else{
//        (*tail)->next = n;
//        (*tail) = n;
//    }
//}
//
//void deleteLinkedList(Node** head){
//    Node* n;
//    while (!(*head)){
//        n = (*head)->next;
//        delete (*head);
//        *head = n;
//    }
//}
//
//void printLinkedList(Node* head){
//    while (head){
//        cout << (head->data) << endl;
//        head = head->next;
//    }
//}
//
//int main(){
//    Node* head = NULL;
//    Node* tail = NULL;
//    addElement(5,&head,&tail);
//    addElement(10,&head,&tail);
//    addElement(15,&head,&tail);
//    printLinkedList(head);
//    deleteLinkedList(&head);
//    return 0;
//}
