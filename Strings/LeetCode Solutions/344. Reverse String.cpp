** Leetcode Problem 344 :- **

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

** Code :- **

class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of(vowels, i);
            j = s.find_last_of(vowels, j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};


** Time Complexity :- **

Finding the Next Vowel:
The find_first_of function scans the string from the current index i to find the next vowel, and find_last_of scans the string backward from index j for the previous vowel.
In the worst case, every character is scanned once during each call to find_first_of and find_last_of, meaning each character is examined at most twice across the string.
This results in O(n) complexity for the vowel search operations, where n is the length of the string.
Swapping Characters:
Each swap operation takes O(1), and swaps are performed at most n/2 times (since each swap involves two characters). This contributes O(n).
Total Time Complexity:
The operations of finding vowels and swapping them both sum to: O(n)

** Space Complexity :- **

Input String:
The input string is modified in place, so no additional space is required for storage.
Vowel List (vowels):
The string "aeiouAEIOU" contains 10 characters and uses O(1) space as it is constant.
Auxiliary Variables:
Variables i, j, and the temporary space for swapping take O(1).
Total Space Complexity:
The algorithm uses constant space: O(1)
