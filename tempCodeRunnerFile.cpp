#include<iostream>
#include "/home/yestodrugs/Desktop/DSA/list.h"
#include<string>

using namespace std; 

int main(){
     cout << "=== Integer DoubleLinkedList ===" << endl;
    doublylinkedlist<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_front(5);
    list1.insert(15, 2); // insert 15 at position 2
    list1.print();       // Expected: 5 10 15 20
    list1.pop_front();   // Removes 5
    list1.pop_back();    // Removes 20
    list1.print();       // Expected: 10 15
    cout << "Search for 15: ";
     list1.search(15)  ;
    cout << "Search for 5: ";
     list1.search(5)  ;

    cout << "\n=== Char DoubleLinkedList ===" << endl;
    doublylinkedlist<char> list2;
    list2.push_back('a');
    list2.push_back('c');
    list2.insert('b', 1); // insert 'b' between a and c
    list2.print();        // Expected: a b c
    list2.pop_front();    // Removes a
    list2.pop_back();     // Removes c
    list2.print();        // Expected: b
    cout << "Search for b: " ;
    list2.search('b')  ;
    cout << "Search for a: ";
     list2.search('a')  ;

    cout << "\n=== String DoubleLinkedList ===" << endl;
    doublylinkedlist<string> list3;
    list3.push_back("hello");
    list3.push_front("world");
    list3.insert("dear", 1); // insert "dear" between world and hello
    list3.print();           // Expected: world dear hello
    list3.pop_back();        // Removes hello
    list3.print();           // Expected: world dear
    cout << "Search for dear: ";
     list3.search("dear") ;
    cout << "Search for hello: ";
     list3.search("hello") ;
}