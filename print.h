#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <array>

using namespace std;

template<typename T>
class print {
private:
    vector<T> v;
    set<T> s;
    multiset<T> ms;
    unordered_set<T> us;
    unordered_map<T, T> um;
    map<T, T> m;
    queue<T> q;
    priority_queue<T> pq;
    deque<T> dq;
    stack<T> st;
    multimap<T, T> mm;
    list<T> l;
    priority_queue<T, vector<T>, greater<T>> pq_min;
    unordered_multimap<T, T> umm;
    // array<T, 100> arr; // Fixed size 100 for array

public:
    void p_vector() {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_set() {
        for (auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_multiset() {
        for (auto i : ms) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_unordered_set() {
        for (auto i : us) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_unordered_map() {
        for (auto i : um) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    void p_map() {
        for (auto i : m) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    void p_queue() {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    void p_priority_queue() {
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
    void p_deque() {
        for (auto i : dq) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_stack() {
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    void p_multimap() {
        for (auto i : mm) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    void p_list() {
        for (auto i : l) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_priority_queue_min() {
        while (!pq_min.empty()) {
            cout << pq_min.top() << " ";
            pq_min.pop();
        }
        cout << endl;
    }
  
    void p_unordered_multimap() {
        for (auto i : umm) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    // void array_print() {
    //     for (auto i : arr) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    print(vector<T>& v) {
        this->v = v;
        p_vector();
    }
    print(set<T>& s) {
        this->s = s;
        p_set();
    }
    print(multiset<T>& ms) {
        this->ms = ms;
        p_multiset();
    }
    print(unordered_set<T>& us) {
        this->us = us;
        p_unordered_set();
    }
    print(unordered_map<T, T>& um) {
        this->um = um;
        p_unordered_map();
    }
    print(map<T, T>& m) {
        this->m = m;
        p_map();
    }
    print(queue<T>& q) {
        this->q = q;
        p_queue();
    }
    print(priority_queue<T>& pq) {
        this->pq = pq;
        p_priority_queue();
    }
    print(deque<T>& dq) {
        this->dq = dq;
        p_deque();
    }
    print(stack<T>& st) {
        this->st = st;
        p_stack();
    }
    print(multimap<T, T>& mm) {
        this->mm = mm;
        p_multimap();
    }
    print(list<T>& l) {
        this->l = l;
        p_list();
    }
    print(priority_queue<T, vector<T>, greater<T>>& pq_min) {
        this->pq_min = pq_min;
        p_priority_queue_min();
    }
    
    print(unordered_multimap<T, T>& umm) {
        this->umm = umm;
        p_unordered_multimap();
    }
    // print(array<T, 100>& arr) {
    //     this->arr = arr;
    //     array_print();
    // }

    // Constructor for C-style arrays: converts to vector for printing
    template<size_t N>
    print(const T (&arr)[N]) {
        v = vector<T>(arr, arr + N);
        p_vector();
    }
};