#include<iostream>
#include<deque>

using namespace std;
//dequeue means to popback an element. de-queuing an element. 

void print(deque<int> &d){ 
    for(int i:d){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    deque<int> d={1,2,3,4,5,6,7,8,9,10}; //initialization is same as list
    //doubly linked list, so it can be traversed in both directions.
    
    d.push_back(11); 
    d.push_front(0); 

    print(d); 
    d.pop_back();
    d.pop_front();
    print(d);

}