** Leetcode Problem 1752 :- **

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

** Code :- **

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > (nums[(i + 1) % n])) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};

** Time Complexity :- **
Iterating through the Array:
The algorithm loops through the array once, comparing each element with the next in a circular manner (using modulo). This takes O(n), where n is the size of the nums array.

Overall Time Complexity:
Since the loop runs for all elements, the time complexity is: O(n)
    
** Space Complexity :- **
In-place Computation:
The algorithm uses only a few integer variables (count, n, and the loop index i) and does not require any extra data structures or additional storage.

Overall Space Complexity:
The space complexity is: O(1)
