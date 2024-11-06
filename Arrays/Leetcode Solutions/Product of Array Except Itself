**Leetcode Problem 238:-**
    
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
    
**Code:-**

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Multiply prefix and suffix except that index
        int n = nums.size();
        vector<int> ans(n, 1);
        //prefix >= ans , prefix in stored directly in ans
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }
        return ans;
    }
};

**Time Complexity:**
The time complexity is O(n) because we iterate over the nums array twice:
In the first loop, we calculate the prefix product for each element and store it in ans.
In the second loop, we calculate the suffix product for each element and multiply it with the corresponding value in ans.
Each loop goes through the array once, resulting in a total time complexity of O(n)+O(n)=O(n).

**Space Complexity:**
The space complexity is O(1) in terms of auxiliary space (excluding the output array) because we only use a single variable, suffix, for calculations in the second loop.
However, since the output array ans is required by the problem, we consider it part of the output rather than extra space. 
Therefore, the auxiliary space complexity is O(1), while the total space requirement, including ans, is O(n).
