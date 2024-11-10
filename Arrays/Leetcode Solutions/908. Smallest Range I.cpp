** Leetcode Problem 908 :- **

You are given an integer array nums and an integer k.
In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.
The score of nums is the difference between the maximum and minimum elements in nums.
Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

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
Output: 0
Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.
    
** Code :- **

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min = nums[0] + k, max = nums[n - 1] - k;
        int ans = max - min;
        if (n == 1 || ans<0) {
            return 0;
        }
        return ans;
    }
};

** Time Complexity: **
The time complexity is O(nlogn) due to the sorting step sort(nums.begin(), nums.end()).Sorting the array takes O(nlogn).
Calculating min, max, and ans, as well as checking the condition (n == 1 || ans < 0), all take O(1) time.
Therefore, the overall time complexity is dominated by the sorting step, resulting in (nlogn), where n is the number of elements in nums.

** Space Complexity: **
The space complexity is O(1) since we use only a fixed amount of extra space for variables (n, min, max, and ans).
No additional data structures are created, so memory usage remains constant regardless of the input size.
