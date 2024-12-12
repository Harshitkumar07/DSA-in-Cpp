** Leetocde Problem 3:- **

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

** Code :- **

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxLen = 0, start = 0;
        for (int end = 0; end < s.size(); end++) {
            while (seen.count(s[end])) {
                seen.erase(s[start]);
                start++;
            }
            seen.insert(s[end]);
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};

** Time Complexity: **

Outer Loop: The outer loop runs from 0 to s.size() - 1, which means it runs n times, where n is the length of the string s. This loop has a time complexity of O(n).
Inner While Loop: The inner while loop runs until the character s[end] is not found in the seen set.
In the worst case, this loop can run up to n times, but it's not a separate loop that runs n times.
Instead, it's a loop that runs a total of n times across all iterations of the outer loop.
Total Iterations: Since the inner while loop runs a total of n times across all iterations of the outer loop, and the outer loop runs n times. 
The total number of iterations is n + n = 2n, which simplifies to O(n).
Operations Inside Loops: Inside the loops, there are constant-time operations such as seen.erase(s[start]), start++, seen.insert(s[end]), and maxLen = max(maxLen, end - start + 1).
These operations do not affect the overall time complexity.
Overall Time Complexity: Since the total number of iterations is O(n), and the operations inside the loops are constant-time, the overall time complexity is O(n).

** Space Complexity: **

Hash Set: The algorithm uses an unordered set seen to store unique characters from the string s.
In the worst case, the size of the seen set will be equal to the number of unique characters in the string s.
Size of Hash Set: If the string s contains all unique characters, the size of the seen set will be equal to the length of the string s, which is n. 
However, if the string s contains duplicate characters, the size of the seen set will be less than n.
Size of Character Set: 
In the worst case, the size of the seen set will be equal to the size of the character set, which is typically 256 for ASCII characters or 65536 for Unicode characters.
Auxiliary Space: The algorithm uses O(1) additional space for variables such as maxLen, start, and end.
Overall Space Complexity: Since the hash set requires O(min(n, m)) space, where n is the length of the string s and m is the size of the character set, and the auxiliary space is O(1). 
The overall space complexity is O(min(n, m)) + O(1) = O(min(n, m)).
