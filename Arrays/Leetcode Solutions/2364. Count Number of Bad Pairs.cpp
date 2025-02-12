** Leetcode Problem 2364 :- **

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
Return the total number of bad pairs in nums.

Example 1:
Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.

Example 2:
Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.

** Code :- **

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size() - 1;
        long long int totalPairs = (n * (n + 1)) / 2, goodPairs = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i] - i) != map.end()) {
                goodPairs = goodPairs + map[nums[i] - i];
            }
            map[nums[i] - i]++;
        }
        return totalPairs - goodPairs;
    }
};

** Time Complexity :- **
    
The algorithm iterates through the nums array while maintaining a frequency map of (nums[i] - i). It calculates the number of "good pairs" and subtracts it from the total possible pairs.
Computing Total Pairs (totalPairs = (n * (n + 1)) / 2)
This is a mathematical formula that runs in O(1) time since it involves a constant number of operations.
Iterating Through the Array (for loop over nums)
The loop runs O(n) times, processing each element exactly once.
Unordered Map Operations (find and update)
The find operation in an unordered map takes O(1) on average.
The update operation (incrementing frequency) also takes O(1) on average.
Since both operations are performed n times, the total complexity remains O(n).
Total Time Complexity :
Best Case: O(n) → If all elements are distinct, minimal map operations occur.
Worst Case: O(n) → If there are frequent hash collisions, the unordered map could degrade, but it remains linear on average.

** Space Complexity :- **
    
The algorithm uses extra space for a hash map that tracks how often (nums[i] - i) appears in the array.
Variable Storage (n, totalPairs, goodPairs)
These use O(1) space since they store only integers.
Unordered Map Storage (unordered_map<int, int> map)
In the worst case, every element in nums has a unique (nums[i] - i) value.
This results in O(n) additional space usage.
Total Space Complexity :
Best Case: O(1) → If all values of (nums[i] - i) are the same, the map size remains small.
Worst Case: O(n) → If all values are distinct, the map grows to store all n elements.
Thus, the overall space complexity is O(n) in the worst case.
