** Leetcode Problem 2108 :- **

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.

** Code :- **

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int left = 0, right = 0;
        for (const string& str : words) {
            left = 0, right = str.length() - 1;
            while (str[left++] == str[right--]) {
                if (left >= right) {
                    return str;
                }
            }
        }
        return "";
    }
};

** Time Complexity :- **
    
Checking Each Word :
The algorithm iterates through each word in the words vector.
For each word, it checks whether it is a palindrome by comparing characters from both ends.
In the worst case, each character in the word is compared once.
Time Complexity: O(m) where m is the length of the current word.
Iterating Through the Words List
The algorithm processes each word in the list once.
Time Complexity: O(n) where n is the number of words.

Total Time Complexity :
Best Case: O(m) if the first word is a palindrome.
Worst Case: O(n⋅m) if all words are checked.

** Space Complexity :- **
    
In-Place Comparisons :
The algorithm uses only a few integer variables (left and right) for comparison, without extra storage.
Space Complexity: O(1)
Total Space Complexity :
Best Case: O(1) as no additional space is allocated.
Worst Case: O(1) since memory usage remains constant.
