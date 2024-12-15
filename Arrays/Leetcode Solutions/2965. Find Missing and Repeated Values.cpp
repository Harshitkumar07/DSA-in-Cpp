** Leetcode Problem 2965 :- **

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

Example 1:
Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

Example 2:
Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

** Code :- **

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int a, b, expSum = 0, actualSum = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum = (n * n) * (n * n + 1) / 2;
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};

** Time Complexity :- **
    
Outer and Inner Loops:
The algorithm iterates over an n×n grid using two nested loops. This results in O(n 2) iterations.
Set Operations:
Inside the nested loops, each element is checked against the unordered set s to determine if it has been encountered before. 
Checking and inserting in an unordered set both take O(1) on average, so this contributes O(n 2) across all iterations.
Calculations for Expected Sum:
Calculating the expected sum (n×n)×((n×n)+1)/2 involves a constant-time computation: O(1).
Final Computation of Missing Value:
The missing value is calculated using arithmetic operations, which is also O(1).
Total Time Complexity: O(n 2)

** Space Complexity :- **
    
Unordered Set:
The unordered set s is used to track unique elements from the grid. In the worst case, it holds n2 elements, requiring O(n 2) space.
Answer Vector:
The vector ans stores two integers (the repeated and missing values), which requires O(1) space.
Other Variables:
A few additional variables (a, b, expSum, actualSum) are used, which take O(1) space.
Total Space Complexity: O(n2)
