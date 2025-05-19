#include<iostream>
#include<list>

using namespace std;

void print(list<int> &l){ 
    for(int i:l){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> l={1,2,3,4,5,6,7,8,9,10}; //initialization is same as vector
    //doubly linked list, so it can be traversed in both directions.
    
    l.push_back(11); 
    l.push_front(0); 

    print(l); 
    l.pop_back();
    l.pop_front();
    print(l);

}