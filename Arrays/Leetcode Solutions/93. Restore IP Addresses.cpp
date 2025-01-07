** Leetcode Problem 93 :- **

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

** Code :- **

class Solution {
public:
    bool isValid(string sub) {
        if (sub.size() == 1)
            return true;
        if (sub.size() > 1 && sub[0] != '0' && stoi(sub) <= 255)
            return true;
        return false;
    }
    void dfs(vector<string>& ans, string s, string path, int i, int dots) {
        if (dots == 4) {
            if (i == s.length()) {
                path.pop_back();
                ans.push_back(path);
            }
            return;
        }
        for (int k = 1; k <= 3; k++) {
            if (i + k <= s.length() && isValid(s.substr(i, k))) {
                dfs(ans, s, path + s.substr(i, k) + '.', i + k, dots + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string path;
        dfs(ans, s, path, 0, 0);
        return ans;
    }
};

** Time Complexity :- **
    
Recursive Backtracking :
At each recursive step, the function tries to place a dot after 1, 2, or 3 characters.
For a string of length n, there are at most 34=81 possible combinations of dots to form 4 valid parts (since at most 3 characters can belong to each segment).
For each combination, it checks the validity of the current segment using isValid, which operates in O(k), where k is the segment length (at most 3).
Worst Case :
The function explores all O(34)=O(81) potential ways to place the dots. For each valid segmentation, the isValid function processes up to 12 characters (entire string): 
O(81⋅12)=O(972)≈O(1) for small constant values.
Best Case :
If the input string is invalid early (e.g., too short or too long to form an IP address), the recursion terminates quickly without exploring all paths.
This would result in fewer recursive calls.
Total Time Complexity :
Best Case: O(1), when the string is invalid.
Worst Case: O(81) = O(1) \text{ for small \( n values.} )

** Space Complexity :- **
    
Recursive Stack :
The recursion depth corresponds to the number of dots placed, which is at most 4.
Space Used by Recursive Stack: O(4)=O(1)
Storage for Results (ans) :
The vector ans stores all valid IP addresses. The number of valid IP addresses is a function of the input string and depends on its structure, but in the worst case, there can be O(81) results.
Each IP address requires O(n) space to store.
Space Used for ans: O(81⋅n)≈O(n)
Temporary Strings (path) :
The path string accumulates characters during recursive calls, requiring at most O(n) space.
Total Space Complexity :
Best Case: O(1), when no valid IP addresses are found.
Worst Case: O(n), dominated by the storage of results.
