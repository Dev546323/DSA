#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <random>
#include<ctime>

using namespace std;



void merge(vector<int>& arr, int start, int mid, int end) {
vector<int> temp(end-start+1);

int left = start, right = mid + 1, index = 0;

while (left <= mid && right <= end) { //comparing elements from both halves at the same time to fill up temp array with sorted values.
   if(arr[left] <= arr[right]) {
        temp[index] = arr[left];
        left++;
    } else {
        temp[index] = arr[right];
        right++;
    }
    index++;
 }
while(left<=mid){ //if left half is not exhausted, fill up the rest of temp with left half elements
    temp[index] = arr[left];
    left++;
    index++;
 }
while(right<=end){ //if right half is not exhausted, fill up the rest of temp with right half elements
    temp[index] = arr[right];
    right++;
    index++;
 }
 index =0; 
 while(start <= end) { //filling up the final array with sorted values from temp
    arr[start] = temp[index];
    start++;
    index++;
 }
}

//we divide the array until a single elemnt is left
//we start merging the divided arrays from the bottom up, i.e. we merge the smallest subarrays first and then merge them to form larger sorted arrays.
void mergesort(vector<int>& arr, int start=0, int end=-1){
    if(end == -1) {
        end = arr.size() - 1; 
    }
    if(start >= end) {
        return; 
    }
    int mid= start + (end - start) / 2; 

    mergesort(arr, start, mid); //divide left half
 
    mergesort(arr, mid + 1, end); //divide right half

    merge(arr, start, mid, end); //actual merge sort after dividing
}

int partition(vector<int>& arr, int start, int end){
    int temp = start;
    for(int i=start;i<=end;i++){ //puts pivot in the right place
        if(arr[i]<=arr[end]){ //puts all smaller elements in the left half, and all bigger elements to the right half
            swap(arr[i], arr[temp]);
            temp++;
        }
    }
    return temp-1;//returns the new pivot index
}
//pivot is where an arbitary element is placed at it's sorted correct position with all the smaller elements to the left and bigger elements to the right.

void quicksort(vector<int>& arr, int start=0, int end=-1) {
    if(end == -1) {
        end = arr.size() - 1; 
    }
    if(start >= end) {
        return; 
    }
    int pivot = partition(arr, start, end);

    quicksort(arr, start, pivot - 1); //sort left half
    quicksort(arr, pivot+1 , end); //sort right half
}

int main() {
    vector<int> arr (50000);
    for(int i = 0; i < 50000; ++i) {
        arr[i] = rand() % 10000; // Fill with random numbers
    }

    timer t;
    t.start();
    quicksort(arr);
    t.end();
    t.milliseconds("Quick sort");

    for(int i = 0; i < 50000; ++i) {
        arr[i] = rand() % 50000; // Fill with random numbers
    }   
     timer t2;
   
    print p(arr, 200);
   
    t2.start();
    mergesort(arr);
    t2.end();
    t2.milliseconds("merge sort");
  
    
    return 0;
}