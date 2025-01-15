** Leetcode Problem 674 :- **

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.
A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

Example 1:
Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element 4.

Example 2:
Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. 
Note that it must be strictly increasing.

** Code :- **

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans, cnt = 0, temp = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= temp) {
                ans = max(ans, cnt);
                cnt = 0;
            }
            temp = nums[i];
            cnt += 1;
        }
        return max(ans, cnt);
    }
};

** Time Complexity :- **
    
Single Iteration Over Array :
The algorithm iterates through the nums array exactly once using a single for loop.
At each iteration:
A constant-time comparison (nums[i] <= temp) is performed.
Integer variables ans, cnt, and temp are updated in constant time.
Time Complexity: O(n)
where n is the size of the input array nums.
Best Case: O(n)
The array is strictly increasing, so the loop processes each element without resetting cnt. 
Worst Case: O(n)
The array frequently resets due to non-increasing elements, but each element is processed once.

** Space Complexity :- **
    
In-Place Computation :
The algorithm uses a constant number of integer variables: ans, cnt, temp, and the loop index i.
No additional memory or data structures are allocated.
Space Complexity: O(1)
Input Array :
The input array nums is accessed but not modified, so it does not contribute to additional space usage.
Total Space Complexity: O(1)
