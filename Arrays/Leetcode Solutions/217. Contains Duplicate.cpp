** Leetcode Problem 217 :- **

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.
    
Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

** Code :- **

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool ans = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return ans;
    }
};

** Time Complexity :- **

Sorting the Array:
Sorting the array takes O(nlogn), where n is the size of the array.
Checking for Duplicates:
The loop iterates through the array once, which takes O(n).
Overall Time Complexity:
Since sorting dominates, the time complexity is: O(nlogn)
    
** Space Complexity :- **
    
In-Place Sorting:
The sorting operation (using algorithms like quicksort or heapsort) is typically performed in-place, requiring O(1) additional space if the input is mutable.
Overall Space Complexity: O(1)
