** Leetcode Problem 202 :- **

Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false

** Code :- **

class Solution {
public:
    bool isHappy(int n) {
        if (n < 10) {
            if (n == 1 || n == 7)
                return true;
            else
                return false;
        }
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return isHappy(sum);
    }
};

** Time Complexity :- **
    
Breaking Down the Number :
In each iteration of the while (n > 0) loop, the digits of the number n are squared and summed.
For a number with d digits, the sum operation takes O(d).
Using the property that the number of digits d is approximately log 10(n), this operation is O(logn).
Recursive Calls :
The function recurses with the squared digit sum, which generally reduces the value of n.
The number eventually reduces to a repeating cycle or the number 1.
For integers, the maximum number of unique states in the cycle of sums is constant (O(243), as 92×number of digits is bounded).
Thus, the recursion is limited to a constant number of steps in practical terms.
Best Case :
The best case occurs when n reduces to 1 in the first few iterations. This requires only O(logn) operations.
Worst Case :
The worst case occurs when n is large and takes several recursive calls before entering a cycle or reaching 1.
However, this is still bounded by the constant number of unique states in the sum cycle.
Total Time Complexity :
Best Case: O(logn), if n quickly reduces to 1.
Worst Case: O(logn), as the number of recursive calls is limited by a constant.

** Space Complexity :- **
    
Recursive Stack :
Each recursive call adds a frame to the stack.
In the worst case, the stack depth is equal to the number of unique states in the digit-sum cycle, which is constant (O(243)).
Auxiliary Variables :
The algorithm uses a constant amount of space for variables such as sum and digit.
Total Space Complexity :
Best Case: O(logn), when n reduces to 1 in a few recursive calls.
Worst Case: O(1), since the number of unique states is bounded.
