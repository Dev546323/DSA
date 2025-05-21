#include<iostream>
#include<algorithm>
#include<vector>
#include "/home/yestodrugs/Desktop/DSA/print.h"

using namespace std;



int main(){

    int arr[10] = {37, 82, 14, 59, 23, 71, 46, 5, 68, 91};
    sort(arr, arr + 10); //sort function takes the start and end of the array
    print<int> p(arr);
}