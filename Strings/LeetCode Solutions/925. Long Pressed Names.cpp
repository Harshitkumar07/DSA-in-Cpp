** Leetcode Problem 925:- **

Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.

** Code :- **

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i < name.size() && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == name.size();
    }
};

** Time Complexity :- **
    
Two-Pointer Traversal :
The function uses two pointers (i and j) to traverse the name and typed strings.
Pointer j iterates through the entire typed string, and pointer i iterates through name based on matches.
In the worst case, the entire typed string is traversed.
Time Complexity: O(m), where m is the length of the typed string.
Character Comparisons :
Each character in typed is compared to either the corresponding character in name or its previous character in typed.
The number of comparisons is proportional to the length of typed.
Time Complexity: O(m).
Total Time Complexity :
Best Case: O(m), when every character in typed matches name without extra long presses.
Worst Case: O(m), when typed contains many repeated characters not matching name.

** Space Complexity :- **
    
In-Place Processing :
The function uses two integer variables (i and j) to traverse the strings and no additional data structures.
Space Complexity: O(1).
Temporary Variables :
A few temporary variables for indices (i, j) and comparisons are used.
These require constant space.
Space Complexity: O(1).
Total Space Complexity : O(1), as no extra memory is allocated other than the two pointers.
