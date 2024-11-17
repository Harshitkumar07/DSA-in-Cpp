** Leetcode Problem 1:- **

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

** Code :- **

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i], second = target - first;
            if (map.find(second) != map.end()) {
                ans.push_back(i);
                ans.push_back(map[second]);
                break;
            }
            map[first] = i;
        }
        return ans;
    }
};

** Time Complexity **

Iterating Through the Array: The algorithm iterates through the array once, which takes O(n), where n is the number of elements in the array.
Hash Map Operations: Each lookup and insertion operation in an unordered_map takes O(1) on average.
Thus, the overall time complexity is: O(n)
    
** Space Complexity **
The algorithm uses an unordered_map to store the elements and their indices. In the worst case, all elements of the array are stored in the map. Thus, the space complexity is: O(n)
