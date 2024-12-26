** Leetcode Problem 567:- 

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

** Code :- **

class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        int widSize = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            int widIdx = 0, idx = i, widFreq[26] = {0};
            while (widIdx < widSize && idx < s2.length()) {
                widFreq[s2[idx] - 'a']++;
                widIdx++;
                idx++;
            }
            if (isFreqSame(freq, widFreq)) {
                return true;
            }
        }
        return false;
    }
};

** Time Complexity :- **
    
Outer Loop:
The outer loop runs over the length of string s2 (denoted as n).
Inner Loop:
For every iteration of the outer loop, the inner loop iterates over the length of s1 (denoted as m) to populate the frequency array widFreq.
Frequency Comparison (isFreqSame):
This function compares two frequency arrays of size 26. The cost of comparison is O(26), which is constant time.
Overall, the worst-case scenario involves O(n×m) operations for building frequency arrays, and each comparison costs O(1).
Total Time Complexity: O(n×m)

** Space Complexity :- **
    
Frequency Arrays:
The algorithm uses two frequency arrays, each of size 26, to store letter frequencies for s1 and the current window in s2.
Other Variables:
Uses only a few integer variables to track indices and window size.
Overall Space Complexity: O(26)=O(1)
