**Leetcode Problem 14:-**

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". 

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

**Code:-**

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

**Time Complexity:**
The time complexity is O(n⋅m), where: n is the number of strings in the strs vector.m is the length of the shortest string in strs.
Each iteration of the outer loop (over strs) compares the current prefix s with the next string in strs character-by-character until a mismatch is found or one of the strings ends.
In the worst case, we compare up to m characters for each of the n−1 strings, resulting in a complexity of O(n⋅m).

**Space Complexity:**
The space complexity is O(1), since we only use a fixed amount of extra space to store the current prefix (s) and temporary variables (k and j). 
No additional data structures are used that grow with the input size.
