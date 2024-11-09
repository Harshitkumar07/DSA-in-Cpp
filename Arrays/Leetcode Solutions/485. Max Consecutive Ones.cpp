** Leetcode Problem 485:- **

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2

** Code :- **

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //Two pointer
        int count = 0;
        int notCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                notCount++;
            } else {
                count = max(count, notCount);
                notCount = 0;
            }
        }
        count = max(count, notCount);
        return count;
    }
};

** Time Complexity: **

The time complexity is O(n) because we iterate through the nums array once. For each element:
If it’s 1, we increment notCount.
If it’s not 1 (i.e., 0), we compare notCount with count and reset notCount to zero.
Since each operation inside the loop takes constant time, the overall time complexity is O(n), where n is the number of elements in nums.

** Space Complexity: **

The space complexity is O(1) because we use only a fixed amount of extra space for variables (count, notCount, and n).
No additional data structures are created, so memory usage remains constant regardless of the input size.
