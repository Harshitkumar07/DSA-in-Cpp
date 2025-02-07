** Leetcode Problem 131 :- **

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

** Code :- **

class Solution {
public:
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
    void getAllParts(string s, vector<string>& partitions,
                     vector<vector<string>>& ans) {
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if (isPalin(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};

** Time Complexity :- **
    
Generating All Possible Partitions :
The function generates all possible palindromic partitions of the input string.
At each step, the algorithm considers all prefixes of s, checking if they are palindromes and recursively processing the remaining substring.
Palindrome Checking (isPalin function) :
isPalin(s) takes O(n) time as it reverses and compares the string.
This function is called for every partition we attempt.
Recursive Calls (getAllParts function) :
The worst case occurs when every substring is a palindrome (e.g., "aaaa").
This results in an exponential number of partitions being generated.
Since each recursive call reduces the problem size, the number of recursive calls follows a backtracking tree structure with approximately 2ⁿ nodes in the worst case.
Total Time Complexity :
The worst-case complexity is O(n * 2ⁿ), where n accounts for palindrome checking in each recursive call.

** Space Complexity :- **

Recursive Stack Space :
In the worst case, the recursion depth can reach O(n), meaning an O(n) space is used for function calls.
Storage for Results (ans) :
Since all partitions are stored, the worst case results in O(2ⁿ) partitions, each using up to O(n) space.
This contributes to O(n * 2ⁿ) space in the worst case.
Total Space Complexity :
Best Case (O(n)): If the input is already a palindrome, minimal space is used.
Worst Case (O(n * 2ⁿ)): If every substring is a palindrome, the function generates an exponential number of partitions.
