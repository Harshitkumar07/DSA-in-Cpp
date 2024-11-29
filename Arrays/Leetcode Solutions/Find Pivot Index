** Leetcode Problem 724:- **

Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0

** Code :- **

class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int sum = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int lsum = 0;
        for (int i = 0; i < n; i++) {
            int rsum = sum - lsum - arr[i];
            if (lsum == rsum) {
                return i;
            }
            lsum += arr[i];
        }
        return -1;
    }
};

** Time Complexity:- **

Building the map:
This step involves iterating through all elements of a. If the size of a is n, this step takes O(n).
Checking elements of b:
This step involves iterating through all elements of b. If the size of b is m, this step takes O(m).
Total time complexity:
The overall time complexity is O(n+m), where:n is the size of vector a.m is the size of vector b.

** Space Complexity:- **

Unordered map:
The unordered_map map stores frequencies of elements from a. In the worst case, all elements in a are unique, so the map will have O(n) space usage.
Other space usage:
A few integer variables are used for iteration, which take O(1) space.
Total space complexity:
The overall space complexity is O(n), where n is the size of vector a.
