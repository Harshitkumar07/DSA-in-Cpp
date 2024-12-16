** Leetcode Problem 125 :- **

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

** Code :- **

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string ans;
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                ans.push_back(char(tolower(s[i])));
            }
        }
        for (int i = 0; i < ans.length(); i++) {
            if (ans[i] != ans[ans.length() - i - 1])
                return false;
        }
        return true;
    }
};

** Time Complexity :- **
    
Processing the String:
The algorithm iterates over the input string s of length n once, checking whether each character is alphanumeric and converting it to lowercase if necessary. This step takes O(n).
Palindrome Check:
After constructing the filtered string ans, the algorithm compares its characters symmetrically from the beginning and the end. This takes O(k), where k is the length of the filtered string ans, and k≤n.
Total Time Complexity: (n)
    
** Space Complexity :- **
    
String Storage:
A new string ans is created to store the filtered alphanumeric characters. In the worst case, if all characters of s are alphanumeric, the space used is O(n).
Auxiliary Variables:
A constant amount of space is used for loop variables and comparisons.
Total Space Complexity: O(n)
