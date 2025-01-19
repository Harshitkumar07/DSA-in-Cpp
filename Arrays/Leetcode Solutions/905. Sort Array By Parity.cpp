** Leetcode Problem 905 :- **

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.
 
Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:
Input: nums = [0]
Output: [0]

** Code :- **

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[left], nums[i]);
                left++;
            }
        }
        return nums;
    }
};

** Time Complexity :- **
    
Single Iteration :
The algorithm iterates through the nums array using a single for loop: O(n) where n is the size of the nums array.
Swapping :
Each swap operation is O(1) and is performed whenever an even number is encountered.
In the worst case, the number of swaps equals the number of even elements in the array.
Total Time Complexity :
Best Case: O(n) if all elements are already in the correct order (all evens followed by all odds).
Worst Case: O(n) as every element is visited exactly once.

** Space Complexity :- **
    
In-Place Rearrangement :
The algorithm rearranges the elements in the nums array in place, requiring: O(1)
additional space.
Auxiliary Variables :
The algorithm uses only one integer variable (left) to keep track of the position for even elements, requiring: O(1)
Total Space Complexity :
Best Case: (1)
Worst Case: O(1)
