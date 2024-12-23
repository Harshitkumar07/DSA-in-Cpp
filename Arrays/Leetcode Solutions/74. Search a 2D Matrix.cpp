** Leetcode Problem 74 :- **

You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity. 

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

** Code :- **

class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int target, int row) {
        int st = 0, end = matrix[0].size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == matrix[row][mid]) {
                return true;
            } else if (target > matrix[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int stRow = 0, endRow = matrix.size() - 1;
        while (stRow <= endRow) {
            int midRow = stRow + (endRow - stRow) / 2;
            if (target >= matrix[midRow][0] && 
            target <= matrix[midRow][matrix[0].size() - 1]) {
                return searchRow(matrix, target, midRow);
            } else if (target >= matrix[midRow][matrix[0].size() - 1]) {
                stRow = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }
        return false;
    }
};

Time Complexity Analysis
The searchMatrix algorithm employs binary search twice: once to locate the appropriate row and then to locate the target within that row. Here’s a detailed breakdown of the time complexity:

Step 1: Binary Search on Rows
The outer binary search is applied to the rows of the matrix.
For a matrix with m rows, binary search will take O(logm) time.
Each comparison checks whether the target is within the bounds of the current middle row (matrix[midRow][0] and matrix[midRow][end]).
Step 2: Binary Search Within the Row
Once the target row is identified, binary search is applied to the n columns of that row.
For a row with n columns, binary search will take O(logn) time.
Overall Time Complexity
The two binary searches are independent, so the time complexity adds up:O(logm)+O(logn)
Special Cases
Single Row or Single Column:
For m=1, the outer binary search is skipped, and the complexity becomes O(logn).
For n=1, the inner binary search becomes trivial, and the complexity becomes O(logm).
Empty Matrix:
If the matrix is empty (matrix.size() == 0 or matrix[0].size() == 0), no operations are performed, and the algorithm terminates in O(1) time.
Space Complexity Analysis
Primary Operations
Binary Search on Rows:
Binary search does not use additional memory; it only modifies the indices (stRow, endRow) during the computation.
Binary Search Within the Row:
Similarly, the search within the row modifies the indices (st, end) without allocating extra memory.
Auxiliary Space
The algorithm uses a constant amount of memory for variables like stRow, endRow, midRow, and function parameters.
Overall Space Complexity : O(1)
This is because the algorithm does not use any additional data structures that grow with the size of the input.
