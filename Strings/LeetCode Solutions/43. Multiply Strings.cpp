** Leetcode Problem 43 :- **

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

** Code :- **

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0"){
            return "0";
        }
        int n1 = num1.size(), n2 = num2.size();
        vector<int> ans(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0') + ans[i + j + 1] + carry;
                carry = mul / 10;
                ans[i + j + 1] = mul % 10;
            }
            ans[i] += carry;
        }
        string result;
        int i = 0;
        while (i < ans.size() && ans[i] == 0) {
            i++;
        }
        for (; i < ans.size(); i++) {
            result.push_back(ans[i] + '0');
        }
        return result;
    }
};

** Time Complexity :- **
    
Outer Loop (Iterating Over num1):
The first loop iterates through each digit of num1, so it runs O(n1) times, where n1 is the length of num1.
Inner Loop (Iterating Over num2):
For each digit in num1, the inner loop iterates through each digit of num2, contributing O(n2), where n2 is the length of num2.
Operations Inside the Loop:
The multiplication, addition, and updating of the ans vector take O(1) time.
Overall Time Complexity: O(n1×n2)
This is because we compute the product of every pair of digits in num1 and num2.

** Space Complexity :- **
    
Output Storage (ans Vector):
The ans vector has a size of n1+n2 to store the product of two numbers of lengths n1 and n2
Temporary Variables:
Variables such as carry, mul, and indices use O(1) space.
Overall Space Complexity: O(n1+n2)
This is the space required to store the intermediate and final results of the multiplication. The algorithm operates directly on this vector, avoiding additional space usage.
