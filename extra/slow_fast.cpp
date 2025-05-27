//to find duplicates

#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>
#include<numeric>

int slow(vector<int> &nums){
    auto slow = nums[0];
    auto fast = nums[0];

    do{
        slow = nums[slow]; //moves  asingle step considers the value at current index as the next index
        fast = nums[nums[fast]]; // moves two steps, considers the the value of the current index as the next index, and finally stores the value there as it's index. 
    }
    while(slow != fast);
    slow = nums[0]; //fast is already at a diff position 
    while(slow != fast){
        slow = nums[slow]; 
        fast = nums[fast];
    }
    return slow; //or fast, doesn't matter
}

using namespace std;   

int main() {
    vector<int> test1  = {1, 3, 4, 2, 2};                  // Basic case, duplicate is 2
vector<int> test2  = {3, 1, 3, 4, 2};                  // Duplicate at start
vector<int> test3  = {1, 1};                           // Smallest input size
vector<int> test4  = {1, 4, 6, 3, 2, 5, 6};            // Duplicate at the end
vector<int> test5  = {2, 2, 2, 2, 2};                  // All elements are the duplicate
vector<int> test6  = {9, 8, 7, 6, 5, 4, 3, 2, 1, 9};   // Reverse order, duplicate at ends
vector<int> test7  = {1, 5, 3, 4, 2, 6, 7, 8, 9, 5};   // Duplicate somewhere in middle
vector<int> test8  = {2, 6, 4, 1, 3, 5, 7, 6};         // Another random pattern
vector<int> test9  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                      11, 12, 13, 14, 15, 16, 17, 
                      18, 19, 20, 13};                // Stress test with 21 elements
vector<int> test10 = [](){
    vector<int> v(100001);
    iota(v.begin(), v.end(), 1);   // Fill 1 to 100001
    v[100000] = 99999;             // Duplicate 99999
    return v;
}();                                                  // Massive stress test

        cout<< slow(test1)<<endl;
    cout<< slow(test2)<<endl;
    cout<< slow(test3)<<endl;
    cout<< slow(test4)<<endl;
    cout<< slow(test5)<<endl;
    cout<< slow(test6)<<endl;
    cout<< slow(test7)<<endl;
    cout<< slow(test8)<<endl;
    cout<< slow(test9)<<endl;
    cout<< slow(test10)<<endl;

    return 0;
}