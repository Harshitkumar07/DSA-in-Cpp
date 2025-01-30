** Leetcode Problem 6 :- **

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"

** Code :- **

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;
        string ans;
        int cycleLen = 2 * numRows - 2;
        for (int row = 0; row < numRows; ++row) {
            for (int j = 0; j + row < s.size(); j += cycleLen) {
                ans += s[j + row];
                if (row != 0 && row != numRows - 1 &&
                    j + cycleLen - row < s.size()) {
                    ans += s[j + cycleLen - row];
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Outer Loop: Iterating Over Rows :
The algorithm iterates through numRows, which is at most O(n). 
Inner Loop: Processing Characters
For each row, it iterates over the string s, but characters are accessed directly, so there are no unnecessary operations.
Since each character is visited at most once, the overall complexity remains: O(n)
Total Time Complexity :
Best Case: O(n) if numRows = 1, the function returns s directly.
Worst Case: O(n) since all characters are iterated through exactly once.

** Space Complexity :- **
    
Storage for the Answer String :
The algorithm constructs a new string ans, which stores all n characters of s.
No Extra Data Structures :
The algorithm uses only a few integer variables (cycleLen, row, j), which take constant space.
Total Space Complexity :
Best Case: O(n) for storing the output string.
Worst Case: O(n) since the final result has the same length as s.
