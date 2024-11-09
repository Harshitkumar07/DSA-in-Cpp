** Leetcode Problem 53 :- **

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

** Code :- **

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadane's Algoritm
        int currSum = 0; //current sum
        int maxSum = INT_MIN; //maximum sum
        for (int n : nums) {
            currSum = currSum + n;
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

** Time Complexity: **
The time complexity is O(n) because we iterate through the nums array once. For each element: We add it to currSum, check if currSum is the highest sum encountered so far, and update maxSum if needed.
If currSum becomes negative, we reset it to zero to start a new subarray.
Since each operation inside the loop takes constant time, the total time complexity is O(n), where n is the number of elements in nums.

** Space Complexity: **
The space complexity is O(1) because we only use a fixed amount of extra space for variables (currSum and maxSum). 
No additional data structures are created, so memory usage remains constant regardless of the input size.
