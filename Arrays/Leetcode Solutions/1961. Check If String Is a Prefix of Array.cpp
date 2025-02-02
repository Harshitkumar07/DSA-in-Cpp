** Leetcode Problem 1961 :- **

Given a string s and an array of strings words, determine whether s is a prefix string of words.
A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.
Return true if s is a prefix string of words, or false otherwise.

Example 1:
Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Explanation:
s can be made by concatenating "i", "love", and "leetcode" together.

Example 2:
Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
Explanation:
It is impossible to make s using a prefix of arr.

** Code :- **

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans;
        for (int i = 0; i < words.size(); i++) {
            ans = ans + words[i];
            if (ans == s) {
                return true;
            }
        }
        return false;
    }
};

** Time Complexity :- **

Concatenation and Comparison :
The algorithm iterates through words, appending each string to ans and checking if it matches s.
Let n be the length of s and m be the total length of all strings in words.
In the worst case, all strings are concatenated before a match is found or the loop ends.
Each concatenation takes O(k), where k is the length of the added word. 
O(m) since the total number of characters processed is at most m.

Total Time Complexity :
Best Case: O(1) if the first few words form s.
Worst Case: O(m) if all words are concatenated and no match is found.

** Space Complexity :- **

String Storage ans stores a growing substring of s, requiring up to O(n) space.
The input words is given and not modified, so no extra storage is used.
Total Space Complexity :
Best Case: O(1) if a match is found early.
Worst Case: O(n) if the entire prefix must be stored before determining a mismatch.
