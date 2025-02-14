** Leetcode Problem 5:- **

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

** Code :- **

class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int slen = s.length();
        for (int i = 0; i < 2 * slen -1; i++) {
            int left = i / 2;
            int right = left + i % 2;
            while (left >= 0 && right < slen && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > ans.length()) {
                ans = s.substr(left + 1, right - left - 1);
            }
        }
        return ans;
    }
};

** Time Complexity: **
The time complexity is O(n^2), where n is the length of the string s.The main loop iterates 2n−1 times because it considers each character and each "gap" between characters as potential centers for palindromes.
For each center, we expand outwards to check for the longest palindrome. In the worst case, this expansion can take O(n) time if the palindrome spans the entire string.
Thus, the total time complexity is O(n×n)=O(n^2).

** Space Complexity: **
The space complexity is O(1) for auxiliary space, since we use only a fixed number of variables (ans, slen, left, and right). 
However, the function does return a substring, so the actual space complexity for the output is O(n) if we consider the returned palindrome string.
