** Leetcode Problem 1790 :- **

You are given two strings s1 and s2 of equal length.
A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.

** Code :- **

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;
        int left = 0, right = s1.size() - 1;
        while (s1[left] == s2[left]) {
            left++;
        }
        while (s1[right] == s2[right]) {
            right--;
        }
        swap(s2[right], s2[left]);
        return s1 == s2;
    }
};

** Time Complexity :- **
    
Comparing Strings Directly :
The first check if (s1 == s2) takes O(n) in the worst case, where n is the length of s1 and s2.
Finding Mismatched Indices :
The two while loops iterate over s1 and s2 to find mismatched positions (left and right).
Each loop runs at most O(n) times in the worst case.
Swapping Characters and Final Comparison :
Swapping two characters in s2 is O(1).
The final equality check s1 == s2 takes O(n) time in the worst case.
Total Time Complexity :
The worst-case complexity is O(n) + O(n) + O(n) = O(n).
Since the dominant term is O(n), the overall time complexity is O(n).

** Space Complexity :- **
    
In-Place Modifications :
The function uses only a few integer variables (left, right) and modifies s2 in place.
Since no additional data structures are used, the space complexity is O(1).
Total Space Complexity :
The worst-case space complexity is O(1), as the function does not allocate extra memory beyond a few integer variables.
