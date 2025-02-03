** Leetcode Problem 3340 :- **

You are given a string num consisting of only digits. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of digits at odd indices.
Return true if num is balanced, otherwise return false.

Example 1:
Input: num = "1234"
Output: false
Explanation:
The sum of digits at even indices is 1 + 3 == 4, and the sum of digits at odd indices is 2 + 4 == 6.
Since 4 is not equal to 6, num is not balanced.

Example 2:
Input: num = "24123"
Output: true
Explanation:
The sum of digits at even indices is 2 + 1 + 3 == 6, and the sum of digits at odd indices is 4 + 2 == 6.
Since both are equal the num is balanced.

** Code :- **

class Solution {
public:
    bool isBalanced(string num) {
        int odd = 0, even = 0;
        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            if (i % 2)
                odd += digit;
            else
                even += digit;
        }
        return even == odd;
    }
};

** Time Complexity :- **

Breaking Down the Iteration
The function iterates through the entire string num once using a for loop.
Inside each iteration:
Extracting a digit (num[i] - '0'): O(1)
Checking if the index is odd or even: O(1)
Adding the digit to the odd or even sum: O(1)
Since the loop runs n times (where n is the length of num), the total time complexity is: O(n)
Best Case Complexity :
O(n) in all cases, since every digit must be processed.
Worst Case Complexity :
O(n), even if an imbalance is found early, as the function must compute both sums before making a comparison.

** Space Complexity :- **
    
In-Place Computation :
The function only uses a few integer variables:
odd → Stores the sum of digits at odd indices.
even → Stores the sum of digits at even indices.
digit → Stores the extracted digit.
i → Loop counter.
No extra data structures (arrays, hash maps, etc.) are used.
The function does not modify the input string num.
Total Space Complexity O(1)
Memory usage remains constant, irrespective of the length of num.
Best Case Complexity O(1)
Since only a fixed number of variables are used.
Worst Case Complexity O(1) 
The space used does not increase with n.
