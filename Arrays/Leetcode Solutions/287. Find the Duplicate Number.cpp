** Leetcode Problem 287 :- **

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
    
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3

** Code :- **

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 1, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid)
                    count++;
            }
            if (count > mid)
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};

** Time Complexity : -**

Binary Search Iterations:
The binary search narrows the range [1,n−1] by half in each iteration. Since the range contains n elements, the number of iterations is O(logn).

Counting Elements in the Array:
In each iteration of the binary search, a loop iterates through the array to count elements ≤mid. This takes O(n) time per iteration.
Overall Time Complexity: O(nlogn)

** Space Complexity :- **

The algorithm uses only a few integer variables (start,end,mid,count) and does not require additional data structures.
Overall Space Complexity: O(1)
