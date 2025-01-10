** Leetcode Problem 392 :- **

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

** Code :- **

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};

** Time Complexity :- **
    
Two-Pointer Traversal :
The function uses two pointers (i for string s and j for string t) to traverse both strings.
The loop continues until either pointer reaches the end of its respective string.
In the worst case, all characters of t are traversed, resulting in O(length of t).
The pointer i for s only increments when a match is found, leading to at most O(length of s) comparisons.
Best Case :
If s is empty, the function returns immediately with O(1) as no iteration is required.
Alternatively, if all characters of s are found at the very beginning of t, the traversal of t terminates early.
Worst Case :
If s matches only the last characters of t, the entire string t is traversed.
Time complexity is O(length of t).
Total Time Complexity :
Best Case: O(1) if s is empty or terminates early.
Worst Case: O(length of t).

** Space Complexity :- **

Pointer Storage :
The function uses two integer variables (i and j) to keep track of indices. These require O(1) space.
No Additional Storage :
The function does not allocate additional data structures, and it operates directly on the input strings.
Best and Worst Cases :
Both best-case and worst-case scenarios utilize the same constant space.
Total Space Complexity :
Best Case: O(1).
Worst Case: O(1).
