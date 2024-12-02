** Leetcode Problem 75:- **

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

** Code :- **

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

** Time Complexity :- **
    
Single Pass through the Array:
The algorithm uses a single while loop to iterate through the array, which runs until the mid pointer exceeds the high pointer.
At each iteration, constant-time operations (comparison, increment, and swaps) are performed.
The loop processes each element at most once, making the time complexity: O(n)
Here, n is the size of the input array nums.

Overall Time Complexity:
Since there are no nested loops or additional operations that exceed O(n), the total time complexity is: O(n)

** Space Complexity :- **
    
Auxiliary Space:
The algorithm uses only a few integer variables (low, mid, high, and n) for tracking indices and array size, which requires constant space: O(1)
In-Place Sorting:
The sorting is performed directly on the input array without using additional data structures or temporary arrays.

Overall Space Complexity:
The total space complexity is: O(1)
