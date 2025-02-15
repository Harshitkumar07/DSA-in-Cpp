** Leetcode Problem 747 :- **

You are given an integer array nums where the largest integer is unique.
Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

Example 1:
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.

Example 2:
Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.

** Code :- **

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIdx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != maxIdx && nums[maxIdx] < 2 * nums[i])
                return -1;
        }
        return maxIdx;
    }
};

** Time Complexity :- **
    
Finding the Maximum Element :
The algorithm first iterates through the array to find the index of the maximum element.
This takes O(n) time, where n is the number of elements in nums.
Checking the Dominant Condition :
The function iterates again through nums to check if the maximum element is at least twice as large as all other elements.
This also takes O(n) time.
Total Time Complexity :
Best Case: O(n) → If the first element is the dominant one, the loop still runs through the entire array.
Worst Case: O(n) → The algorithm always makes two full passes over nums, leading to O(2n) ≈ O(n).

** Space Complexity :- **
    
Auxiliary Variables (maxIdx, i)
The function only uses a few integer variables (maxIdx and i), which require O(1) space.
No Extra Data Structures :
The input array nums is used directly without creating additional storage.
Total Space Complexity :
Best Case: O(1) → The function operates with constant extra space.
Worst Case: O(1) → No additional data structures are used, keeping the space complexity minimal.
