** Leetcode Problem 1800 :- **

Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
A subarray is defined as a contiguous sequence of numbers in an array.
A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

Example 3:
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

** Code :- **

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int maxSum = nums[0], currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];
            } else {
                currSum = nums[i];
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

** Time Complexity :- **
    
Iterating Through the Array :
The algorithm iterates over the nums array once using a single for loop that runs from i = 1 to nums.size() - 1.
Let n be the length of the input array. The loop runs (n - 1) times, which simplifies to O(n).
Updating Sum Counters :
At each iteration, the algorithm checks whether the current element (nums[i]) is greater than the previous element (nums[i - 1]).
If true, it adds nums[i] to currSum; otherwise, it resets currSum to nums[i].
The max() function is used to update maxSum, which runs in O(1) time.
Total Time Complexity :
Since we only perform O(1) operations per element and iterate through the array once, the overall time complexity is O(n).

** Space Complexity :- **
    
In-Place Computation :
The algorithm does not use any extra data structures.
It only uses two integer variables: maxSum and currSum, each requiring O(1) space.
Total Space Complexity :
Since the function does not allocate additional memory proportional to the input size, the overall space complexity is O(1).
