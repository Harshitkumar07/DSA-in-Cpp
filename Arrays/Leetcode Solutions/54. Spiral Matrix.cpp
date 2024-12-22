** Leetcode Problem 54 :- **

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

** Code :- **

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int stRow = 0, stCol = 0, endRow = m - 1, endCol = n - 1;
        vector<int> ans;

        while (stRow <= endRow && stCol <= endCol) {
            // Top
            for (int j = stCol; j <= endCol; j++) {
                ans.push_back(matrix[stRow][j]);
            }
            // Right
            for (int i = stRow + 1; i <= endRow; i++) {
                ans.push_back(matrix[i][endCol]);
            }
            // Bottom
            for (int j = endCol - 1; j >= stCol; j--) {
                if (stRow == endRow) {
                    break;
                }
                ans.push_back(matrix[endRow][j]);
            }
            // Left
            for (int i = endRow - 1; i >= stRow + 1; i--) {
                if (stCol == endCol) {
                    break;
                }
                ans.push_back(matrix[i][stCol]);
            }
            stRow++; endRow--; stCol++; endCol--;
        }
        return ans;
    }
};

** Time Complexity :- **
    
Traversal of Matrix:
The algorithm traverses every element in the matrix exactly once during the spiral traversal.
If the matrix has m rows and n columns, the total number of elements is m×n.
Each element is visited once, so the time complexity is: O(m×n)
Four Loops for Spiral Traversal:
The loops for the top, right, bottom, and left traversals operate over a decreasing number of elements in each iteration of the outer while loop.
However, the overall number of operations remains proportional to the number of elements in the matrix.
Overall Time Complexity: O(m×n)

** Space Complexity :- **
    
Resultant Vector:
The ans vector stores all elements of the matrix in the spiral order.
Its size is equal to the total number of elements in the matrix, O(m×n).
Auxiliary Variables:
A constant amount of extra space is used for variables like stRow, stCol, endRow, endCol, and loop counters.
Overall Space Complexity: O(m×n)
