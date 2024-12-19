** Leetcode Problem 47 :- **

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1: 
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

** Code :- **

class Solution {
public:
    void perRec(vector<int> nums, vector<vector<int>>& ans, int idx) {
        if (idx >= nums.size()) {
            if (find(ans.begin(), ans.end(), nums) == ans.end()) {
                ans.push_back(nums);
            }
            return;
        }
        for (int j = idx; j < nums.size(); j++) {
            swap(nums[idx], nums[j]);
            perRec(nums, ans, idx + 1);
            swap(nums[idx], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx = 0;
        perRec(nums, ans, idx);
        return ans;
    }
};

** Time Complexity :- **
    
Recursive Calls:
For each position idx, the algorithm iterates over all possible positions j to swap. This means there are n options for idx=0, n−1 options for idx=1, and so on.
The total number of recursive calls is n!, as the recursion generates all permutations of the array.
Checking for Duplicates (find Operation):
For each recursive base case (when idx≥nums.size()), the find operation checks if the current permutation already exists in ans.
In the worst case, this operation takes O(k), where k is the current size of ans. Since there can be at most n! unique permutations, k≤n!, making this check O(n!) at each leaf node.
There are n! leaf nodes in the recursion tree, so the cost of checking duplicates is O(n!×n!)=O((n!)2).
Total Time Complexity: O((n!)2)

** Space Complexity :- **
    
Auxiliary Space for Recursion:
The maximum depth of the recursion tree is n, corresponding to the number of elements in nums.
Storage for ans:
The ans vector stores at most n! permutations, with each permutation requiring O(n) space.
Total space for ans is O(n×n!).
Temporary Storage for nums:
The nums array is passed by value during recursion. Each recursive call creates a copy, but the original array's size remains O(n).
Total Space Complexity: O(n×n!)
