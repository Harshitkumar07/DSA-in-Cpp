** Leetcode Problem 1143 :- **

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

** Code :- **

class Solution {
public:
    int lcs(const string& text1, const string& text2, int m, int n,
            vector<vector<int>>& memo) {
        if (m == 0 || n == 0)
            return 0;
        if (memo[m][n] != -1)
            return memo[m][n];
        if (text1[m - 1] == text2[n - 1]) {
            memo[m][n] = 1 + lcs(text1, text2, m - 1, n - 1, memo);
        } else {
            memo[m][n] = max(lcs(text1, text2, m - 1, n, memo),
                             lcs(text1, text2, m, n - 1, memo));
        }
        return memo[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return lcs(text1, text2, m, n, memo);
    }
};

** Time Complexity :- **
    
Recursive Calls with Memoization:
Without memoization, the recursive solution explores all possible subsequences, resulting in an exponential O(2max(m,n)) complexity.
With memoization, we store the results of overlapping subproblems. The function lcs is called only once for each pair of indices (m,n), which results in a total of m×n unique subproblems.
Work Per Subproblem:
Each subproblem involves O(1) work for comparisons and memo table updates.
Overall Time Complexity: O(m×n)
Here, m and n are the lengths of the strings text1 and text2, respectively.

** Space Complexity :- **
    
Memoization Table:
The 2D vector memo has (m+1)×(n+1) elements, requiring O(m×n) space.
Recursive Stack Space:
The maximum depth of recursion is the larger of m or n, leading to O(max(m,n)) stack space.
Overall Space Complexity: O(m×n)+O(max(m,n))
The O(m×n) term dominates in most cases.
