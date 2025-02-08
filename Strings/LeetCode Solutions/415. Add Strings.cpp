** Leetcode Problem 415 :- **

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"

** Code :- **

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

** Time Complexity :- **
    
Breaking Down the Iteration :
The function iterates through the longer string (num1 or num2), performing a single pass.
The number of iterations is at most O(max(n, m)), where:
n = num1.size()
m = num2.size()
Within each iteration:
Adding digits (sum += num1[i] - '0' or num2[j] - '0') → O(1)
Pushing the result into ans → O(1)
Updating carry → O(1)
The final reverse operation takes O(max(n, m)).
Total Time Complexity : O(max(n,m))
Best Case Complexity : O(n)
When both numbers have the same length n, and there is no carry propagation beyond the original length.
Worst Case Complexity : O(n)
When the sum results in an additional digit due to carry (e.g., "999" + "1" = "1000"), requiring an extra iteration.

** Space Complexity :- **
    
Memory Usage :
The function modifies and stores the result in ans, which requires at most O(max(n, m)) space.
The carry variable and the integer sum require O(1) space.
The reverse operation is done in place.
Total Space Complexity : O(max(n,m))
Since ans stores the sum, it can at most be max(n, m) + 1 in length.
Best Case Complexity : O(n)
The result has at most n digits, and reversing is O(n).
Worst Case Complexity : O(n)
When there is an extra carry, ans grows by one extra digit (max(n, m) + 1).
