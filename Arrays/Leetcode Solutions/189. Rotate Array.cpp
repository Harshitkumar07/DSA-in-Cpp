** Leetcode Problem :- **

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

** Code :- **

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0)
            return;
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

** Time Complexity :- **
    
Reversal Operations : 
The function calls the reverse helper function three times:
First Reversal: Reverses the entire array. This takes O(n), where n is the size of the nums array.
Second Reversal: Reverses the first k elements. This takes O(k).
Third Reversal: Reverses the remaining n−k elements. This takes O(n−k).
Summing these operations: O(n)+O(k)+O(n−k)=O(2n)=O(n)
Modulo Operation :
Calculating k = k % nums.size() is a constant time operation, O(1).
Total Time Complexity :
Best Case: O(n), when k=0 (no rotation is needed, and only modulo is calculated).
Worst Case: O(n), as the algorithm reverses the entire array and subsets.

** Space Complexity :- **
    
In-Place Computation :
The algorithm modifies the array nums directly and uses no additional data structures.
A few integer variables (start, end, and k) are used for calculations.
Total Space Complexity :
Best Case: O(1).
Worst Case: O(1).
