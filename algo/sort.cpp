#include<iostream>
#include<algorithm>
#include<vector>
#include "/home/yestodrugs/Desktop/print.h"

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second>b.second) return false;
    if(a.second<b.second) return true;

    if(a.first>b.first) return false;
    if(a.first<b.first) return true;
    return false;
}

int main(){

    int arr[10] = {37, 82, 14, 59, 23, 71, 46, 5, 68, 91};
    sort(arr, arr + 10); //sort function takes the start and end of the array
    print<int> p(arr);

    vector<int> v = {37, 82, 14, 59, 23, 71, 46, 5, 68, 91};
    sort(v.begin(), v.end(), greater<int>()); //the comparator makes the function sort in descending order
    print<int> p1(v);

    // Sample vector of 5 pairs with fixed values for testing
    vector<pair<int, int>> pairs = {
        {42, 17},
        {89, 53},
        {6, 77},
        {31, 24},
        {58, 92}
    };
    print <vector<pair<int, int>>> p2(pairs);
}