** Leetcode Problem 37 :- **

Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells. 

Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],
               ["6",".",".","1","9","5",".",".","."],
               [".","9","8",".",".",".",".","6","."],
               ["8",".",".",".","6",".",".",".","3"],
               ["4",".",".","8",".","3",".",".","1"],
               ["7",".",".",".","2",".",".",".","6"],
               [".","6",".",".",".",".","2","8","."],
               [".",".",".","4","1","9",".",".","5"],
               [".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]]

** Code :- **

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, int digit) {
        // Horizontal
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit)
                return false;
        }
        // Vertical
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit)
                return false;
        }
        // Grid
        int stRow = (row / 3) * 3, stCol = (col / 3) * 3;
        for (int i = stRow; i <= stRow + 2; i++) {
            for (int j = stCol; j <= stCol + 2; j++) {
                if (board[i][j] == digit)
                    return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }
        for (char digit = '1'; digit <= '9'; digit++) {
            if (isSafe(board, row, col, digit)) {
                board[row][col] = digit;
                if (helper(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { helper(board, 0, 0); }
};

** Time Complexity :- **
    
Recursive Backtracking (helper function)
The helper function iterates over the cells of the Sudoku board. For each empty cell, it tries all digits from '1' to '9'.
For every valid placement, the function recursively proceeds to the next cell. If the placement is invalid, it backtracks and tries the next digit.

In the worst case, the algorithm explores all possible configurations of the board. For a board with cells and 9 possible digits per cell: O(9^n)where n=81 for a 9x9 Sudoku board.
Best Case: If the board is nearly solved, very few recursive calls and placements are required. 
The time complexity is significantly reduced but still proportional to the number of empty cells, m:O(9^m) isSafe Function
For each cell, the isSafe function checks:
Row: O(9)
Column: O(9)
3x3 Subgrid: O(9)
Total for isSafe per cell: O(27)=O(1) (constant as the board size is fixed).
The isSafe function is called up to 9m times in the worst case.
Total Time Complexity :
Best Case: The board is nearly solved, requiring fewer recursive calls and validations.O(9^m⋅27)=O(9^m)
where m is the number of empty cells.
Worst Case: All cells are empty, requiring maximum exploration of configurations.O(9^81⋅27)=O(9^81)
    
** Space Complexity : **

Recursive Stack:
The depth of the recursion corresponds to the number of empty cells, m.
Each recursive call adds to the stack.
Best Case: If there are fewer empty cells, the recursion depth is proportional to m:O(m)
Worst Case: If all cells are empty, the recursion depth reaches 81:O(81)=O(1)
(since 81 is a fixed constant for Sudoku).
In-Place Modification:
The board is modified in place, so no additional space is used for storing the board.
Space Used for Marking: O(1)
Other Storage:
Constant space is used for variables such as row, col, and digit.
Additional Storage:O(1)
Total Space Complexity :
Best Case: O(m)
where m is the number of empty cells.
Worst Case: O(81)=O(1)
since the board size is fixed.
