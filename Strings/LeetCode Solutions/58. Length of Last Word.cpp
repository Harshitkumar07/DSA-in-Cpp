** Leetocde Problem 58 :- **

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

** Code :- **

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 1) {
            return 1;
        }
        int length = 0;
        int i = s.size() - 1;
        while (s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};

** Time Complexity :- **
    
Trailing Space Removal:
The first while loop skips over trailing spaces in the string s. In the worst case, it will iterate through the entire string if it contains only spaces, taking O(n), where n is the length of s.
Last Word Length Calculation:
The second while loop iterates backward through the last word of s. In the worst case (if there are no spaces), it will also iterate through the entire string, taking O(n).
Total Time Complexity: O(n)
    
** Space Complexity :- **
    
Auxiliary Variables:
The algorithm uses a constant number of variables (length, i), which requires O(1) space.
Total Space Complexity: O(1)
