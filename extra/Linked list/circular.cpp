#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include "/home/yestodrugs/Desktop/DSA/list.h"

using namespace std;
template<typename T>
int circular(linkedList<T> &ll) { //checking for circular linked list
    if (ll.head == nullptr) {
        return 0; // Return default value for type T if the list is empty
    }
    Node<T>* slow = ll.head;
    Node<T>* fast = ll.head;
    bool check = false;
        while( fast and fast->next){ //checking if loop exists within the list
            slow= slow->next;
            fast = fast->next->next;
            if(fast==slow){ //loop exists
                check = true;
                break;
            } 
        }
        if(!check) return 0; // post condition for no loop

        slow = ll.head;
        Node<T>* temp = fast;
        while(slow!=fast){ //FINDING starting point of the loop 
            slow = slow->next;
            temp = fast;
            fast = fast ->next; 
        }
        temp->next = nullptr; //breaking the loop
        return slow->data; 
}

int main() {
    // 1. Empty list
linkedList<int> ll1;
circular(ll1);
cout << "1. " << circular(ll1) << " (Expected: 0)\n";

// 2. Single node, no loop
linkedList<int> ll2;
ll2.push_back(1);
circular(ll2);
cout << "2. " << circular(ll2) << " (Expected: 0)\n";

// 3. Single node, self loop
linkedList<int> ll3;
ll3.push_back(1);
ll3.head->next = ll3.head;
cout << "3. " << circular(ll3) << " (Expected: 1)\n";
cout << "   " << circular(ll3) << " (Expected: 0)\n"; // Run again to confirm loop removed

// 4. Two nodes, no loop
linkedList<int> ll4;
ll4.push_back(1); ll4.push_back(2);
cout << "4. " << circular(ll4) << " (Expected: 0)\n";

// 5. Two nodes, last node links to head
linkedList<int> ll5;
ll5.push_back(1); ll5.push_back(2);
ll5.head->next->next = ll5.head;
cout << "5. " << circular(ll5) << " (Expected: 1)\n";
cout << "   " << circular(ll5) << " (Expected: 0)\n";

// 6. Medium list, loop from tail to mid
linkedList<int> ll6;
for(int i = 1; i <= 10; i++) ll6.push_back(i);
Node<int>* temp6 = ll6.head;
Node<int>* loop6 = nullptr;
int count6 = 1;
while(temp6->next) {
    if(count6 == 5) loop6 = temp6;
    temp6 = temp6->next;
    count6++;
}
temp6->next = loop6;
cout << "6. " << circular(ll6) << " (Expected: 1)\n";
cout << "   " << circular(ll6) << " (Expected: 0)\n";

// 7. Full loop (tail to head)
linkedList<int> ll7;
for(int i = 1; i <= 15; i++) ll7.push_back(i);
Node<int>* tail7 = ll7.head;
while(tail7->next) tail7 = tail7->next;
tail7->next = ll7.head;
cout << "7. " << circular(ll7);
cout << "   " << circular(ll7) << " (Expected: 0)\n";

// 8. Loop near end (e.g., node 50 → 45)
linkedList<int> ll8;
for(int i = 1; i <= 60; i++) ll8.push_back(i);
Node<int>* temp8 = ll8.head;
Node<int>* loop8 = nullptr;
int count8 = 1;
while(temp8->next) {
    if(count8 == 45) loop8 = temp8;
    temp8 = temp8->next;
    count8++;
}
temp8->next = loop8;
cout << "8. " << circular(ll8) << " (Expected: 1)\n";
cout << "   " << circular(ll8) << " (Expected: 0)\n";

// 9. Large list, no loop
linkedList<int> ll9;
for(int i = 1; i <= 1000; i++) ll9.push_back(i);
cout << "9. " << circular(ll9) << " (Expected: 0)\n";

// 10. Stress test: 100000 nodes, loop at node 50000
linkedList<int> ll10;
for(int i = 1; i <= 100000; i++) ll10.push_back(i);
Node<int>* temp10 = ll10.head;
Node<int>* loop10 = nullptr;
int count10 = 1;
while(temp10->next) {
    if(count10 == 50000) loop10 = temp10;
    temp10 = temp10->next;
    count10++;
}
temp10->next = loop10;
cout << "10. " << circular(ll10) << " (Expected: 1)\n";
cout << "    " << circular(ll10) << " (Expected: 0)\n";



}