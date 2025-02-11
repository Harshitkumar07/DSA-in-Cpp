** Leetcode Problem 643  :- **

You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

** Code :- **

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double maxAvg = sum / k;
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            maxAvg = max(maxAvg, sum / k);
        }
        return maxAvg;
    }
};

** Time Complexity :- **
    
Sliding Window Initialization
First, we compute the sum of the first k elements.
This takes O(k) time.
Sliding Window Traversal :
After initializing, we iterate through the remaining elements.
Each iteration updates the sum in O(1) time.
This runs (n - k) times, leading to O(n - k) ≈ O(n).
Total Time Complexity :
O(k) (initial sum calculation) + O(n - k) (sliding window updates) = O(n).
Best Case (O(n)): The same logic applies since we process every element once.
Worst Case (O(n)): The entire array is processed.

** Space Complexity :- **
    
We use only a few extra variables (sum, maxAvg).
The input nums is used directly without extra storage.
Best Case (O(1)): No additional memory.
Worst Case (O(1)): Constant space is used.
