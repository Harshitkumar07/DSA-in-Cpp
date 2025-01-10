** Leetcode Problem 557 :- **

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "Mr Ding"
Output: "rM gniD"

** Code :- **

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        while (start < s.length()) {
            while (end < s.length() && s[end] != ' ') {
                end++;
            }
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            end = start;
        }
        return s;
    }
};

** Time Complexity :- **
    
Outer Loop (Traversing Words) : 
The start and end pointers traverse the string s to identify words delimited by spaces.
This traversal goes through each character of s exactly once.
Time Complexity: O(n), where n is the length of s.
Reversing Words :
For each word found, the reverse function is called.
The reverse operation has a complexity proportional to the length of the word.
The total time spent reversing all words is at most O(n) because the sum of the lengths of all words equals n.
Best Case :
If s contains only one word or is already reversed, the operations still traverse the entire string but reverse only one word.
Best-Case Time Complexity: O(n).
Worst Case :
If s contains many short words separated by spaces, the traversal and reversal still involve O(n).
Worst-Case Time Complexity: O(n).
Total Time Complexity :
Best Case: O(n).
Worst Case: O(n).

** Space Complexity :- **

In-Place Operations :
The function modifies the string s directly without allocating additional storage for intermediate results.
The reverse function operates in place, requiring no extra space.
Pointer Storage :
Two integer variables (start and end) are used to track positions in the string.
These require O(1) space.
Best and Worst Cases :
Both cases use the same constant space for pointers and in-place modifications.
Total Space Complexity :
Best Case: O(1).
Worst Case: O(1).
