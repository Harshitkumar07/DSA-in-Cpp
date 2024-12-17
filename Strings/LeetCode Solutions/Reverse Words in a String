** Leetcode Problem 151 :- **

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

** Code :- **

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            string word = "";
            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

** Time Complexity :- **

Initial Reversal of the String:
The entire string s is reversed initially using reverse(s.begin(), s.end()), which takes O(n), where n is the length of the input string.

Processing Words:
The algorithm iterates through the string once to extract individual words, accumulating non-space characters into a temporary string word. 
This step also takes O(n) because every character is visited once.
Reversing Each Word:
For each word encountered, the word is reversed using reverse(word.begin(), word.end()). 
If there are k words, and the total length of all words is n, the reversal across all words cumulatively takes O(n).
Appending Words to the Result:
Each word is added to the result string ans. This step again involves O(n) operations for concatenation.
Substring Extraction:
Finally, ans.substr(1) trims the leading space. This operation takes O(n).
Total Time Complexity:
Each operation over the string cumulatively amounts to O(n)

** Space Complexity :- **

Temporary String word:
Space is used to store each individual word while processing. In the worst case, this space is O(n).
Result String ans:
The output string ans is built incrementally, requiring O(n) space.
Constant Extra Space:
Apart from ans and word, a few variables (i, s.length()) are used, which take O(1) space.
Total Space Complexity: O(n)
