** Leetcode Problem 26:- **

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

** Code :- **

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        if (nums.empty())
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) {
                index++;
                nums[index] = nums[i];
            }
        }
        return index + 1;
    }
};

** Time Complexity **
The time complexity is O(n), where n is the size of the input array nums:

Single Pass: The loop iterates through the array exactly once, comparing each element with the last unique element (nums[index]).
Each comparison and assignment operation (if a unique element is found) takes O(1) time.
Thus, the time complexity is linear in the size of the array.

** Space Complexity **
The space complexity is O(1):

In-Place Modification: The algorithm modifies the array nums in place without using any additional data structures.
Constant Extra Variables: Only a few integer variables (index and i) are used.
