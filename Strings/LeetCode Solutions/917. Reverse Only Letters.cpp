** Leetcode Problem 917:- **

Given a string s, reverse the string according to the following rules:
All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:
Input: s = "ab-cd"
Output: "dc-ba"

Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

** Code :- **

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
            }
            else if (!isalpha(s[j])) {
                j--;
            } else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

** Time Complexity :- **
    
Two-Pointer Traversal :
The function uses two pointers (i and j) to traverse the string.
Both pointers move towards each other, processing each character at most once.
Characters that are not alphabetic (!isalpha(s[i]) or !isalpha(s[j])) are skipped, but the traversal still requires O(n), where n is the length of the string.
Time Complexity: O(n).
Character Swapping :
When both pointers point to alphabetic characters, a swap operation is performed.
The number of swaps is proportional to the number of alphabetic characters, which is at most n.
Time Complexity: O(1) per swap, contributing O(n) overall.
Total Time Complexity :
Best Case: O(n), even if the string contains no or very few alphabetic characters (due to traversal).
Worst Case: O(n), if the string consists entirely of alphabetic characters.

** Space Complexity :- **
    
In-Place Operations :
The function modifies the string s in place using two pointers.
No additional memory is allocated for intermediate data structures.
Space Complexity: O(1).
Temporary Variables :
A few integer variables (i, j) and one or two temporary variables during swapping are used.
These require constant space.
Space Complexity: O(1).
Total Space Complexity : O(1), as the operations are performed in place with minimal auxiliary storage.
