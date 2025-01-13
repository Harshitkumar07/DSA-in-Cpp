** Leetcode Problem 844:- **

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

** Code :- **

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            int backCounts = 0, backCount = 0;
            while (i >= 0 && (s[i] == '#' || backCounts > 0)) {
                backCounts += (s[i] == '#') ? 1 : -1;
                i--;
            }
            while (j >= 0 && (t[j] == '#' || backCount > 0)) {
                backCount += (t[j] == '#') ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j] || (i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};

** Time Complexity :- **
    
Iterating Through Strings s and t
The function uses two pointers (i and j) to traverse strings s and t backward.
Each pointer skips over characters affected by backspaces (#).
In the worst case, every character in both strings must be traversed once.
Time Complexity: O(m+n), where m is the length of s and n is the length of t.
Skipping Backspaces :
For each # in the strings, there is a corresponding backward skip.
The backspaces do not increase the number of iterations but are accounted for during traversal.
Time Complexity: O(m+n).
Total Time Complexity :
Best Case: O(m+n), when there are no backspaces, and the strings are traversed directly.
Worst Case: O(m+n), when backspaces occur frequently, requiring additional processing to skip characters.

** Space Complexity :- **
    
In-Place Processing :
The function does not use additional data structures like stacks or auxiliary strings to process the backspaces.
The two pointers (i and j) handle all operations in-place.
Space Complexity: O(1).
Temporary Variables :
A few variables (i, j, backCounts, backCount) are used for traversal and counting backspaces.
These require constant space.
Space Complexity: O(1).
Total Space Complexity : O(1), as no extra memory is allocated beyond the two pointers and counting variables.
