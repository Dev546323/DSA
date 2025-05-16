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
            if(arr[j]>arr[j+1]){ //checks if the lower index has a higher value, 
                swap(arr[j],arr[j+1]);//in which case it swaps and puts the higher value at a later index
                iswap = true;
            }
        }
       if(!iswap){ //possible optimization, decreasing time in best case i.e providing a pre-sorted array 
           break;
       }
    }
   // print(arr);
}

void selection(vector<int> arr){

    for(int i=0;i<arr.size();i++){
        int small = i;  //considering the current smallest element to be the ith element

        for(int j=i+1;j<arr.size();j++){
           if(arr[j]<arr[small]){ //check if smallest element is smaller than a[j]
           small=j;   //changing smallest element if j is actually the smallest
  
        }
        }
      
        swap(arr[i],arr[small]); //changing i to actually be the smallest element 
    }
    //print(arr);

}

void insertion(vector<int> arr) {

    for (int i = 1; i < arr.size(); i++) { 

        int current = arr[i]; //literally the current value
        int prev = i - 1; //the previous value before current
        while (prev>= 0 && arr[prev] > current) { //loop as long as it doesn't go out of bounds and previous value is larger than current
            arr[prev + 1] = arr[prev]; //the element gets shifted to the right side. 
            prev--; //decreasing loop variable to go towards the left
        }
        arr[prev + 1] = current;
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
vector<int> test2 = {5, 4, 3, 2, 1};
bubble(test2);
selection(test2);
insertion(test2);

// 🧼 Test Case 3: All Elements Same
vector<int> test3 = {7, 7, 7, 7, 7};
bubble(test3);
selection(test3);
insertion(test3);


// 🧼 Test Case 4: Random Order
vector<int> test4 = {3, 1, 4, 2, 5};
bubble(test4);
selection(test4);
insertion(test4);


// 🧼 Test Case 5: Negative Numbers
vector<int> test5 = {-3, -1, -4, -2, -5};
bubble(test5);
selection(test5);
insertion(test5);


// 🧼 Test Case 6: Single Element
vector<int> test6 = {9};
bubble(test6);
selection(test6);
insertion(test6);


// 🧼 Test Case 7: Two Elements Sorted
vector<int> test7 = {1, 2};
bubble(test7);
selection(test7);
insertion(test7);


// 🧼 Test Case 8: Two Elements Unsorted
vector<int> test8 = {2, 1};
bubble(test8);
selection(test8);
insertion(test8);


// 🧼 Test Case 9: Large Range
vector<int> test9 = {100, 2000, 30, 400, 500};
bubble(test9);
selection(test9);
insertion(test9);



// 🧼 Test Case 10: Empty Array
// Input: []
// Expected Output: (no output, but no crash either)
bubble({});
selection({});
insertion({});


// 🚨 Stress 1: 1,000 elements in reverse
// Bubble sort's worst-case, your patience's final test
vector<int> stress1(1000);
iota(stress1.rbegin(), stress1.rend(), 1);
cout<<endl<<"Stress1"<<endl<<endl;
start = high_resolution_clock::now();
bubble(stress1);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Selection"<<endl;
start = high_resolution_clock::now();
selection(stress1);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;cout<<"Insertion"<<endl;
start = high_resolution_clock::now();
insertion(stress1);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;




// 🧨 Stress 2: 5,000 elements in random order
// You might finish your degree before this finishes
vector<int> stress2(5000);
generate(stress2.begin(), stress2.end(), rand);
cout<<endl<<"Stress2"<<endl;
start = high_resolution_clock::now();
bubble(stress2);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Selection"<<endl;
start = high_resolution_clock::now();
selection(stress2);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Insertion"<<endl;
start = high_resolution_clock::now();
insertion(stress2);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;




// 🧊 Stress 3: 1,000 elements, all same
// Should be quick... unless your bubble sort is on vacation
vector<int> stress3(1000, 42);
cout<<endl<<"Stress3"<<endl;
start = high_resolution_clock::now();
bubble(stress3);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Selection"<<endl;
start = high_resolution_clock::now();
selection(stress3);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Insertion"<<endl;
start = high_resolution_clock::now();
insertion(stress3);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;



// 🔥 Stress 4: Already sorted 10,000 elements
// Best-case scenario... but bubble sort still bubbles slowly
vector<int> stress4(10000);
iota(stress4.begin(), stress4.end(), 1);
cout<<endl<<"Stress4"<<endl;
start = high_resolution_clock::now();
bubble(stress4);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Selection"<<endl;
start = high_resolution_clock::now();
selection(stress4);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Insertion"<<endl;
start = high_resolution_clock::now();
insertion(stress4);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;



// 💣 Stress 5: Descending 10,000 elements (max torture)
// Because who *doesn't* love nested loops?
vector<int> stress5(10000);
iota(stress5.rbegin(), stress5.rend(), 1);
cout<<endl<<"Stress5"<<endl;
start = high_resolution_clock::now();
bubble(stress5);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Selection"<<endl;
start = high_resolution_clock::now();
selection(stress5);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;
cout<<"Insertion"<<endl;
start = high_resolution_clock::now();
insertion(stress5);
end = high_resolution_clock::now();
duration = duration_cast<microseconds>(end - start);
cout << "Time taken: " << duration.count() << " microseconds" << endl;




}