** Leetcode Problem 704 :- **

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

** Code :- **

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                return mid;
            } else {
                if (arr[mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};

** Time Complexity :- **
Binary Search:
In each iteration, the algorithm divides the search range by half:

The number of comparisons made is at most log (n), where n is the size of the array.
Hence, the time complexity is: O(logn)

** Space Complexity :- **
Auxiliary Space:

The algorithm uses a constant amount of space for variables (start, end, mid, etc.).
Overall Space Complexity: O(1)
