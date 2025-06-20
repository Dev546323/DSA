#include "/home/yestodrugs/Desktop/DSA/print.h"
#include <iostream>
#include<vector>

using namespace std;

bool safe(vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solve(vector<vector<string>>& ans, vector<string>& board, int row, int n){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int i =0;i<n;i++){
        if(safe(board, row, i, n)){
            board[row][i] = 'Q'; // Place queen
            solve(ans, board, row + 1, n); // Recur to place next queen
            board[row][i] = '.'; // Backtrack
        }
    }
}

vector<vector<string>> Nqueens (int n){
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(ans, board, 0, n);
    cout<<ans.size()<<" solutions found for "<<n<<" queens."<<endl;
     return ans;
}
int main() {
    Nqueens(4); // Example for 4x4 board
    Nqueens(8); // Example for 8x8 board
    Nqueens(13);
    return 0;
}