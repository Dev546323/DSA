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

void push_back(int val){
    Node* newnode = new Node(val); 
    if (head == nullptr) {
        head = tail = newnode; 
    } else {
        tail->next = newnode; //The current tail points to the new node. 
        tail = newnode; // the newnode becomes the new tail.
    }
}

void pop_front(){ //removes the first element of the linked list.
    if (head == nullptr) {
        cout << "List is empty, nothing to pop." << endl;
        return;
    }
    Node* temp = head; //temp will point to the head node.
    head = head->next; //head will now point to the next node.
    delete temp; //deleting the old head node.
}

void print(){
    Node* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next; 
    }
    cout<<endl;
}
};

int main() {
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
        ll.print(); 

    ll.pop_front(); 
    ll.push_back(0);
        ll.print(); 



  
    return 0;
}