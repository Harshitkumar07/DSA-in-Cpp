** Leetcode Problem :- **

Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede"

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

Finding the Next and Previous Vowel:
find_first_of scans the string from the current index i to the next occurrence of any vowel, and find_last_of scans backward from j to the previous occurrence of any vowel.
Together, these operations ensure that each character in the string is examined at most once.
Since both operations are linear in the size of the string, the overall cost for these operations is/O(n), where n is the length of the string.
Swapping Characters:
Each swap operation takes O(1), and swaps are performed at most n/2 times (since each swap involves two characters).
This adds up to O(n) for all swaps.
Total Time Complexity: O(n)

** Space Complexity :- **

Input String:
The input string is modified in place, so no additional space is needed for storing a copy.
Vowel List (vowels):
The string "aeiouAEIOU" is a constant and uses O(1) space.
Auxiliary Variables:
Variables i, j, and the temporary storage for swapping take (1) space.
Total Space Complexity: O(1)
