** Leetcode Problem 1984 :- **

You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
Return the minimum possible difference.

Example 1:
Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.

Example 2:
Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.

** Code :- **

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = k - 1, ans = INT_MAX;
        while (j < nums.size()) {
            ans = min(ans, nums[j] - nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};

** Time Complexity :- **
    
Sorting the Array (sort(nums.begin(), nums.end()))
Sorting takes O(n log n) time, where n is the size of nums.
Sliding Window Iteration (while (j < nums.size()))
The loop runs O(n) times, as both i and j traverse nums once.
Each iteration performs a constant-time operation (min(nums[j] - nums[i])).
Total Time Complexity :
Best Case: O(n log n) → Sorting dominates.
Worst Case: O(n log n) → Sorting remains the most expensive operation.
The sliding window contributes only O(n), which is negligible compared to sorting.
Thus, the overall complexity is O(n log n).

** Space Complexity :- **
    
Sorting Space :
If an in-place sorting algorithm is used (like std::sort in C++), the space usage is O(1) (ignoring recursion stack space).
If an additional array were needed (e.g., for merge sort), the space complexity would be O(n).
Extra Variables (i, j, ans).
These require only O(1) space.
Total Space Complexity :
Best Case: O(1) → If sorting is done in-place.
Worst Case: O(n) → If an external sorting algorithm (like merge sort) is used.
Assuming in-place sorting, the overall space complexity is O(1).
