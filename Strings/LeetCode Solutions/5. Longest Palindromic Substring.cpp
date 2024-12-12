** Leetcode Probelm 5:- **

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
        for (int i = 0; i < 2 * s.length() -1; i++) {
            int left = i / 2, right = left + i % 2;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
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

Outer Loop: The outer loop runs from 0 to 2 * s.length() - 1, which means it runs 2n - 1 times, where n is the length of the string s. This loop has a time complexity of O(n).
Inner While Loop: The inner while loop runs until the characters at the left and right indices are not equal.
In the worst case, this loop can run up to n times, but it's not a separate loop that runs n times.
Instead, it's a loop that runs a total of n times across all iterations of the outer loop.
Total Iterations: Since the inner while loop runs a total of n times across all iterations of the outer loop, and the outer loop runs 2n - 1 times. 
The total number of iterations is 2n - 1 + n = 3n - 1, which simplifies to O(n).
Operations Inside Loops: Inside the loops, there are constant-time operations such as left--, right++, and s[left] == s[right].
These operations do not affect the overall time complexity.
Overall Time Complexity: Since the total number of iterations is O(n), and the operations inside the loops are constant-time, the overall time complexity is O(n).

** Space Complexity: **

String ans: The algorithm uses a string ans to store the longest palindromic substring.
In the worst case, the length of ans will be equal to the length of the string s, which is n.
Auxiliary Space: The algorithm uses O(1) additional space for variables such as left, right, and i.
Overall Space Complexity: Since the string ans requires O(n) space, and the auxiliary space is O(1), the overall space complexity is O(n) + O(1) = O(n).
