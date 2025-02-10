** Leetcode Problem 1221 :- **

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
Given a balanced string s, split it into some number of substrings such that:
Each substring is balanced.
Return the maximum number of balanced strings you can obtain.

Example 1:
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Example 2:
Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.

Example 3:
Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

** Code :- **

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, cntLeft = 0, cntRight = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') {
                cntRight++;
            } else {
                cntLeft++;
            }
            if (cntRight == cntLeft) 
                count++;
        }
        return count;
    }
};

** Time Complexity :- **
    
Iterating Through the String :
The for loop iterates through all characters of the string s, which has length n.
Each character is processed in O(1) time, updating counters.
Counting Operations :
The counters cntLeft and cntRight are incremented based on character type.
When both counters become equal, count is incremented.
All operations inside the loop run in O(1) time per iteration.
Total Time Complexity :
The loop runs O(n) times, with all operations inside being O(1).
Worst-case complexity: O(n).

** Space Complexity :- **

In-Place Computation :
Only a few integer variables (count, cntLeft, cntRight) are used.
No extra data structures are allocated.
Total Space Complexity :
Since the function uses only a few variables, the space complexity is O(1).
