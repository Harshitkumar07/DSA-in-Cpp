** Leetcode Problem 680 :- **

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false
    
** Code : -**

class Solution {
public:
    bool check(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return check(s, i + 1, j) || check(s, i, j - 1);
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};

** Time Complexity :- **
    
Outer Loop:
The outer while loop iterates over the string s from both ends towards the middle. In the worst case, this takes O(n), where n is the length of s.
Helper Function (check):
The check function runs only if a mismatch is found, checking whether the substring between indices i+1 and j or i and j−1 is a palindrome.
The check function takes O(n) in the worst case when checking nearly the entire string. Since check is called at most twice, the complexity is still O(n).
Overall Time Complexity: O(n)

** Space Complexity :- **
    
Auxiliary Space:
The algorithm uses constant space for variables i, j, and the helper function. No additional space is used proportional to the input size.
Overall Space Complexity: O(1)
