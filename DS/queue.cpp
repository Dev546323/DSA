#include<iostream>
#include<queue>
#include<type_traits>

using namespace std;

//printable queue class
template<typename T>
class PrintableQueue {
    enum class Type { Queue, PriorityQueueMax, PriorityQueueMin };
    Type type;
    queue<T> q;
    priority_queue<T> pq_max;
    priority_queue<T, vector<T>, greater<T>> pq_min;

public:
    // Construct from std::queue
    PrintableQueue(const queue<T>& q_) : type(Type::Queue), q(q_) {}

    // Construct from std::priority_queue (max heap)
    PrintableQueue(const priority_queue<T>& pq_) : type(Type::PriorityQueueMax), pq_max(pq_) {}

    // Construct from std::priority_queue (min heap)
    PrintableQueue(const priority_queue<T, vector<T>, greater<T>>& pq_) : type(Type::PriorityQueueMin), pq_min(pq_) {}

    void print() {
        switch (type) {
            case Type::Queue: {
                auto copy = q; // Create a copy of the because of lack of iterator with the queue type. 
                while (!copy.empty()) { 
                    cout << copy.front() << " ";
                    copy.pop(); //pop is required to remove the element from the queue it acts like i--;
                }
                break;
            }
            case Type::PriorityQueueMax: {
                auto copy = pq_max;
                while (!copy.empty()) {
                    cout << copy.top() << " ";
                    copy.pop();
                }
                break;
            }
            case Type::PriorityQueueMin: {
                auto copy = pq_min;
                while (!copy.empty()) {
                    cout << copy.top() << " ";
                    copy.pop();
                }
                break;
            }
        }
        cout << endl;
    }
};

// Print each element and its memory address in a std::queue
template<typename T>
void print_queue_with_addresses(const queue<T>& q) {
    queue<T> copy = q;
    while (!copy.empty()) {
        const T& elem = copy.front();
        cout << elem << " @ " << static_cast<const void*>(&elem) << "\n";
        copy.pop();
    }
}

int main() {
    queue<int> q;

    // Push elements onto the queue
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    cout << "Queue elements: ";
    PrintableQueue<int>(q).print();

    cout << "Queue elements with addresses:\n";
    print_queue_with_addresses(q);

    // Pop an element from the queue
    q.pop();
    cout << "After popping an element: ";
    PrintableQueue<int>(q).print();

    // Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq1;

    // Push elements onto the priority queues
    for (int i = 1; i <= 5; i++) {
        pq.push(i);
        pq1.push(i);
    }
      pq.push(10);
      pq1.push(10);
     
    cout << "Priority Queue (max heap) elements: ";
    PrintableQueue<int>(pq).print();
    cout << "Priority Queue 1(min heap) elements: ";
    PrintableQueue<int>(pq1).print();
   
}