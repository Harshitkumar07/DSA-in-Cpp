** Leetcode Problem 1392:- **

A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

** Code :- **

class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);
        int i = 1, len = 0;
        while (i < s.size()) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, lps[s.size() - 1]);
    }
};

** Time Complexity :- **
    
LPS Array Construction :
The while loop iterates through the string s to compute the Longest Prefix Suffix (LPS) array.
For each character s[i], the algorithm either increments i or adjusts len using the values in the LPS array.
Each character is processed at most twice: once when compared and possibly again when len is updated.
Time Complexity: O(n), where n is the length of s.
Substring Extraction :
The function extracts a substring using s.substr(0, lps[s.size() - 1]).
Substring extraction has a time complexity of O(k), where k is the length of the extracted substring. Since k≤n, this step is bounded by O(n).
Total Time Complexity :
Best Case: O(n) (all characters match early or mismatch quickly).
Worst Case: O(n) (LPS array requires full iterations).

** Space Complexity :- **
    
LPS Array : The algorithm constructs an LPS array of size n.
Space Complexity: O(n).
Variables :
The algorithm uses a few integer variables (i, len) and does not allocate additional memory proportional to the input size.
Space Complexity: O(1).
Total Space Complexity : O(n), dominated by the LPS array.
