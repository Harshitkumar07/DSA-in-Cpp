** Leetcode Problem 78 :- **

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

** Code :- **

class Solution {
public:
    void createSubset(vector<int>& nums, int index,vector<vector<int>>& ans,
                      vector<int>& subset) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        createSubset(nums, index + 1, ans, subset);
        subset.pop_back();
        createSubset(nums, index + 1, ans, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        createSubset(nums, 0, ans, subset);
        return ans;
    }
};

** Time Complexity :- **
Recursive Subset Generation:

At each index, there are two choices: include the current element or exclude it.
This results in 2 n subsets for an array of size n.
Generating each subset involves traversing its elements, contributing an additional factor of n in the worst case.
Therefore, the time complexity is: O(n⋅2 n )

** Space Complexity :- **
Auxiliary Space:
The recursion stack depth is proportional to the size of the array n, so the auxiliary space is O(n).
Space for Answer Storage:

There are 2 n  subsets, and the total space to store all subsets is proportional to the sum of the lengths of these subsets. This sum is O(n⋅2 n ).
Overall Space Complexity: O(n⋅2 n)
