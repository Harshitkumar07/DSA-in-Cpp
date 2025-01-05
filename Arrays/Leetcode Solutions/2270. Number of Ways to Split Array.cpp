** Leetcode Problem :- **

You are given a 0-indexed integer array nums of length n.
nums contains a valid split at index i if the following are true:
The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.

Example 1:
Input: nums = [10,4,-8,7]
Output: 2
Explanation: 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.

Example 2:
Input: nums = [2,3,1,0]
Output: 2
Explanation: 
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The second part is [1,0], and its sum is 1. Since 5 >= 1, i = 1 is a valid split. 
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The second part is [0], and its sum is 0. Since 6 >= 0, i = 2 is a valid split.

** Codde :- **

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, leftSum = 0;
        int ans = 0;
        for (int num : nums) {
            totalSum += num;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum) {
                ans++;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
First Iteration (Calculating totalSum)
The function iterates through the array nums to calculate the totalSum.
Complexity: O(n)
This step is always required regardless of the input size.
Second Iteration (Splitting and Counting)
The function iterates through the array again (up to nums.size() - 1) to calculate leftSum and check the split condition.
At each step, the split condition leftSum >= totalSum - leftSum is evaluated in O(1).
Complexity: O(n)
Total Time Complexity :
Both iterations are linear, so the overall time complexity is: O(n)
This remains the same for both best and worst cases, as the function always iterates through the array twice, regardless of the splits or values.

** Space Complexity :- **

Storage for Variables
Variables such as totalSum, leftSum, and ans require constant space: O(1)
Input Array : The array nums is passed by reference and is not duplicated, so it doesn’t contribute to extra space usage.
Total Space Complexity :
Best Case: O(1)
Minimal space usage since no additional data structures are used.
Worst Case: O(1)
Space complexity remains constant as the input size does not affect the memory requirements.
