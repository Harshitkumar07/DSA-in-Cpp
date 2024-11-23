** Leetcode Problem 55 :- **

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

** Code :- **

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) {
                return false;
            }
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};

** Time Complexity :- **
    
Single Pass Through the Array:
The algorithm iterates through the array once, updating the maxIndex and checking if the current index is reachable.
This takes O(n), where n is the size of the input array nums.
Overall Time Complexity: O(n)

** Space Complexity :- **

The algorithm uses a constant amount of extra space (only the variable maxIndex). It does not use any additional data structures.
Overall Space Complexity: O(1)
