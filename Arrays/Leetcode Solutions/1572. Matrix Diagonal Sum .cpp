** Leetcode Problem 1572 :- **

Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

Example 1:
Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:
Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

Example 3:
Input: mat = [[5]]
Output: 5

** Code :- **

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            if (i != n - i - 1) {
                sum += mat[i][n - i - 1];
            }
        }
        return sum;
    }
};

** Time Complexity :- **
    
Iterating Over the Matrix:
The for loop iterates through each row of the square matrix mat of size n. Since there is one iteration per row, this operation takes O(n).
Constant-Time Operations:
During each iteration, two elements are accessed and added to the sum: one from the primary diagonal (mat[i][i]) and one from the secondary diagonal (mat[i][n−i−1]). 
These are O(1) operations.
Overall Time Complexity: O(n)

** Space Complexity :- **
    
Auxiliary Variables:
The algorithm uses a few integer variables (n and sum), which require O(1) space.
No Additional Data Structures:
No extra data structures are used since the matrix is accessed in place.
Overall Space Complexity: O(1)
