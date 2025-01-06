** Leetcode Problem 2596 :- **

There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.
You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited.
The moves are 0-indexed. Return true if grid represents a valid configuration of the knight's movements or false otherwise.
Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically.
The figure below illustrates all the possible eight moves of a knight from some cell. 

Example 1:
Input: grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
Output: true
Explanation: The above diagram represents the grid. It can be shown that it is a valid configuration.

Example 2:
Input: grid = [[0,3,6],[5,8,1],[2,7,4]]
Output: false
Explanation: The above diagram represents the grid. The 8th move of the knight is not valid considering its position after the 7th move.

** Code :- **

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int n,
                 int expVal) {
        if (row < 0 || col < 0 || row >= n || col >= n ||
            grid[row][col] != expVal)
            return false;
        if (expVal == n * n - 1)
            return true;
        int ans1 = isValid(grid, row - 2, col + 1, n, expVal + 1),
            ans2 = isValid(grid, row - 1, col + 2, n, expVal + 1),
            ans3 = isValid(grid, row + 1, col + 2, n, expVal + 1),
            ans4 = isValid(grid, row + 2, col + 1, n, expVal + 1),
            ans5 = isValid(grid, row + 2, col - 1, n, expVal + 1),
            ans6 = isValid(grid, row + 1, col - 2, n, expVal + 1),
            ans7 = isValid(grid, row - 1, col - 2, n, expVal + 1),
            ans8 = isValid(grid, row - 2, col - 1, n, expVal + 1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

** Time Complexity :- **
    
Recursive Calls in isValid :
For each position (row, col), the function explores 8 possible moves recursively.
The depth of the recursion is determined by the size of the grid n, as the function attempts to validate a sequence of numbers from 0 to n×n−1.
In the worst case, all n2 cells of the grid are visited, and for each cell, the function explores up to 8 moves. This results in a time complexity of: O(8n2)
This exponential growth occurs because there is no pruning of invalid paths unless explicitly terminated by grid constraints.
Best Case :
In the best case, the function finds a valid path early and terminates recursion. If the sequence is valid without backtracking, the complexity is reduced to visiting all n2 cells once: O(n2)
Total Time Complexity :
Best Case: O(n2) (valid sequence without backtracking).
Worst Case: O(8n2) (exploring all possible paths in the grid).

** Space Complexity :- **
    
Recursive Stack :
The maximum depth of the recursion corresponds to the total number of cells in the grid, n2.
Each recursive call adds to the stack, resulting in: O(n2)
This occurs when a full sequence traversal is attempted.
Other Storage :
No additional data structures are used apart from constant-sized variables. The grid is passed by reference and not copied.
Space Used for Variables: O(1)
Total Space Complexity :
Best Case: O(n2) (minimal recursion depth if valid path found early).
Worst Case: O(n2) (maximum recursion depth).
