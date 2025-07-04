#pragma once
#include <iostream>
#include<vector>
#include<list>

using namespace std;

template<typename T>
struct Node{

    T data;
    Node* next;
    Node* prev; 

    Node(T val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

template<typename T>
struct linkedList {
    Node<T>* head; //pointer pointing to data of the type T
    Node<T>* tail;

 linkedList() {
        head = tail = nullptr; //initializing head and tail to nullptr
    }
    linkedList(Node<T>* node) {
    head = node;
}


void insert(T val, int pos){
    Node<T>* newnode = new Node(val);
    if(pos == 0){
        push_front(val); 
        return;
    }
    Node<T>* current = head;
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

    void push_front(T val) { 
        Node<T>* newnode = new Node<T>(val); 
        if (head == nullptr) {
            head = tail = newnode; 
        } else {
            newnode->next = head;  
            head = newnode; 
        }
    }
    void push_back(T val){
    Node<T>* newnode = new Node(val); 
    if (head == nullptr) {
        head = tail = newnode; 
    } else {
        tail->next = newnode; //The current tail points to the new node. 
        tail = newnode; // the newnode becomes the new tail.
    }
}

void pop_front(){ 
    if (head == nullptr) {
        cout << "List is empty, nothing to pop." << endl;
        return;
    }
    Node<T>* temp = head; 
    head = head->next; 
    delete temp;
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
    Node<T>* current = head;
    while(current->next != tail) { // Traverse to the second last node
        current = current->next;
    }
    delete tail; // Delete the last node
    tail = current; // Update tail to the second last node
    tail->next = nullptr; // Set the next of the new tail to nullptr
}

    void print() { 
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; 
        }
        cout<<endl;
    }


    void search(T val){
    if(head == tail or head == nullptr){
        cout<<"Please die\n";
        return;
    }

    Node<T>* current = head;
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

template<typename T>
struct doublylinkedlist {
    Node<T>* head;
    Node<T>* tail;

    doublylinkedlist() {
        head = tail = nullptr;
    }
    doublylinkedlist(Node<T>* node) {
        head = node;
    }

    void insert(T val, int pos){
    Node<T>* newnode = new Node(val);
    if(pos == 0){
        push_front(val); 
        return;
    }
    Node<T>* current = head;
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
         newnode->prev = current;
       newnode->next = current->next; // The new node's next will point to the current node's next.
       current->next = newnode; // The current node's next will now point to the new node.
         if(newnode->next != nullptr) {
              newnode->next->prev = newnode; 
         }
     }
    }   
        void push_front(T val) { 
        Node<T>* newnode = new Node<T>(val); 
        if (head == nullptr) {
            head = tail = newnode; 
        } else {
            newnode->next = head;  
             head->prev = newnode; 
             newnode->prev = nullptr; // The new node's prev should be nullptr since it's the new head.
            head = newnode; 
        }
    }
    void push_back(T val){
    Node<T>* newnode = new Node(val); 
    if (head == nullptr) {
        head = tail = newnode; 
     } else {
        tail->next = newnode; //The current tail points to the new node. 
            newnode->prev = tail; // The new node's prev should point to the current tail.
            newnode->next = nullptr; // The new node's next should be nullptr since it's the new tail.
        tail = newnode; // the newnode becomes the new tail.

         }
    }

    void pop_front(){ 
    if (head == nullptr) {
        cout << "List is empty, nothing to pop." << endl;
        return;
    }
    Node<T>* temp = head; 
    head = head->next; 
    if (head != nullptr) { // If the list is not empty after popping
        head->prev = nullptr; // Set the new head's prev to nullptr
    } else {
        tail = nullptr; // If the list is now empty, set tail to nullptr
    }
    delete temp; // Delete the old head
    
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
    Node<T>* temp = tail;
   tail = tail->prev; 
    delete temp; 
    tail->next = nullptr; 
}


    void print() { 
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; 
        }
        cout<<endl;
    }


    void search(T val){
    if(head == tail or head == nullptr){
        cout<<"Please die\n";
        return;
    }

    Node<T>* current = head;
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


