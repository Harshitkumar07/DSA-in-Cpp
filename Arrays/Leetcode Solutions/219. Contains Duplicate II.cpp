** Leetcode Problem 219 :- **

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true
    
Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

** Code :- **

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                if (i - map[nums[i]] <= k) {
                    return true;
                }
            }
            map[nums[i]] = i;
        }
        return false;
    }
};

** Time Complexity : - **
    
Iteration Over the Array:
The for loop iterates through the array once, taking O(n), where n is the size of the array.
Hash Map Operations:
Each operation (insertion and lookup) in the unordered map takes O(1) on average. Hence, for n elements, the total cost remains O(n).
Overall Time Complexity: O(n)
    
** Space Complexity :- **

Hash Map Storage:
The hash map stores up to n key-value pairs (each number in the array mapped to its last index). This requires O(n) space in the worst case.
Overall Space Complexity: O(n)
