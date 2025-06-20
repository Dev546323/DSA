#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include "/home/yestodrugs/Desktop/DSA/list.h"

using namespace std;


template<typename T>
T middle(linkedList<T> &ll){
    if(ll.head == nullptr){
        return T();
    }
    Node<T>* slow = ll.head;
    Node<T>* fast = ll.head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow by one step
        fast = fast->next->next; // Move fast by two steps
    }
    return slow->data; // Return the data at the middle node

}


int main() {

    // 1. Empty list
linkedList<int> ll1;
cout << "1. " << middle(ll1) << " (Expected: 0)\n";

// 2. Single element
linkedList<int> ll2;
ll2.push_back(42);
cout << "2. " << middle(ll2) << " (Expected: 42)\n";

// 3. Two elements
linkedList<int> ll3;
ll3.push_back(1); ll3.push_back(2);
cout << "3. " << middle(ll3) << " (Expected: 2)\n";

// 4. Three elements
linkedList<int> ll4;
ll4.push_back(1); ll4.push_back(2); ll4.push_back(3);
cout << "4. " << middle(ll4) << " (Expected: 2)\n";

// 5. Even number of elements
linkedList<int> ll5;
for(int i = 1; i <= 6; i++) ll5.push_back(i);
cout << "5. " << middle(ll5) << " (Expected: 4)\n";

// 6. Odd number of elements
linkedList<int> ll6;
for(int i = 1; i <= 7; i++) ll6.push_back(i);
cout << "6. " << middle(ll6) << " (Expected: 4)\n";

// 7. List with duplicates
linkedList<int> ll7;
for(int i = 0; i < 5; i++) ll7.push_back(5);
cout << "7. " << middle(ll7) << " (Expected: 5)\n";

// 8. List of chars
linkedList<char> ll8;
for(char c : {'a', 'b', 'c', 'd', 'e'}) ll8.push_back(c);
cout << "8. " << middle(ll8) << " (Expected: c)\n";

// 9. List of strings
linkedList<string> ll9;
for(string s : {"one", "two", "three", "four"}) ll9.push_back(s);
cout << "9. " << middle(ll9) << " (Expected: three)\n";

// 10. Stress test: large list
linkedList<int> ll10;
for(int i = 1; i <= 100001; i++) ll10.push_back(i);
cout << "10. " << middle(ll10) << " (Expected: 50001)\n";

    return 0;
}