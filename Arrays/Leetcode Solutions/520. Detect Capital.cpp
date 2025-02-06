** Leetcode Problem 520 :- **

We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

** Code :- **

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char ch : word) {
            if (isupper(ch))
                count++;
        }
        if (count == word.size() || count == 0)
            return true;
        if (count == 1 && isupper(word[0]))
            return true;
        return false;
    }
};

** Time Complexity :- **
    
Counting Uppercase Letters :
The function iterates through the string word once to count uppercase letters.
Let n be the length of word.
This traversal takes O(n) time.
Checking Capitalization Rules :
After counting, the function performs O(1) conditional checks.
These involve simple comparisons and a single call to isupper(word[0]), all of which take O(1) time.
Total Time Complexity :
Best Case: O(1) if the first condition is met early.
Worst Case: O(n) if the entire string needs to be processed.

** Space Complexity :- **
    
In-Place Computation
The function only uses an integer variable count, which takes O(1) space.
No additional data structures are used.
Total Space Complexity :
Best Case: O(1) (only a few integer variables used).
Worst Case: O(1) (constant space, no extra allocations).
