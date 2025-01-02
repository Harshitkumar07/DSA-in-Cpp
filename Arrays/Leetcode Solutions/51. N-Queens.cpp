** Leetcode Problem 51 :- **

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

** Code :- **

class Solution {
public:
    bool isSafe(const vector<string>& board, int row, int col, int n) {
        // Horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        // Vertical
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // Left Diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // Right Diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};

** Time Complexity :- **

1. isSafe Function Complexity
Each call to isSafe performs the following checks:
Horizontal: O(n), where n is the size of the board.
Vertical: O(n).
Left Diagonal: O(n) (maximum elements checked along the diagonal).
Right Diagonal: O(n).
The total cost per call to isSafe is: O(n+n+n+n)=O(4n)=O(n)
2. Recursive Function nQueens
The nQueens function tries all columns in the current row. For each column:
It calls isSafe once, which is O(n).
If the position is safe, the function makes a recursive call to the next row.
At each row, there are n possible columns to place the queen. In the worst case, this recursion generates n! valid permutations of queen placements.
Total Complexity :
The total number of calls to isSafe over all recursive calls is approximately n! times n, resulting in: O(n⋅n!)=O(n⋅n!)
    
** Space Complexity :- **
    
Board Storage:
The board vector has n strings, each of length n. Thus, it requires O(n2) space.
Recursive Stack:
The depth of the recursive stack is n (one call per row).
Answer Storage:
The ans vector stores all valid solutions. In the worst case, there are n! solutions, and each solution uses O(n2) space to store the board configuration.
Overall Space Complexity: O(n2)+O(n)+O(n!⋅n2)=O(n!⋅n2)
