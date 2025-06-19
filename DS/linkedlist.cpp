#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<list>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList {

    Node* head;
    Node* tail;
 
public:
LinkedList(){
    head=tail=nullptr;
}
void push_front(int val){ //makes  a node at the front of the linked list.
    Node* newnode = new Node(val); // newnode is a pointer to a new node that is created with the value val.
    //Declare a variable named newnode that will store a pointer to a Node object.
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        newnode->next = head; // new node ka next wala data type. will now hold the head value. 
        head = newnode; // head will now point to the new node.
}
}
void print(){
    Node* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next; 
    }
}
};

int main() {
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.print(); 
    return 0;
}