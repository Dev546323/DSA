#pragma once
#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<list>

using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head; //pointer pointing to data of the type T
    Node<T>* tail;
public:
 LinkedList() {
        head = tail = nullptr; //initializing head and tail to nullptr
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
    Node* newnode = new Node(val); 
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
    Node* temp = head; 
    head = head->next; 
    delete temp;
}
    void print() { 
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; 
        }
    }

};

