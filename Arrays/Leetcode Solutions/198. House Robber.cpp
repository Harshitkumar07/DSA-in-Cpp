** Leetcode Problem 198 :- **

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police. 
If two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12

** Code :- **

class Solution {
public:
    int rob(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        if (nums.size() == 0) {
            return 0;
        }
        for (int num : nums) {
            int temp = sum1;
            sum1 = max(sum2 + num, sum1);
            sum2 = temp;
        }
        return sum1;
    }
};

** Time Complexity :- **
    
Iterating through the array:
The algorithm loops through the nums array once, performing constant-time operations in each iteration.
This results in a time complexity of O(n), where n is the size of the array.
Overall Time Complexity: O(n)
    
** Space Complexity :- **
    
The algorithm uses only two integer variables (sum1 and sum2) for dynamic programming instead of creating an auxiliary array.
Overall Space Complexity: O(1)
