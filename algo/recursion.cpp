#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>


using namespace std;

int fibo (int n){
    if(n-2==0 or n-1==0) return 1;
    return fibo(n-1) + fibo(n-2);
}

void check(vector<int> arr){
    int n = arr.size();
    if(arr.size()-2 <= 0) 
    return;
    if( arr[n-1] >=arr[n-2]){
        arr.pop_back();
        check(arr);
    }
}

int main() {
    cout<<fibo(13);
    return 0;
}