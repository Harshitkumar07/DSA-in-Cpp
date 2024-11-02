Leetcode Problem 169:-

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
    
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
    
Code:-

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore's voting algoritm
        int freq = 0; //Frequency of element in array
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }
        return ans;
    }
};

Time Complexity:
The time complexity is O(n) because we iterate through the nums array exactly once. Each iteration performs constant-time operations (updating freq and possibly ans), 
resulting in a linear pass over n elements, where n is the size of nums.

Space Complexity:
The space complexity is O(1) since we use only a fixed amount of extra space for variables (freq and ans). 
No additional data structures are created that depend on the input size, so the space usage remains constant.
