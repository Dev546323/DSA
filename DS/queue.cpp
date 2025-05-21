#include "/home/yestodrugs/Desktop/print.h"
#include <iostream>
#include <queue>
#include <type_traits>

using namespace std;

int main() {
    // Demonstrate std::queue
    queue<int> q;
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    cout << "Queue elements: ";
    print<int> p1(q);

    // Pop an element from the queue
    q.pop();
    cout << "After popping an element: ";
    print<int> p2(q);

    // Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Demonstrate std::priority_queue (max heap)
    priority_queue<int> pq;
    // Demonstrate std::priority_queue (min heap)
    priority_queue<int, vector<int>, greater<int>> pq1;

    for (int i = 1; i <= 5; i++) {
        pq.push(i);
        pq1.push(i);
    }
    pq.push(10);
    pq1.push(10);

    cout << "Priority Queue (max heap) elements: ";
    print<int> p3(pq);

    cout << "Priority Queue 1(min heap) elements: ";
    print<int> p4(pq1);

    return 0;
}