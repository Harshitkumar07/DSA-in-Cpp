** Leetcode Problem 944 :- **

You are given an array of n strings strs, all of the same length.
The strings can be arranged such that there is one on each line, making a grid.
For example, strs = ["abc", "bce", "cae"] can be arranged as follows:
abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
Return the number of columns that you will delete.

Example 1:
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
cba
daf
ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

Example 2:
Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
a
b
Column 0 is the only column and is sorted, so you will not delete any columns.

Example 3:
Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
zyx
wvu
tsr
All 3 columns are not sorted, so you will delete all 3.

** Code :- **

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(), cols = strs[0].size(), ans = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 1; j < rows; j++) {
                if (strs[j - 1][i] > strs[j][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Iterating Over Columns :
The outer loop runs O(m) times, where m is the number of columns in strs[0].
Iterating Over Rows :
The inner loop runs O(n) times for each column, where n is the number of strings (rows).
It compares adjacent elements in a column.
Total Time Complexity :
Since the inner loop runs for every column, the worst-case time complexity is: O(m⋅n)
Best Case: If no deletions are needed, the algorithm still checks all columns → O(m \cdot n).
Worst Case: If all columns must be deleted, the algorithm still performs O(m \cdot n) checks.

** Space Complexity :- **
    
In-Place Computation :
The function uses only integer variables (rows, cols, ans, i, j) → O(1) space.
No additional data structures are allocated.
Total Space Complexity :
Best and Worst Case: O(1) since no extra memory is used beyond a few variables.
