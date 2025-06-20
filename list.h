#pragma once
#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<list>

using namespace std;

template<typename T>
struct Node{

    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

template<typename T>
struct linkedList {
    Node<T>* head; //pointer pointing to data of the type T
    Node<T>* tail;

 linkedList() {
        head = tail = nullptr; //initializing head and tail to nullptr
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
    }
    int search(T val){
    if(head == tail or head == nullptr){
        cout<<"Please die\n";
    }

    Node<T>* current = head;
    int index =0; 
    while(current != nullptr){
        if(current->data == val){
            // cout << "Value " << val << " found at index: " << index << endl;
            return index;
        }
        current = current->next; // Move to the next node.
        index++;
    }
    cout << "Value " << val << " not found in the list." << endl;
}

};

