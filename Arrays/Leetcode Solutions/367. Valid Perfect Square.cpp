** Leetcode Problem 367:- **

Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.

Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

** Code :- **

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int start = 1;
        int end = num;
        while (start <= end) {
            double mid = start + (end - start) / 2;
            if (mid * mid == num) {
                return true;
            } else if (mid * mid > num) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Binary Search Process:
The algorithm reduces the search space by half in each iteration.
The number of iterations required is approximately log 2(num), where num is the input number.
Time Complexity: O(log(num))

** Space Complexity :- **
    
Constant Space Usage:
Only a few variables (start, end, mid) are used to track the search range and perform calculations.
No additional data structures are utilized.
Space Complexity: O(1)
