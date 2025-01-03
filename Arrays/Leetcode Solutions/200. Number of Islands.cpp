** Leetcode Problem 200:- **

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

** Code :- **

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};

** Time Complexity :- **
    
Outer Iteration over the Grid
The numIslands function iterates through all cells of the grid, which has n rows and m columns.
Complexity:O(n⋅m)
This remains the same in both best and worst cases, as the function always checks each cell.
Depth-First Search (DFS)
For every cell containing '1', the dfs function is invoked to explore the connected component (island).
Best Case: Each island is very small (e.g., 1 or a few cells), so DFS only performs minimal recursive calls per cell.O(n⋅m)
because every cell is processed, but DFS work is limited.
Worst Case: The entire grid is a single island, so DFS traverses all n⋅m cells in one go. O(n⋅m)
Total Time Complexity
In both best and worst cases, each cell is processed exactly once, either by the outer loop or by DFS.
Best Case:O(n⋅m)
when islands are small and DFS recursion is shallow.
Worst Case: O(n⋅m)
when the entire grid is a single island, requiring maximal DFS traversal.

** Space Complexity :- **

Recursion Stack in DFS
DFS uses the recursion stack to keep track of visited nodes.
Best Case: Each island is small, and the maximum recursion depth is limited to the size of the largest small island, k:O(k)
Worst Case: The entire grid is a single island, resulting in a recursion depth of up to n⋅m:O(n⋅m)
Grid Modifications
The grid is modified in place to mark visited cells as '2', requiring no additional space.
Space Used for Marking:O(1)
in both best and worst cases.
Other Storage
Only constant space is used for variables such as i, j, and cnt.
Additional Storage: O(1)
Total Space Complexity :
Best Case:O(k)
where k is the size of the largest small island.
Worst Case: O(n⋅m)
if the entire grid is a single island.
