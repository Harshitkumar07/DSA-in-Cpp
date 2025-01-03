** Leetcode Problem 79:- **

Given an m x n grid of characters board and a string word, return true if word exists in the grid.0
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once. 

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

** Code :- **

class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int w) {
        int n = board.size(), m = board[0].size();
        if (w == word.size())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[w])
            return false;
        char c = board[i][j];
        board[i][j] = '.';
        if (dfs(i + 1, j, board, word, w + 1) || dfs(i - 1, j, board, word, w + 1) ||
            dfs(i, j - 1, board, word, w + 1) || dfs(i, j + 1, board, word, w + 1))
            return true;
        board[i][j] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    int w = 0;
                    if (dfs(i, j, board, word, w))
                        return true;
                }
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
1. Outer Iteration over the Board
The function iterates through every cell in the board to check if the starting character of the word matches. If the board has n rows and m columns, the outer iteration takes: O(n⋅m)
2. Depth-First Search (DFS)
In the worst case, for each cell, the DFS can visit every cell in the board. For a word of length k, the recursive DFS explores up to 4 directions (up, down, left, right) at each step. 
However, since cells already visited are marked, the effective number of recursive calls is reduced. The DFS complexity is:O(4^k)
where k is the length of the word.
3. Total Time Complexity
For every cell in the board, the DFS may be called. Therefore, the overall time complexity is: O(n⋅m⋅4^k)

** Space Complexity :- **
    
1. Recursion Stack
The DFS recursion depth corresponds to the length of the word, k. Each recursive call adds to the stack, resulting in a space complexity of: O(k)
2. Board Modifications
The board is modified in place to mark visited cells, so no additional space is used for marking.
3. Other Storage
Only constant space is used for variables in the function.
Overall Space Complexity : O(k)
