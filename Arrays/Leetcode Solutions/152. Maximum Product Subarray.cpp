** Leetcode Problem 152 :- **

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

** Code :- **

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], maxEnd = nums[0], minEnd = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxEnd, minEnd);
            maxEnd = max(nums[i], maxEnd * nums[i]);
            minEnd = min(nums[i], minEnd * nums[i]);
            maxProduct = max(maxProduct, maxEnd);
        }
        return maxProduct;
    }
};

** Time Complexity :- **
    
Single Iteration Over Array :
The algorithm iterates through the nums array exactly once using a for loop.
At each iteration, it performs a constant number of operations, including comparisons and updates to maxEnd, minEnd, and maxProduct.
Time Complexity: O(n), where n is the size of the input array nums.
Swapping and Updating Values :
Swapping maxEnd and minEnd when the current number is negative is a constant time operation.
Updating the maximum and minimum products involves computing the product and taking the max or min, which are also constant time operations.
Time Complexity: O(n).
Total Time Complexity : 
Best Case: O(n), even if the array has no negative values or all elements are the same, as the algorithm still iterates through the array.
Worst Case: O(n), regardless of the presence of negative values or zeros.

** Space Complexity :- **
    
In-Place Computation :
The algorithm uses only a few integer variables (maxProduct, maxEnd, minEnd) to keep track of the current state of calculations.
It does not use any additional data structures like arrays or stacks.
Space Complexity: O(1).
Input Array :
The input array nums is accessed but not modified, so it does not contribute to additional space usage.
Space Complexity: O(1).
Total Space Complexity : O(1).
