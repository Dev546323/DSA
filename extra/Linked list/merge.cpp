#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include "/home/yestodrugs/Desktop/DSA/list.h"


using namespace std;

template<typename T>
Node<T>* merge(Node<T>* head1, Node<T>* head2){
    if(head1 == nullptr) return head2; // If first list is empty, return second list
    if(head2 == nullptr) return head1; // If second list is empty, return first list

    if(head1->data <= head2->data){
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

int main() {

    // 1. Both lists empty
linkedList<int> l1_1, l2_1;
linkedList<int> res1 = merge(l1_1.head, l2_1.head);
res1.print(); // Expected:

// 2. One empty, one non-empty
linkedList<int> l1_2, l2_2;
l2_2.push_back(1); l2_2.push_back(3); l2_2.push_back(5);
linkedList<int> res2 = merge(l1_2.head, l2_2.head);
res2.print(); // Expected: 1 3 5

// 3. No overlapping values
linkedList<int> l1_3, l2_3;
l1_3.push_back(1); l1_3.push_back(2); l1_3.push_back(3);
l2_3.push_back(4); l2_3.push_back(5); l2_3.push_back(6);
linkedList<int> res3 = merge(l1_3.head, l2_3.head);
res3.print(); // Expected: 1 2 3 4 5 6

// 4. Alternating merge
linkedList<int> l1_4, l2_4;
l1_4.push_back(1); l1_4.push_back(4); l1_4.push_back(7);
l2_4.push_back(2); l2_4.push_back(5); l2_4.push_back(8);
linkedList<int> res4 = merge(l1_4.head, l2_4.head);
res4.print(); // Expected: 1 2 4 5 7 8

// 5. Lists with duplicate values
linkedList<int> l1_5, l2_5;
l1_5.push_back(1); l1_5.push_back(3); l1_5.push_back(5);
l2_5.push_back(1); l2_5.push_back(3); l2_5.push_back(5);
linkedList<int> res5 = merge(l1_5.head, l2_5.head);
res5.print(); // Expected: 1 1 3 3 5 5

// 6. One list is entirely smaller than the other
linkedList<int> l1_6, l2_6;
l1_6.push_back(1); l1_6.push_back(2); l1_6.push_back(3);
l2_6.push_back(10); l2_6.push_back(20); l2_6.push_back(30);
linkedList<int> res6 = merge(l1_6.head, l2_6.head);
res6.print(); // Expected: 1 2 3 10 20 30

// 7. One list has one element
linkedList<int> l1_7, l2_7;
l1_7.push_back(4);
l2_7.push_back(1); l2_7.push_back(2); l2_7.push_back(3);
linkedList<int> res7 = merge(l1_7.head, l2_7.head);
res7.print(); // Expected: 1 2 3 4

// 8. All elements same in both lists
linkedList<int> l1_8, l2_8;
for(int i = 0; i < 3; i++) {
    l1_8.push_back(7);
    l2_8.push_back(7);
}
linkedList<int> res8 = merge(l1_8.head, l2_8.head);
res8.print(); // Expected: 7 7 7 7 7 7

// 9. Lists of unequal lengths
linkedList<int> l1_9, l2_9;
l1_9.push_back(1); l1_9.push_back(4);
l2_9.push_back(2); l2_9.push_back(3); l2_9.push_back(5); l2_9.push_back(6);
linkedList<int> res9 = merge(l1_9.head, l2_9.head);
res9.print(); // Expected: 1 2 3 4 5 6

// 10. Stress test: 1000 elements each
linkedList<int> l1_10, l2_10;
for(int i = 0; i < 1000; i++) {
    l1_10.push_back(i * 2);     // Even numbers
    l2_10.push_back(i * 2 + 1); // Odd numbers
}
linkedList<int> res10 = merge(l1_10.head, l2_10.head);
res10.print(); // Expected: 0 1 2 3 ... 1999

    return 0;
}