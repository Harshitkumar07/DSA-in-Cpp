** Leetcode Problem 28 :- **

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

** Code :- **

class Solution {
public:
    int strStr(string haystack, string needle) {
        int s1 = haystack.size(), s2 = needle.size();
        for (int i = 0; i <= s1 - s2; i++) {
            if (haystack.substr(i, s2) == needle) {
                return i;
            }
        }
        return -1;
    }
};

** Time Complexity :- **
    
Outer Loop:
The loop runs from i=0 to s1−s2, where s1 is the length of haystack and s2 is the length of needle. This results in at most s1−s2+1 iterations.
Substring Comparison:
For each iteration of the loop, the substr method extracts a substring of length s2 from haystack and compares it with needle. The substr operation takes O(s2) time to extract, and the string comparison also takes O(s2) in the worst case.
Total Comparisons:
In the worst case, the substr and comparison operations are performed s1−s2+1 times, resulting in a total time complexity of: O((s1−s2+1)⋅s2)
Simplified: O(s1⋅s2)

** Space Complexity :- **

Auxiliary Space:
The substr method creates a new substring of length s2 for each iteration. In the worst case, up to s1−s2+1 substrings are created. However, only one substring exists in memory at any given time, requiring O(s2) space.
Input Space:
No additional space is required for the input strings haystack and needle.
Total Space Complexity: O(s2)
