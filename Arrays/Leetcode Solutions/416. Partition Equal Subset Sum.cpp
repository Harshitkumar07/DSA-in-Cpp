** Leetcode Problem 416 :- **

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

** Code :- **

class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        unordered_set<int> allSums;
        allSums.insert(0);
        for (int num : nums) {
            unordered_set<int> newSums;
            for (int sum : allSums) {
                int newSum = sum + num;
                if (newSum == target) {
                    return true;
                }
                if (newSum < target) {
                    newSums.insert(newSum);
                }
            }
            allSums.insert(newSums.begin(), newSums.end());
        }
        return false;
    }
};

** Time Complexity :- **
    
Outer Loop:
The algorithm iterates over all elements in the array nums, so the outer loop runs O(n) times, where n is the size of the array.
Inner Loop:
The inner loop iterates over all current sums stored in allSums.
In the worst case, the size of allSums could grow to include all possible sums of subsets of nums.
The number of subsets is 2n, leading to O(2n) operations in the worst case.
Overall Time Complexity:
Combining the two loops, the time complexity is: O(n⋅2n)
This exponential complexity arises from considering all possible subset sums.

** Space Complexity :- **
    
allSums Storage:
The allSums unordered set stores all unique subset sums that can be generated.
In the worst case, it could store O(2n) sums, as there are 2n subsets of an array of size n.
Additional Variables:
Other variables, such as totalSum, target, and newSums, use O(1) space.
Overall Space Complexity: O(2n)
