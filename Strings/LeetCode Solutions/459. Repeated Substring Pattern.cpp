** Leetcode Problem 459 :- **

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

** Code :- **

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int len = 1; len <= n / 2; len++) {
            if (n % len == 0) {
                string repeated, str = s.substr(0, len);
                for (int j = 0; j < n / len; j++) {
                    repeated += str;
                }
                if (repeated == s) {
                    return true;
                }
            }
        }
        return false;
    }
};


** Time Complexity :- **
    
Iterating Over Possible Substring Lengths :
The outer loop runs for all possible substring lengths len from 1 to n/2.
This results in O(n/2) = O(n) iterations.
Checking If the Length Divides n :
For each len, we check if n % len == 0, which takes O(1) time.
Constructing the Repeated Substring :
If len divides n, we construct a string by repeating the first len characters (n / len) times.
Constructing the repeated string takes O(n) time since we concatenate (n / len) substrings of length len, giving a total of O(n) characters appended.
Comparing the Repeated String with Original
The string comparison repeated == s takes O(n) time.
Total Time Complexity :
The worst case occurs when we iterate up to O(n) substring lengths and construct & compare O(n) characters for each valid length.
This results in an overall worst-case complexity of O(n²).

** Space Complexity :- **

String Storage :
We use the repeated string to store repeated patterns, which takes O(n) space in the worst case.
The substring str also takes O(len) space, but since len ≤ n/2, it is O(n) in the worst case.
Total Space Complexity :
The function uses O(n) auxiliary space for storing strings, making the worst-case space complexity O(n).
