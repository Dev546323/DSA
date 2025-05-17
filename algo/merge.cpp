//merging 2 sorted arrays into 1. 

#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &a){
    if(a.size()<300){
        for(int i:a)
        cout<<i<<" ";
    }
    cout<<endl;
}

void merge(vector<int>& a, vector <int>& b, int m, int n){
    int index = m+n-1; 
    m-=1;
    n-=1;
  
    while(m>=0 and n>=0){
        if(a[m]>=b[n]){
            a[index] =a[m];
            index--;
            m--;
        }
        else {
            a[index] = b[n];
            index--;
            n--;
        }
     
    }
    while (n >= 0) {
        a[index--] = b[n--];
    }
    print(a);
}


int main(){
    // Test Case 1: Basic merge
std::vector<int> test1_arr1 = {1, 3, 5, 0, 0, 0};
std::vector<int> test1_arr2 = {2, 4, 6};
merge(test1_arr1, test1_arr2, 3, 3);

// Test Case 2: All elements of arr2 smaller
std::vector<int> test2_arr1 = {7, 8, 9, 0, 0, 0};
std::vector<int> test2_arr2 = {1, 2, 3};
merge(test2_arr1, test2_arr2, 3, 3);

// Test Case 3: All elements of arr2 larger
std::vector<int> test3_arr1 = {1, 2, 3, 0, 0, 0};
std::vector<int> test3_arr2 = {7, 8, 9};
merge(test3_arr1, test3_arr2, 3, 3);

// Test Case 4: Duplicates in both arrays
std::vector<int> test4_arr1 = {2, 2, 3, 0, 0, 0};
std::vector<int> test4_arr2 = {2, 3, 4};
merge(test4_arr1, test4_arr2, 3, 3);

// Test Case 5: First array is empty
std::vector<int> test5_arr1 = {0, 0, 0};
std::vector<int> test5_arr2 = {1, 2, 3};
merge(test5_arr1, test5_arr2, 0, 3);

// Test Case 6: Second array is empty
std::vector<int> test6_arr1 = {1, 2, 3};
std::vector<int> test6_arr2 = {};
merge(test6_arr1, test6_arr2, 3, 0);

// Test Case 7: Both arrays empty
std::vector<int> test7_arr1 = {};
std::vector<int> test7_arr2 = {};
merge(test7_arr1, test7_arr2, 0, 0);

// Test Case 8: Large values
std::vector<int> test8_arr1 = {1000000, 2000000, 3000000, 0, 0, 0};
std::vector<int> test8_arr2 = {1500000, 2500000, 3500000};
merge(test8_arr1, test8_arr2, 3, 3);

// Test Case 9: Negative numbers
std::vector<int> test9_arr1 = {-10, -5, 0, 0};
std::vector<int> test9_arr2 = {-6, -3};
merge(test9_arr1, test9_arr2, 2, 2);

// Test Case 10: Stress test with large arrays
std::vector<int> test10_arr1(100000, 1);
test10_arr1.resize(200000, 0); // placeholders
std::vector<int> test10_arr2(100000, 2);
merge(test10_arr1, test10_arr2, 100000, 100000);


}