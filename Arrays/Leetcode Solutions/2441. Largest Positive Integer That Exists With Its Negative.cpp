** Leetcode Problem 2441:- **

Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
Return the positive integer k. If there is no such integer, return -1.

Example 1:
Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.

Example 2:
Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.

Example 3:
Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.

** Code :- **

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxK = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j] == -nums[i]) {
                        maxK = max(maxK, nums[i]);
                        break; 
                    }
                }
            }
        }
        return maxK;
    }
};

** Time Complexity :- **
    
Nested Loop Execution :
The algorithm iterates through the nums array twice in a nested manner.
For each positive element in nums (outer loop), it searches for its negative counterpart in nums (inner loop).
In the worst case, all elements may need to be checked.
Time Complexity: O(n2) where n is the number of elements in nums.
Best Case Scenario :
If a match is found early, the inner loop may terminate early. However, in the worst case, it still requires O(n2) iterations.

** Space Complexity :- **
    
In-Place Computation :
The algorithm uses only a few integer variables (maxK, i, j) to keep track of computations.
No additional data structures are used.
Space Complexity: O(1)
Total Space Complexity :
Best Case: O(1)
Worst Case: O(1) since the memory usage does not grow with the input size.
