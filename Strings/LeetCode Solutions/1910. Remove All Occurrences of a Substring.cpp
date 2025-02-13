** Leetcode Problem 1910 :- **

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.

Example 1:
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

Example 2:
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

** Code :- **

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

** Time Complexity :- **
    
Finding Substring (s.find(part)) 
The find operation searches for part in s, taking O(n) in the worst case (where n is the length of s).
Erasing Substring (s.erase(...)) 
Removing a substring of length m from s takes O(n) in the worst case, as characters need to be shifted.
While Loop Execution :
In the worst case, the loop runs O(n/m) times (where m is the length of part).
This happens when part appears frequently in s and needs to be removed iteratively.
Each iteration involves find (O(n)) and erase (O(n)), leading to O(n²/m) complexity.
Total Time Complexity :
Best Case: O(n) → If part is not found, only one find operation runs.
Worst Case: O(n²/m) → If part appears many times and needs repeated removal.

** Space Complexity :- **

In-Place String Modification :
The function modifies s directly, so no extra space is allocated apart from temporary variables.
Total Space Complexity :
Best Case: O(1) → If no modification is needed.
Worst Case: O(n) → If s undergoes multiple modifications, but no extra auxiliary space is used beyond input storage.
The overall space complexity remains O(1) since s is modified in place.
