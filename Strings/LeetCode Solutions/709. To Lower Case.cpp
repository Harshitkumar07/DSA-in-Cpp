** Leetcode Problem 709 :- **

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

Example 1:
Input: s = "Hello"
Output: "hello"

Example 2:
Input: s = "here"
Output: "here"

Example 3:
Input: s = "LOVELY"
Output: "lovely"

** Code :- **

class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i <= s.length(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }
};

** Time Complexity :- **
    
Iterating Through the String :
The for loop runs from i = 0 to i <= s.length(), meaning it iterates over all characters in the string plus one extra iteration, which causes an out-of-bounds access (should be i < s.length()).
The correct version runs O(n) times, where n is the length of s.
Character Conversion :
The function tolower(s[i]) operates in O(1) time for each character.
Since it runs for all n characters, this results in O(n) operations.
Total Time Complexity :
The dominant term is O(n), so the worst-case complexity is O(n).

** Space Complexity :- **

In-Place Modification :
The function modifies s directly, meaning no additional space is used except for a few integer variables (i).
Total Space Complexity :
Since no extra data structures are used, the space complexity is O(1).
