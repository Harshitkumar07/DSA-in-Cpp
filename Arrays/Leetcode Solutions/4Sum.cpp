** Leetcode Problem 18. :- **

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

** Code :- **

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                int p = j + 1, q = nums.size() - 1;
                while (p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[p] + (long long)nums[q];
                    if (sum < target) {
                        p++;
                    } else if (sum > target) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;
                        while (p < q && nums[p] == nums[p - 1]) 
                            p++;
                        while (p < q && nums[q] == nums[q + 1]) 
                            q--;
                    }
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **

Outer Loops (i and j):
The first loop runs O(n) times for i, and the second loop runs O(n) times for j in the worst case.
Combined, this results in O(n2) iterations.
Two-Pointer Search (p and q):
For each (i,j) pair, the two-pointer technique processes O(n) elements in total.

Overall Time Complexity: O(n3)
Where n is the size of the input array.

** Space Complexity :- **

Sorting: Sorting the array requires O(logn) space due to the sorting algorithm's stack space (if quicksort is used).
Auxiliary Space:
The algorithm uses O(1) additional space for variables and O(k) space for the result, where k is the number of quadruplets.

Overall Space Complexity: O(k+logn)
