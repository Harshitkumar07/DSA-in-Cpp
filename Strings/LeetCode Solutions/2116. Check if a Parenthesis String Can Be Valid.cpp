** Leetcode Problem 2116 :- **

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.

Example 1:
Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.

Example 2:
Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.

Example 3:
Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.

** Code :- **

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) 
            return false;
        int balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '1') {
                balance += (s[i] == '(') ? 1 : -1;
            } else {
                balance++;
            }
            if (balance < 0) 
                return false;
        }
        balance = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                balance += (s[i] == ')') ? 1 : -1;
            } else {
                balance++;
            }
            if (balance < 0)
                return false;
        }
        return true;
    }
};

** Time Complexity :- **

Left-to-Right Pass :
The algorithm iterates through the string s once, using a single for loop.
At each iteration:
It performs constant-time operations like checking the value of locked[i], comparing characters, and updating the balance.
Time Complexity: O(n), where n is the length of the string s.
Right-to-Left Pass :
Similarly, the algorithm iterates through s in reverse using another for loop.
Like the left-to-right pass, it performs constant-time operations during each iteration.
Time Complexity: O(n).
Total Time Complexity :
Best Case: O(n), when the string is already balanced, and no imbalance is detected early.
Worst Case: O(n), as the algorithm must iterate through the entire string in both passes.

** Space Complexity :- **

In-Place Computation :
The algorithm uses a few integer variables (balance, loop counters) to keep track of calculations.
It does not allocate any additional data structures like arrays, stacks, or hash maps.
Space Complexity: O(1).
Input Strings :
The input strings s and locked are accessed but not modified, so they do not contribute to additional space usage.
Space Complexity: O(1).
Total Space Complexity :
Best Case: O(1), since only a constant amount of memory is used.
Worst Case: O(1), as the memory usage does not grow with the size of the input.
