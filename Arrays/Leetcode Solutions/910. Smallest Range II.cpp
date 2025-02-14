** Leetcode Problem 910:- **

You are given an integer array nums and an integer k.
For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
The score of nums is the difference between the maximum and minimum elements in nums.
Return the minimum score of nums after changing the values at each index.

Example 1:
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

Example 2:
Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.

Example 3:
Input: nums = [1,3,6], k = 3
Output: 3
Explanation: Change nums to be [4, 6, 3]. The score is max(nums) - min(nums) = 6 - 3 = 3.

** Code :- **

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; i++) {
            int minH = min(nums[0] + k, nums[i] - k);
            int maxH = max(nums[i - 1] + k, nums[n - 1] - k);
            ans = min(ans, maxH - minH);
        }
        return ans;
    }
};

** Time Complexity: **

The time complexity is O(nlogn) due to the sorting step sort(nums.begin(), nums.end()).Sorting the array takes O(nlogn).
After sorting, the function iterates through nums once (from i = 1 to i = n - 1), which takes O(n).
Inside the loop, calculating minH, maxH, and updating ans each take O(1) time.
Thus, the total time complexity is dominated by the sorting step, resulting in O(nlogn), where n is the number of elements in nums.

** Space Complexity: **
    
The space complexity is O(1) because we only use a fixed amount of extra space for variables (n, ans, minH, and maxH). 
No additional data structures are created, so memory usage remains constant regardless of the input size.
