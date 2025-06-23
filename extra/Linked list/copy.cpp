#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include "/home/yestodrugs/Desktop/DSA/list.h"

using namespace std;

template<typename T>
void copylist(Node<T>* head){
    unordered_map<Node<T>*, Node<T>*> nodeMap; 
    if(!head) cout<<"empty list\n";
    Node<T>* current = head; //creating a copy of the head node, to not lose the head poitner while traversing the list.
    Node<T>* nhead = new Node<T>(current->data); //creating a headnode for the new list as to not lose the new head
    Node<T>* copy = nhead; //creating first node of the new list with the new head. 
        nodeMap[current] = copy; 

current = current->next; //first node already copied, so moving to the next node.
    while(current){
        copy->next = new Node<T>(current->data); //initializing the copy->next with the new node's address. while creating a node with current data. 
       nodeMap[current] = copy->next; 
        current = current->next; 
        copy = copy->next;

    }
}

int main() {

    return 0;
}