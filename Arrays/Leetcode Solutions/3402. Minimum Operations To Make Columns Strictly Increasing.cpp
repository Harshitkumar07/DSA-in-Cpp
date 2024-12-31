** Leetcdoe Problem 3402 :- **

You are given a m x n matrix grid consisting of non-negative integers.
In one operation, you can increment the value of any grid[i][j] by 1.
Return the minimum number of operations needed to make all columns of grid strictly increasing.

Example 1:
Input: grid = [[3,2],[1,3],[3,4],[0,1]]
Output: 15
Explanation:
To make the 0th column strictly increasing, we can apply 3 operations on grid[1][0], 2 operations on grid[2][0], and 6 operations on grid[3][0].
To make the 1st column strictly increasing, we can apply 4 operations on grid[3][1].

Example 2:
Input: grid = [[3,2,1],[2,1,0],[1,2,3]]
Output: 12
Explanation:
To make the 0th column strictly increasing, we can apply 2 operations on grid[1][0], and 4 operations on grid[2][0].
To make the 1st column strictly increasing, we can apply 2 operations on grid[1][1], and 2 operations on grid[2][1].
To make the 2nd column strictly increasing, we can apply 2 operations on grid[1][2].

** Code :- **

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int opr = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (grid[i][j] <= grid[i - 1][j]) {
                    int inc = grid[i - 1][j] - grid[i][j] + 1;
                    opr += inc;
                    grid[i][j] += inc;
                }
            }
        }
        return opr;
    }
};

** Time Complexity :- **
    
Outer Loop:
The algorithm iterates over each column of the grid, which has n columns.
Inner Loop:
For each column, it iterates over the rows (from the second row to the last row), which has m−1 iterations per column.
The total number of iterations is proportional to m×n, where m is the number of rows and n is the number of columns.
Overall Time Complexity: O(m×n)
    
** Space Complexity :- **
    
Auxiliary Storage:
The algorithm uses a constant amount of extra space for variables like opr and inc.
Grid Update:
The modifications are made directly on the input grid, so no additional space is required.
Overall Space Complexity: O(1)
The algorithm operates in-place without any additional data structures.
