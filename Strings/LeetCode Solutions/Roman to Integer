** Leetcode Problem 13 :- **

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

** Code :- **

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int result = 0,n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }
        return result;
    }
};

** Time Complexity :- **

Traversal of String:
The for loop iterates through each character of the input string s, which has a size n.
Therefore, the traversal takes O(n).
Map Access:
Each access to the romanMap (e.g., romanMap[s[i]]) is an O(1) operation because unordered_map provides average-case constant-time lookups.
Conditional Check and Operations:
The comparison romanMap[s[i]]<romanMap[s[i+1]] and the arithmetic operations (addition or subtraction) inside the loop are O(1).

Total Time Complexity: O(n)
The algorithm processes each character of the string once, resulting in linear time complexity.

** Space Complexity :- **

Auxiliary Space:
The unordered_map romanMap is a fixed-size data structure containing mappings for 7 Roman numerals. Its space requirement is constant: O(1)
Output Space:
The integer result is used to store the final value and occupies O(1) space.
Input Space:
The input string s is given as a parameter, and no additional space is allocated for it within the function.

Total Space Complexity: O(1)
The algorithm uses constant additional space regardless of the input size.
