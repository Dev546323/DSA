#include<iostream>
#include<queue>

using namespace std;

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main() {
    queue<int> q; //practically opposite of stack. acts like a queue of people. can do anything from the front
    queue<int> q1; 

    // Push elements onto the queue
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    cout << "Queue elements: ";
    printQueue(q);

    // Pop an element from the queue
    q.pop();
    cout << "After popping an element: ";
    printQueue(q);

    // Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    cout<<"Front element: " << q.front() << endl;
    cout<<"Back element: " << q.back() << endl;

}