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
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != ptr) {
                    swap(nums[i], nums[ptr]);
                }
                ptr++;
            }
        }
    }
};

**Time Complexity:**
The time complexity is O(n) because we iterate through the nums array once. For each element:We check if it’s non-zero, which takes O(1).
If it’s non-zero and at a different position than ptr, we perform a swap, which also takes O(1).
Since each element is processed at most once, the total time complexity is O(n), where n is the number of elements in nums.

**Space Complexity:**
The space complexity is O(1) because we use only a fixed amount of extra space for variables (ptr and i). 
The function modifies nums in place without using any additional data structures, so memory usage does not scale with the size of nums.
