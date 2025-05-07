#include<iostream>
#include <vector>

using namespace std;

int brute(vector<int> side){
    int water=0;
    int level=0;
    int maxi =0; 
    for(int i=0;i<side.size();i++){
        for(int j=i+1;j<side.size();j++){
            level = min(side[i],side[j]);
            water= level*(j-i);
            maxi = max(maxi,water);
        }
    }
    return maxi;
}

int optimize (vector<int> side){
    int left =0;
    int right=side.size()-1;
    int waterlevel=0;
    while (left<right){
        int level = min(side[right], side[left]);
        waterlevel = max(waterlevel, level*(right-left));
        if(side[right]>side[left]){
            left++;
        }
        else right--;

    }
    return waterlevel;
}

int main(){
    vector<int> test1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};     // Expected: 49
vector<int> test2 = {1, 1};                         // Expected: 1
vector<int> test3 = {4, 3, 2, 1, 4};                // Expected: 16
vector<int> test4 = {1, 2, 1};                      // Expected: 2
vector<int> test5 = {2, 3, 10, 5, 7, 8, 9};         // Expected: 36
// Edge Case: All elements are equal
vector<int> edge1 = {5, 5, 5, 5, 5};                // Expected: 20

// Edge Case: Only two lines
vector<int> edge2 = {1000, 1000};                   // Expected: 1000

// Edge Case: Increasing heights
vector<int> edge3 = {1, 2, 3, 4, 5};                // Expected: 6

// Stress Test: Large input with peaks
vector<int> stress1 = {1, 10000, 1, 10000, 1};      // Expected: 20000

// Stress Test: Very large input (1e5 elements)
vector<int> stress2(100000, 1);                     // Expected: 99999
cout<<brute(test1)<<endl;
cout<<brute(test2)<<endl;
cout<<brute(test3)<<endl;
cout<<brute(test4)<<endl;
cout<<brute(test5)<<endl;
cout<<brute(edge1)<<endl;
cout<<brute(edge2)<<endl;
cout<<brute(edge3)<<endl;
cout<<brute(stress1)<<endl;
cout<<brute(stress2)<<endl;
cout<<"Brute finishes here\n";
cout<<optimize(test1)<<endl;
cout<<optimize(test2)<<endl;
cout<<optimize(test3)<<endl;
cout<<optimize(test4)<<endl;
cout<<optimize(test5)<<endl;
cout<<optimize(edge1)<<endl;
cout<<optimize(edge2)<<endl;
cout<<optimize(edge3)<<endl;
cout<<optimize(stress1)<<endl;
cout<<optimize(stress2)<<endl;


}