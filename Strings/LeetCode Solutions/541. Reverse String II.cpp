** Leetcode Problem 541:- **

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
If there are fewer than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"

** Code :- **

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i = i + k + k) {
            int j = i, x = j + k - 1;
            while (j <= x) {
                if (x > len - 1) {
                    x = len - 1;
                }
                swap(s[j++], s[x--]);
            }
        }
        return s;
    }
};

** Time Complexity :- **

Outer Loop:
The loop increments i by 2k in each iteration. For a string of length len, the number of iterations is approximately ⌈ 2k len⌉.
Inner Reversal:
In each iteration of the outer loop, a maximum of k characters are reversed. Each reversal operation involves swapping, which is O(k).
Since every character in the string is processed at most once, the total time complexity is linear:
Time Complexity: O(len)

**Space Complexity :- **

In-Place Reversal:
The algorithm modifies the string directly without using extra storage for another data structure. Only a few variables are used for indices and temporary storage during swaps.
Overall Space Complexity: O(1)
