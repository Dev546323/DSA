#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>



using namespace std;

bool search(vector<vector<int>> matrix, int target){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
int diagonalSumbrute(vector<vector<int>> matrix){ // brute force O(n*n)
    int sum=0;
     for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(i==j){
                sum+=matrix[i][j]; // Primary diagonal
            }
            if(j==matrix.size()-1-i){
                sum+=matrix[i][j]; // Secondary diagonal
            }
        }
     }
     return sum;
}
int diagonalSum(vector<vector<int>> matrix) { // Optimized O(n) solution
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        sum += matrix[i][i]; // Primary diagonal
        if (i != matrix.size() - 1 - i) { // Avoid double counting the middle element in odd-sized matrices
            sum += matrix[i][matrix.size() - 1 - i]; // Secondary diagonal
        }
    }
    return sum;
}

int main() {
    vector<vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8,17,18,19,20}, //magic of using vectors instead of arrays
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    print<vector<vector<int>>> p(matrix);
    int target = 10;
    cout<<"Searching for " << target << ": " << (search(matrix, target) ? "Found" : "Not Found") << endl;
    cout << "Diagonal Sum (Brute Force): " << diagonalSumbrute(matrix) << endl;
    cout << "Diagonal Sum (Optimized): " << diagonalSum(matrix) << endl;
 

    return 0;
}