#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <array>
#include <map>
#include <unordered_map>

using namespace std;

template<typename T>
class print {
private:
    vector<T> v;
    set<T> s;
    multiset<T> ms;
    unordered_set<T> us;
    queue<T> q;
    priority_queue<T> pq;
    deque<T> dq;
    stack<T> st;
    list<T> l;
    priority_queue<T, vector<T>, greater<T>> pq_min;
    pair<T, T> p;
    vector<pair<T, T>> vp;
    string str;
   
public:
    void p_vector() {
        cout << endl;
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_set() {
        cout << endl;
        for (auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_multiset() {
        cout << endl;
        for (auto i : ms) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_unordered_set() {
        cout << endl;
        for (auto i : us) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_queue() {
        cout << endl;
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    void p_priority_queue() {
        cout << endl;
        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
    void p_deque() {
        cout << endl;
        for (auto i : dq) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_stack() {
        cout << endl;
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    void p_list() {
        cout << endl;
        for (auto i : l) {
            cout << i << " ";
        }
        cout << endl;
    }
    void p_priority_queue_min() {
        cout << endl;
        while (!pq_min.empty()) {
            cout << pq_min.top() << " ";
            pq_min.pop();
        }
        cout << endl;
    }
    void p_pair() {
        cout << endl;
        cout << p.first << " " << p.second << endl;
    }
    void p_vector_pair() {
        cout << endl;
        for (auto& i : vp) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
    void p_string() {
        cout << endl;
        cout << str << endl;
    }
 
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
    print(list<T>& l) {
        this->l = l;
        p_list();
    }
    print(priority_queue<T, vector<T>, greater<T>>& pq_min) {
        this->pq_min = pq_min;
        p_priority_queue_min();
    }

    template<size_t N>
    print(const T (&arr)[N]) {
        v = vector<T>(arr, arr + N);
        p_vector();
    }
    print(pair<T, T>& p) {
        this->p = p;
        p_pair();
    }
    print(vector<pair<T, T>>& vp) {
        this->vp = vp;
        p_vector_pair();
    }
    print(const string& str) {
        this->str = str;
        p_string();
    }

    print() = default;
};

// Specialization for std::map<K, V>
template<typename K, typename V>
class print<std::map<K, V>> {
public:
    print(std::map<K, V>& m) {
        cout << endl;
        for (auto& i : m) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
};

// Specialization for std::multimap<K, V>
template<typename K, typename V>
class print<std::multimap<K, V>> {
public:
    print(std::multimap<K, V>& mm) {
        cout << endl;
        for (auto& i : mm) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
};

// Specialization for std::unordered_map<K, V>
template<typename K, typename V>
class print<std::unordered_map<K, V>> {
public:
    print(std::unordered_map<K, V>& um) {
        cout << endl;
        for (auto& i : um) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
};

// Specialization for std::unordered_multimap<K, V>
template<typename K, typename V>
class print<std::unordered_multimap<K, V>> {
public:
    print(std::unordered_multimap<K, V>& umm) {
        cout << endl;
        for (auto& i : umm) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
};

template<typename K, typename V>
class print<pair<K, V>> {
public:
    print(pair<K, V>& p) {
        cout << endl;
        cout << p.first << " " << p.second << endl;
    }
};

template<typename K, typename V>
class print<vector<pair<K, V>>> {
public:
    print(vector<pair<K, V>>& v) {
        cout << endl;
        for (auto& i : v) {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
};
// template <>
// class print<string> {
// private:
//     string str;
// public:
//     print(const string& s) {
//         cout << endl;
//         cout << s << endl;
//     }
// };

template<typename T>
class print<vector<vector<T>>> {
    public:
    print(vector<vector<T>> & matrix){
        cout<<endl;
        for(auto row: matrix){
            for(auto i:row){
                cout<< i<<" ";
            }
            cout<<endl;
        }
    }
};