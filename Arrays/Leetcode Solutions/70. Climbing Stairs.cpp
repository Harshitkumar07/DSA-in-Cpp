** Leetcode Problem 70 :- **

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

** Code :- **

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int prev1 = 3, prev2 = 2, ans = 0;
        for (int i = 3; i < n; i++) {
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};

** Time Complexity :- **
    
Single Iteration :
The function iterates from i=3 to i=n−1. This is a single loop running for n−3 iterations.
The time complexity for this loop is O(n), where n is the input value.
Best Case :
The best case occurs when n≤3, as the function directly returns the value n without entering the loop. This requires O(1) operations.
Worst Case :
The worst case occurs when n>3, requiring n−3 iterations to compute the result. The complexity remains O(n).
Total Time Complexity :
Best Case: O(1), if n≤3.
Worst Case: O(n), if n>3.
    
** Space Complexity :- **
    
Auxiliary Variables :
The algorithm uses three integer variables: prev1, prev2, and ans.
These consume a constant amount of space, O(1), regardless of the input size.
No Additional Data Structures :
The algorithm does not use arrays, recursion, or any dynamic data structures, so no additional memory is consumed.
Total Space Complexity :
Best Case: O(1), as the space usage is constant.
Worst Case: O(1), with no additional space required.
