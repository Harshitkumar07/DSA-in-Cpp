** Leetcode Problem 20 :- **

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

** Code :- **

class Solution {
public:
    bool isValid(string s) {
        stack<char> copy;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                copy.push(ch);
            } else {
                if (!copy.empty()) {
                    char top = copy.top();
                    if ((ch == '}' && top == '{') || (ch == ')' && top == '(') ||
                        (ch == ']' && top == '[')) {
                        copy.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return copy.empty() ? true : false;
    }
};

** Time Complexity :- **
    
Iteration over the String :
The function iterates through all characters in the string s of length n.
Complexity: O(n)
This is consistent for both the best and worst cases since all characters must be examined to determine validity.
Stack Operations :
Push Operation: For each opening bracket (, {, [, the function pushes the character onto the stack.
Pop Operation: For each closing bracket ), }, ], the function checks the top of the stack and pops it if there’s a match.
Both push and pop operations are O(1), and in the worst case, every character in the string is either pushed or popped once.
Total Stack Operations: O(n)
Total Time Complexity :
Best Case: O(n)
This occurs when the input string is empty, or all pairs of brackets match without needing backtracking.
Worst Case: O(n)
This occurs when the string is long and either balanced or unbalanced, as all characters are still processed.

** Space Complexity :- **
    
Stack Usage : 
The stack stores at most n characters in the worst case, when all characters are opening brackets (e.g., "(((((").
Best Case: O(1)
This occurs when the string is empty or contains only valid pairs, causing the stack to remain nearly empty.
Worst Case: O(n)
This occurs when all characters are pushed onto the stack (e.g., an input with only opening brackets).
Other Storage :
A few variables (ch, top, and copy) are used, requiring constant space: O(1)
Total Space Complexity :
Best Case:O(1)
Minimal stack usage for balanced or empty strings.
Worst Case: O(n)
Maximum stack usage for all-opening or unbalanced brackets.
