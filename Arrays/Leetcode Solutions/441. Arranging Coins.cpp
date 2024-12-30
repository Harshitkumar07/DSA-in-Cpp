** Leetcode Problem 441 :- **

You have n coins and you want to build a staircase with these coins. 
The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
Given the integer n, return the number of complete rows of the staircase you will build.

Example 1:
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

Example 2:
Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.

** Code :- **

class Solution {
public:
    int arrangeCoins(int n) {
        long int left = 1, right = n;
        while (left <= right) {
            long int mid = left + (right - left) / 2, sum = mid * (mid + 1) / 2;
            if (sum == n) {
                return mid;
            } else if (sum > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};

** Time Complexity :- **

Binary Search: 
The algorithm performs a binary search to determine the largest number of complete rows k that can be formed.
At each step, the range of possible values for k is halved.
The total number of steps is O(logn), where n is the input.
Arithmetic Operations:
For each iteration, the calculation of the sum mid×(mid+1)/2 takes O(1).
Overall Time Complexity: O(logn)
    
** Space Complexity :- **
    
Auxiliary Storage:
The algorithm uses a constant amount of extra space for variables such as left, right, mid, and sum.
Overall Space Complexity: O(1)
The algorithm does not require additional data structures.
