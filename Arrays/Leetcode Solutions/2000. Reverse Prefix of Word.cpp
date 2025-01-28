** Leetcode Problem 2000 :- **

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). 
If the character ch does not exist in word, do nothing.
For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

Example 1:
Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".

Example 2:
Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".

Example 3:
Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".

** Code :- **

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                int j = 0;
                while (j < i)
                    swap(word[j++], word[i--]);
                break;
            }
        }
        return word;
    }
};

** Time Complexity :- **
    
Single Iteration Through the String :
The algorithm iterates through the string word to find the first occurrence of the character ch.
In the worst case, it scans the entire string.
Time Complexity:
O(n) where n is the length of the string.
Prefix Reversal :
If the character ch is found, the prefix of the string (up to the first occurrence of ch) is reversed.
The reversal operation involves swapping characters, which takes O(k), where k is the index of ch in the string.
Since k≤n, this step is bounded by O(n).
Total Time Complexity :
Best Case: O(n) if ch is found early or does not exist in the string.
Worst Case: O(n) as the entire string is scanned and a prefix reversal is performed.

** Space Complexity :- **
    
In-Place Computation :
The algorithm modifies the string word in place, without using any additional data structures.
It uses a few integer variables (i and j) for indexing.
Space Complexity: O(1)
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1) since the memory usage remains constant regardless of input size.
