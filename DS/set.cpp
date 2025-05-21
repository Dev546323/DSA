#include<iostream>
#include<set>
#include<unordered_set>
#include<type_traits>
#include "/home/yestodrugs/Desktop/print.h"
using namespace std;

int main(){
    set<int> s; //set completely ignores duplicates
    
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);

    cout << "Set elements (sorted):" << endl;
     print<int> p1(s);
    cout<<s.count(11)<<endl; //checks the presence of an element

    s.erase(5);
    cout<<*(s.lower_bound(5))<<endl; // greater than or equal to
    cout<<*(s.upper_bound(6))<<endl; //greater than only. 

    multiset<int> ms; //multiset allows duplicates
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);
    ms.insert(6);
    ms.insert(7);
    ms.insert(8);
    ms.insert(8);
    ms.insert(9);
    ms.insert(10);
    
    cout<<"Multiset- has duplicates"<<endl;
    print<int> p2(ms);

    unordered_set<int> us; //unordered set does not guarantee order
    us.insert(1); //no lower bound and upper bound
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);
    us.insert(6);
    us.insert(7);
    us.insert(8);
    us.insert(9);
    us.insert(9);

    cout<<"Unordered set- no order"<<endl;
    print<int> p3(us);
}