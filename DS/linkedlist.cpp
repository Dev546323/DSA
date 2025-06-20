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

void insert(int val, int pos){
    Node* newnode = new Node(val);
    if(pos == 0){
        push_front(val); 
        return;
    }
    Node* current = head;
    while(current != nullptr && pos > 1){
        current = current->next;
        pos--;
    }
    if(current==nullptr){
        cout<< "Please enter a valid position." << endl;
        return;
    }
    else if(current == tail){
        push_back(val); // If the position is at the end, we can use push_back.
        return;
    }
    else {
       newnode->next = current->next; // The new node's next will point to the current node's next.
       current->next = newnode; // The current node's next will now point to the new node.
       
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

void pop_back(){
     if (head == nullptr) {
        cout << "List is empty, nothing to pop." << endl;
        return;
    }
    if (head == tail) { // If there's only one node
        delete head;
        head = tail = nullptr; 
        return;
    }
    Node* current = head;
    while(current->next != tail) { // Traverse to the second last node
        current = current->next;
    }
    delete tail; // Delete the last node
    tail = current; // Update tail to the second last node
    tail->next = nullptr; // Set the next of the new tail to nullptr
}

void print(){
    Node* current = head;
    while (current != nullptr){
        cout << current->data << " ";
        current = current->next; 
    }
    cout<<endl;
}

void index(int val){
    Node* current = head;
    int index =0; 
    while(current != nullptr){
        if(current->data == val){
            cout << "Value " << val << " found at index: " << index << endl;
            return;
        }
        current = current->next; // Move to the next node.
        index++;
    }
    cout << "Value " << val << " not found in the list." << endl;
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