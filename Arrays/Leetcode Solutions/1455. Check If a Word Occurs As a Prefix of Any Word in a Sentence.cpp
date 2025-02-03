** Leetcode Problem 1455 :- **

Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.
Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word.
If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

Example 2:
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.

Example 3:
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.

** Code :- **

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), s = searchWord.length();
        int idx = 1, i = 0;
        while (i < n) {
            while (i < n && sentence[i] == ' ') {
                i++;
            }
            int start = i;
            while (i < n && sentence[i] != ' ') {
                i++;
            }
            if (i - start >= s && sentence.substr(start, s) == searchWord) {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};

** Time Complexity :- **
    
Parsing Words :
The algorithm scans sentence character by character, skipping spaces and identifying words.
Let n be the length of sentence and s be the length of searchWord.
The while loops ensure each character is processed once.
Substring Check :
The function sentence.substr(start, s) == searchWord extracts a substring of length s and compares it with searchWord, taking O(s) time.
This operation is performed at most O(n/s) times in the worst case.
Total Time Complexity :
Best Case: O(n) if searchWord is found early.
Worst Case: O(n+s) if searchWord is never found and all words are checked.

** Space Complexity :- **

In-Place Computation :
The function only uses a few integer variables (n, s, idx, i, start), all of which are O(1).
The input string sentence is accessed but not modified, so no extra space is used.
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1) since no additional space is allocated apart from variables.
