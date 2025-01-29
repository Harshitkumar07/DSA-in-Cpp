** Leetcode Problem 2460 :- **

You are given a 0-indexed array nums of size n consisting of non-negative integers.
You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:
If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
After performing all the operations, shift all the 0's to the end of the array.
For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
Return the resulting array.
Note that the operations are applied sequentially, not all at once.

Example 1:
Input: nums = [1,2,2,1,1,0]
Output: [1,4,2,0,0,0]
Explanation: We do the following operations:
- i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
- i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,4,0,1,1,0].
- i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
- i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,2,0,0].
- i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,0,0].
After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].

Example 2:
Input: nums = [0,1]
Output: [1,0]
Explanation: No operation can be applied, we just shift the 0 to the end.

** Code :- **

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};

** Time Complexity :- **
    
First Pass: Doubling Adjacent Elements :
The algorithm iterates through nums once, checking and modifying adjacent elements.
Time Complexity: O(n)
Second Pass: Moving Non-Zero Elements
The algorithm iterates through nums again to shift non-zero elements to the left.
Time Complexity: O(n)
Total Time Complexity :
Best Case: O(n) if no modifications are needed.
Worst Case: O(n) since both passes always iterate through the entire array.

** Space Complexity :- **
    
In-Place Modifications :
The algorithm only uses a few integer variables (i, j) and modifies nums directly without additional storage.
Space Complexity: O(1)
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1) since no extra space is used apart from input storage.
