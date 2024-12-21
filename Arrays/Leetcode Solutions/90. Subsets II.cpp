** Leetcode Problem 90 :- **

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

** Code : -**

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);
        ans.pop_back();
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) 
            idx++;
        getAllSubsets(nums, ans, idx, allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

** Time Complexity :- **
    
Sorting the Input Array:
The input array nums is sorted, which takes O(nlogn), where n is the size of the input array.
Subset Generation:
The recursive function getAllSubsets explores all possible subsets.
In the worst case (no duplicates in the array), the number of subsets is 2n , where n is the size of the input array.
The generation of each subset requires O(n) time for constructing the subset.
Time Complexity for Subset Generation: O(2n⋅n)
Skipping Duplicates:
The while loop skips over duplicate elements, but this adds negligible overhead since duplicates are already grouped due to sorting.
Overall Time Complexity: O(nlogn+2n⋅n)
    
** Space Complexity :- **
    
Recursive Call Stack:
The recursion depth is equal to the size of the input array n, leading to a space complexity of O(n).
Temporary Storage:
The vector ans stores one subset at a time, requiring O(n) space.
The allSubsets vector stores all subsets, requiring O(2n⋅n) space in the worst case.
Overall Space Complexity: O(2n⋅n)
