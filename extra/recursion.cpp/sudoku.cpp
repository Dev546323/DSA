#include "/home/yestodrugs/Desktop/DSA/print.h"

using namespace std;
bool safe(vector<vector<int>>& board, int row, int col, int num) {

    for(int i=0;i<9;i++){
        if(board[row][i] == num || board[i][col] == num) {
            return false; // check row and column
        }
        if(board[(row/3)*3 + i/3][(col/3)*3 + i%3] == num) {
            return false; // check 3x3 subgrid
        }
        if(board[row][col] == num) {
            return false; // check if the cell is already filled
        }
    }
    return true;
}

bool sudoku(vector<vector<int>>& board, int row, int col) {
    if (row == 9) return true; 
    int nextrow= row, nextcol= col;

    if (col==9){
        nextrow++;
        nextcol=0;
    }

    if(board[row][col] != '.') {
        return sudoku(board, nextrow, nextcol); // move to the next cell
    }

    for(int i=1; i<=9; i++){
        if(safe(board, row, col,i)){
            board[row][col] = i; // place the number
            if(sudoku(board, nextrow, nextcol)) {
                return true; // if it leads to a solution, return true
            }
            board[row][col] = '.'; // backtrack if it doesn't lead to a solution
        }
    }
    return false; // if no number can be placed, return false

}

int main() {

    return 0;
}