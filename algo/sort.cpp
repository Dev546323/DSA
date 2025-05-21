#include<iostream>
#include<algorithm>
#include<vector>
#include "/home/yestodrugs/Desktop/DSA/print.h"

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

    // Sample vector of 5 pairs with fixed values for testing
    vector<pair<int, int>> pairs = {
        {42, 17},
        {89, 53},
        {61, 77},
        {31, 24},
        {58, 92},
        {13, 10},
        {27, 10},
        {45, 10},
        {62, 10},
        {88, 10}
    };
    print <vector<pair<int, int>>> p2(pairs);

    sort(pairs.begin(), pairs.end(), compare);
    cout << "Sorted pairs: (second value takes priority)" << endl;
    print <vector<pair<int, int>>> p3(pairs);

    print<int> p1(v);
    reverse(v.begin(), v.end()); 
    cout << "Reversed vector: " << endl;
    print<int> p4(v);
    next_permutation(v.begin(), v.end()); 
    cout << "Next permutation: " << endl;
    print<int> p5(v);

    cout<<"Max Element: "<<*(max_element(v.begin(), v.end()))<<endl;
    cout<<"min Element: "<<*(min_element(v.begin(), v.end()))<<endl;
    cout<<binary_search(v.begin(), v.end(), 37)<<endl; //returns true or false
    cout<<binary_search(v.begin(), v.end(), 36/*target*/)<<endl; //returns true or false



}