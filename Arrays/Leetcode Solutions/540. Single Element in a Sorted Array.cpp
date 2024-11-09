** Leetcode Problem 540 :- **

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10

** Code :- **

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //By Binary Search Method
        int n = nums.size();
        int m = n + 1;
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid == 0 || mid == n - 1) {
                break;
            }
            if (nums[mid] != nums[mid + 1] && nums[mid - 1] != nums[mid]) {
                break;
            }        
            if (mid % 2 == 0) {
                if (nums[mid + 1] == nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid - 1] == nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return nums[mid];
    }
};

Binary Search Method
This method uses a binary search to find the single non-duplicate element in a sorted array where every other element appears twice.

**Time Complexity: **
The time complexity is O(logn), where n is the number of elements in nums.
The search space is halved in each iteration of the binary search. This gives a logarithmic time complexity, as we only consider half of the elements at each step.
**Space Complexity: **
The space complexity is O(1) because we use only a fixed amount of extra space for variables (l, r, and mid). No additional data structures are used.

                          OR

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //By XOR method
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};

XOR Method
This method uses XOR to find the single non-duplicate element.

**Time Complexity: **
The time complexity is O(n) because we iterate through each element in nums once.
XORing all elements together leaves only the unique element since XORing two identical elements cancels them out.

**Space Complexity: **
The space complexity is O(1) because only a single variable, result, is used to store the cumulative XOR result.
