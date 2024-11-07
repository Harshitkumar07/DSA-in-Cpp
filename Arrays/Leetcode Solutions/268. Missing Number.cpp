**Leetcode Problem 268:-**

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

**Code:-**
    
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int ans;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }
        ans = n * (n + 1) / 2 - sum;
        return ans;
    }
};

**Time Complexity:**
The time complexity is O(n) because we iterate through the nums array once to calculate the sum of its elements. Calculating the expected sum using the formula n×(n+1)/2 is an O(1) operation. 
Thus, the total time complexity is dominated by the single loop, resulting in O(n).

**Space Complexity:**
The space complexity is O(1) because we only use a fixed amount of extra space for variables (sum, n, and ans).
No additional data structures are used, and memory usage does not scale with the input size.
