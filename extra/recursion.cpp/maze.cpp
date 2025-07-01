#include "/home/yestodrugs/Desktop/DSA/print.h"


using namespace std;

vector<string> path(vector<vector<int>>& maze, int row , int col, vector<string> &possible, string current){
    if(row <0 or col <0 or row >= maze.size() or col >= maze.size() or maze[row][col] == 0){
        return possible; // out of bounds or blocked cell
    }
    if(row == maze.size()-1 and col == maze.size()-1){
        possible.push_back(current); // reached the destination
        return possible;
    }
    if(maze[row][col] == 2){
        return possible; // already visited cell
    }
    maze[row][col] = 2; // mark the cell as visited
    // move down
    path(maze, row + 1, col, possible, current + "D");
    // move up
    path(maze, row - 1, col, possible, current + "U");
    // move right
    path(maze, row, col + 1, possible, current + "R");
    // move left
    path(maze, row, col - 1, possible, current + "L");
    maze[row][col] = 1; // unmark the cell as visited
    return possible; // return the possible paths found
}

void rat(vector<vector<int>>& maze){
    vector<vector<bool> > visited(maze.size(), vector<bool>(maze.size(), true));
    vector<string> possible;
    string current = "";
    possible = path(maze, 0,0 ,possible, current) ;
    print<string> p(possible);
}


int main() {
    // Test Case 1: Simple 2x2 Maze (Single Path)
vector<vector<int>> maze1 = {
    {1, 1},
    {0, 1}
};
// Expected output: One path, e.g., "RD"

// Test Case 2: 4x4 Maze with Multiple Paths
vector<vector<int>> maze2 = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 1, 1, 1}
};
// Expected output: Multiple paths, e.g., "DRDDRR", "DRDRDR", etc.

// Test Case 3: No Path Available
vector<vector<int>> maze3 = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};
// Expected output: No valid path (empty result)

// Test Case 4a: Start is Blocked
vector<vector<int>> maze4 = {
    {0, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
};
// Expected output: No path

// Test Case 4b: End is Blocked
vector<vector<int>> maze5 = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 0}
};
// Expected output: No path

rat(maze1);
rat(maze2);
rat(maze3); 
rat(maze4);
rat(maze5);
    return 0;
}