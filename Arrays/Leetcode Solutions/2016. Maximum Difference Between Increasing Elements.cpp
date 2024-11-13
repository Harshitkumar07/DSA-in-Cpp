** Leetcode Problem 2016 :- **

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
Return the maximum difference. If no such i and j exists, return -1.

Example 1:
Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

Example 2:
Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].

Example 3:
Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

** Code :- **

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 1, maxDiff = -1;
        if (n < 2) {
            return -1;
        }
        while (right < n) {
            if (nums[left] < nums[right]) {
                maxDiff = max(maxDiff, nums[right] - nums[left]);
                right++;
            } else {
                left = right;
                right++;
            }
        }
        return maxDiff;
    }
};

** Time Complexity: **
The time complexity is O(n), where n is the number of elements in nums.

The function uses a two-pointer approach, with the right pointer iterating through each element of nums once.
In each iteration, we either update maxDiff or move left to right when we find a higher minimum value, keeping each pointer moving only once through the array.
Thus, the entire process requires a single traversal, resulting in a time complexity of O(n).

** Space Complexity: **
The space complexity is O(1) since the function only uses a fixed number of variables (n, left, right, and maxDiff). No additional data structures are used, so memory usage is constant.
