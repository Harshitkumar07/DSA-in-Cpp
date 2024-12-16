** Leetcode Problem 67:- **

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

** Code :- **

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0, i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};

** Time Complexity :- **
    
Binary Addition:
The algorithm iterates over the longer of the two strings a and b, processing one character at a time from right to left. 
If m is the length of a and n is the length of b, the loop runs O(max(m,n)) times.
String Reversal:
After constructing the result in reverse order, the algorithm reverses the string ans, which takes O(k), where k is the length of the resulting binary sum. In the worst case, k=max(m,n)+1 (to account for an additional carry bit).
Total Time Complexity: O(max(m,n))
    
** Space Complexity :- **
    
String Storage:
The result ans requires O(k) space, where k=max(m,n)+1.
Auxiliary Variables:
A constant amount of space is used for carry and index variables i and j.
Total Space Complexity: O(max(m,n))
