** Leetcode Problem 796 : -**

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

** Code :- **

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s.substr(i, goal.size()) == goal) {
                return true;
            }
            s.push_back(s[i]);
            i++;
        }
        return false;
    }
};

** Time Complexity :- **
    
Checking Length (O(1))
We first compare the sizes of s and goal. If they are not equal, return false in O(1).
Concatenation (O(n))
Creating s + s results in a string of size 2n.
This takes O(n) time.
Substring Search (O(n)) :
find(goal) in a 2n-length string takes O(n) in the worst case.
Total Time Complexity : O(n)
Best Case: goal is found early → O(1)
Worst Case: goal is checked in O(n) time.
    
** Space Complexity :- **
    
Extra Space :
We create a new string of size 2n, making the space complexity O(n).
Total Space Complexity : O(n)
