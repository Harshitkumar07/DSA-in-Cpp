** Leetcode Problem 1:- **

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

** Code :- **

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans.push_back({nums[i], i});
        }
        sort(ans.begin(), ans.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (ans[i].first + ans[j].first > target) {
                j--;
            } else if (ans[i].first + ans[j].first < target) {
                i++;
            } else {
                return {ans[i].second, ans[j].second};
            }
        }
        return {};
    }
};

** Time Complexity: **
Creating the ans Array: The function first pushes each element from nums along with its index into the ans vector, which takes O(n) time, where n is the number of elements in nums.
Sorting: Sorting the ans vector takes O(nlogn).
Two-Pointer Search: After sorting, the two-pointer search to find the target sum takes O(n), as each pointer moves only once from the start and end toward the middle.
Overall, the time complexity is dominated by the sorting step, resulting in O(nlogn).

** Space Complexity: **
The space complexity is O(n) due to the additional ans vector, which stores each element and its index from the original array.
