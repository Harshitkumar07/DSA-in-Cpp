** Leetcode Problem 414:- **

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

** Code :- **

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int cnt = 1, ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                cnt++;
                ans = nums[i];
            if (cnt == 3)
                return ans;
        }
        return nums[0];
    }
};

** Time Complexity :- **

Sorting:
Sorting the array takes O(nlogn), where n is the size of the array.
Iteration:
The loop through the array takes O(n) time.

Overall Time Complexity: O(nlogn)

** Space Complexity :- **

Auxiliary Space for Sorting:
Sorting requires O(n) additional space for internal operations.
Variables:
Constant space is used for the cnt and ans variables.

Overall Space Complexity: O(n)
