** Leetcode Problems 1838:- **

The frequency of an element is the number of times it occurs in an array.
You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
Return the maximum possible frequency of an element after performing at most k operations.

Example 1:
Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.

Example 2:
Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.

Example 3:
Input: nums = [3,9,6], k = 2
Output: 1

** Code :- **

class Solution {
public:
    long long maxFrequency(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        long long left = 0, right = 0, n = nums.size(), ans = 0, maxFreq = 0;
        while (right < n) {
            maxFreq += nums[right];
            while (nums[right] * (right - left + 1) > maxFreq + k) {
                maxFreq -= nums[left];
                left += 1;
            }
            ans = max(ans, right - left + 1);
            right = right + 1;
        }
        return ans;
    }
};

** Time Complexity :- **
Sorting the Array:
Sorting the input array nums takes O(nlogn), where n is the size of nums.

Sliding Window:
The sliding window mechanism iterates through the array once. For each step:
Adding elements to maxFreq and adjusting the window (left pointer) are O(1) operations.
The total iterations for the while loop in all steps of the sliding window are proportional to n, as the left pointer moves from 0 to n−1 cumulatively across the iterations.
Thus, the sliding window contributes (n).

Overall Time Complexity:
The algorithm's dominant operation is the sorting step, making the overall complexity: O(nlogn)
    
** Space Complexity :- **
Auxiliary Space:
The algorithm uses a few variables (left, right, maxFreq, ans, etc.) and does not require any additional data structures. Sorting is done in-place in most implementations.

Overall Space Complexity:
The space complexity is: O(1)
