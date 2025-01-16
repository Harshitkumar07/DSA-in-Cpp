** Leetcode Problem 977 :- **

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

** Code :- **

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = nums.size() - 1, k = nums.size() - 1;
        while (i <= j) {
            if (nums[i] * nums[i] >= nums[j] * nums[j]) {
                ans[k] = nums[i] * nums[i];
                k--;
                i++;
            } else {
                ans[k] = nums[j] * nums[j];
                k--;
                j--;
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Two-Pointer Traversal :
The algorithm uses a two-pointer approach, where i starts from the left of the array and j from the right.
Both pointers traverse the array once, comparing the squares of the elements at their respective positions.
This traversal is O(n), where n is the size of the input array nums.
Square and Assign Operations :
At each iteration of the while loop, the algorithm computes the square of the current element, compares it, and assigns it to the result array ans.
These operations are constant time (O(1)) for each element.
Total Time Complexity :
Best Case: O(n)
The algorithm always processes each element exactly once.
Worst Case: O(n)
The number of iterations does not vary based on input properties.

** Space Complexity :- **
    
Output Array :
The algorithm creates a new array ans to store the sorted squares of the input.
This array has the same size as the input array, requiring: O(n)
Auxiliary Variables :
The algorithm uses three integer variables (i,j,k) to track indices, which require a constant amount of space O(1)
Total Space Complexity :
Best Case: O(n)
This accounts for the output array.
Worst Case: O(n)
