#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main() {
    stack<int> s; //acts like a stack of plates. cannot do anything from the bottom
    stack<int> s1; 

    // Push elements onto the stack
    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }

    cout << "Stack elements: ";
    printStack(s);

    // Pop an element from the stack
    s.pop();
    cout << "After popping an element: ";
    printStack(s);

    // Check if the stack is empty
    if (s.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    cout<<"Top element: " << s.top() << endl;

    //swap function swaps the entire stacks. 
    for (int i = 6; i <= 10; i++) {
        s1.push(i);
    }
    cout << "Stack 1 elements: ";
    printStack(s1);
    cout << "Stack 2 elements: ";
    printStack(s);
    s.swap(s1);
    cout << "After swapping stacks: " << endl;
    cout << "Stack 1 elements: ";
    printStack(s1);
    cout << "Stack 2 elements: ";
    printStack(s);

    return 0;
}