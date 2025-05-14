#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<chrono>


using namespace std;
using namespace std::chrono;

void print(vector<int> arr){
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void bubble(vector<int> arr){ //n^2 time complexity. 
    for(int i=0;i<arr.size();i++){

        bool iswap = false;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                iswap = true;
            }
        }
       if(!iswap){ //possible optimization, decreasing time in best case i.e providing a pre-sorted array 
           break;
       }
    }
   // print(arr);
}








int main(){
    // 🧼 Test Case 1: Already Sorted
// Input: [1, 2, 3, 4, 5]
// Expected Output: 1 2 3 4 5
auto start = high_resolution_clock::now();
bubble({1, 2, 3, 4, 5});
auto end = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;

// 🧼 Test Case 2: Reverse Sorted
// Input: [5, 4, 3, 2, 1]
// Expected Output: 1 2 3 4 5
bubble({5, 4, 3, 2, 1});

// 🧼 Test Case 3: All Elements Same
// Input: [7, 7, 7, 7, 7]
// Expected Output: 7 7 7 7 7
bubble({7, 7, 7, 7, 7});

// 🧼 Test Case 4: Random Order
// Input: [3, 1, 4, 2, 5]
// Expected Output: 1 2 3 4 5
bubble({3, 1, 4, 2, 5});

// 🧼 Test Case 5: Negative Numbers
// Input: [-3, -1, -4, -2, -5]
// Expected Output: -5 -4 -3 -2 -1
bubble({-3, -1, -4, -2, -5});

// 🧼 Test Case 6: Single Element
// Input: [9]
// Expected Output: 9
bubble({9});

// 🧼 Test Case 7: Two Elements Sorted
// Input: [1, 2]
// Expected Output: 1 2
bubble({1, 2});

// 🧼 Test Case 8: Two Elements Unsorted
// Input: [2, 1]
// Expected Output: 1 2
bubble({2, 1});

// 🧼 Test Case 9: Large Range
// Input: [100, 2000, 30, 400, 500]
// Expected Output: 30 100 400 500 2000
bubble({100, 2000, 30, 400, 500});

// 🧼 Test Case 10: Empty Array
// Input: []
// Expected Output: (no output, but no crash either)
bubble({});

// 🚨 Stress 1: 1,000 elements in reverse
// Bubble sort's worst-case, your patience's final test
vector<int> stress1(100);
iota(stress1.rbegin(), stress1.rend(), 1);
cout<<endl<<"Stress1"<<endl<<endl;
start = high_resolution_clock::now();
bubble(stress1);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;


// 🧨 Stress 2: 5,000 elements in random order
// You might finish your degree before this finishes
vector<int> stress2(500);
generate(stress2.begin(), stress2.end(), rand);
cout<<endl<<"Stress2"<<endl<<endl;
start = high_resolution_clock::now();
bubble(stress2);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;


// 🧊 Stress 3: 1,000 elements, all same
// Should be quick... unless your bubble sort is on vacation
vector<int> stress3(1000, 42);
cout<<endl<<"Stress3"<<endl<<endl;
start = high_resolution_clock::now();
bubble(stress3);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;


// 🔥 Stress 4: Already sorted 10,000 elements
// Best-case scenario... but bubble sort still bubbles slowly
vector<int> stress4(1000);
iota(stress4.begin(), stress4.end(), 1);
cout<<endl<<"Stress4"<<endl<<endl;
start = high_resolution_clock::now();
bubble(stress4);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;


// 💣 Stress 5: Descending 10,000 elements (max torture)
// Because who *doesn't* love nested loops?
vector<int> stress5(1000);
iota(stress5.rbegin(), stress5.rend(), 1);
cout<<endl<<"Stress5"<<endl<<endl;
start = high_resolution_clock::now();
bubble(stress5);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;



}