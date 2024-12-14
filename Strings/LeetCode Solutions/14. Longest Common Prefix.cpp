** Leetcode Problem 14 :- **

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
    
Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

** Code :- **

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int k = 0, j = 0;
            while (k < s.size() || j < strs[i].size()) {
                if (s[k] == strs[i][j]) {
                    k++;
                    j++;
                } else {
                    s = strs[i].substr(0, j);
                    break;
                }
            }
        }
        return s;
    }
};

** Time Complexity :- **
    
Outer Loop:
The algorithm iterates through the array of strings strs starting from the second string to the end. If the array has n strings, the outer loop runs n−1 times.
Inner Loop (Finding Common Prefix):
For each pair of strings (current prefix s and the next string in the array), the algorithm compares characters until a mismatch is found or the shorter string is exhausted.
In the worst case, this loop compares all characters of the shortest string among the n strings. Let the length of the shortest string be m.
Total Comparisons:
For n strings, each with at most m characters in common, the total number of character comparisons across all iterations is: O(n⋅m)
Final Time Complexity: (n⋅m)
    
** Space Complexity :- **
    
Auxiliary Space:
The variable s holds the current longest common prefix and is updated iteratively. At most, it is equal to the length of the shortest string m. The space requirement for s is: O(m)
Input Space:
The input array strs is not modified or copied, so no additional space is allocated for the input.
Total Space Complexity: O(m)
