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

    void print() { 
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; 
        }
    }

};

