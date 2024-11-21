** Leetcode Problem 46 :- **

Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

** Code :- **

class Solution {
public:
    void perRec(vector<int>& nums, int currIndex,
                    vector<vector<int>>& ans) {
        if (currIndex == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for (int index = currIndex; index < nums.size(); index++) {
            swap(nums[currIndex], nums[index]);
            perRec(nums, currIndex + 1, ans);
            swap(nums[currIndex], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perRec(nums, 0, ans);
        return ans;
    }
};

** Time Complexity :- **

Recursive Permutation Generation:
At each recursive level, we iterate over the remaining elements. For the first element, there are n choices, for the second element n−1 choices, and so on, resulting in n! permutations.
For each permutation, a copy of the current array is pushed into the answer vector, which takes O(n) time for copying.
Thus, the time complexity is: O(n⋅n!)

** Space Complexity :- **
Auxiliary Space for Recursion:
The recursion depth can go up to n, so the auxiliary stack space is O(n).

Space for Answer Storage:
There are n! permutations, and each permutation is of size n. Therefore, space to store all permutations is O(n⋅n!).
Overall Space Complexity: O(n⋅n!)
