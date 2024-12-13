** Leetcode Probelm 12 :- **

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:
If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol. 
For example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. 
If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

Example 1:
Input: num = 3749
Output: "MMMDCCXLIX"
Explanation:
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

Example 2:
Input: num = 58
Output: "LVIII"
Explanation:
50 = L
 8 = VIII

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation:
1000 = M
 900 = CM
  90 = XC
   4 = IV

** Code :- **

class Solution {
public:
    string intToRoman(int num) {
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
        int i = 0;
        string str;
        while (num > 0) {
            if (num >= n[i]) {
                str = str + s[i];
                num = num - n[i];
            } else {
                i++;
            }
        }
        return str;
    }
};

** Time Complexity :- **

Outer While Loop:
The loop continues until num > 0.
In each iteration, the value of num decreases by the current value in the n vector, n[i], when num≥n[i].
In the worst case (if num is large and divisible by smaller Roman numeral values), this can lead to O(min(n)num) iterations.
Given that the Roman numeral system uses fixed constants, this results in a constant number of iterations on average, 
making the overall time complexity proportional to the number of digits in the input num.
Inner Operations:
The if condition num≥n[i] and the arithmetic operations (subtracting n[i] from num and concatenating strings) are O(1).
The loop index increment i++ is also O(1).

Total Time Complexity:
The algorithm effectively processes each digit in num, so the time complexity is: O(log 10 (num))
As the number has at most a fixed range in Roman numeral representation (bounded by 3999), the worst-case time complexity remains effectively O(1) for practical purposes.

** Space Complexity :- **

Auxiliary Space:
Two constant-sized vectors, n and s, are used to store Roman numeral values and symbols.
These occupy a fixed amount of space:O(1)
Output Space:
The output string str stores the Roman numeral representation.
In the worst case (e.g., num = 3999), the output string length is proportional to the value of num in Roman numeral form, which can have at most 15 characters.
The space required for str is therefore: O(log 10 (num))
For practical inputs (e.g., bounded by 3999), this space cost is constant.

Total Space Complexity: O(1)
