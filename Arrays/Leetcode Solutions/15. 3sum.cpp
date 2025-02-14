** Leetcode Problem 15 :- **

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. 

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

** Code :- **

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }
        return ans;
    }
};

** Time Complexity :- **

Sorting the Array:
Sorting the array take O(nlogn), where n is the size of the array.
Iterating Over the Array:
The outer loop runs for n elements.

Two-Pointer Search:
For each fixed element from the outer loop, the two-pointer search runs in O(n) time (as pointers move linearly).
Over n iterations of the outer loop, this results in O(n2).
Total Time Complexity:
Sorting: O(nlogn)
Triplet search: O(n2)
Overall: O(n2)

** Space Complexity :- **

Auxiliary Space:
The algorithm uses constant extra space for variables like pointers and indices.
No additional data structures are used beyond the input array and result vector.
Total auxiliary space:O(1)
Output Space: The result vector stores unique triplets. In the worst case, there could be O(n3) unique triplets, but this is not counted towards auxiliary space.

Total Space Complexity: O(1)
