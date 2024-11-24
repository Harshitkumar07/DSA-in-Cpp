** Leetcode Problem 35 :- **

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
    
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
    
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

** Code :- **

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};

** Time Complexity :- **
    
Binary Search:
The algorithm performs binary search on the sorted array nums.
In each iteration, the size of the search space is halved.
This takes O(logn), where n is the size of the array.
Overall Time Complexity: O(logn)
    
** Space Complexity :- ** 
    
The algorithm uses only a few integer variables (start, end, mid) and does not allocate additional memory.
Overall Space Complexity: O(1)
