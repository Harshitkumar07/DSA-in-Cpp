** Code :- **

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

**Time Complexity: **

The time complexity is O(logn) because this function implements a modified binary search. In each iteration, the search space is halved:
The midpoint mid is recalculated, and based on the values at start, mid, and end, the algorithm decides which half of the array to discard.
This results in a logarithmic reduction of the search space with each step.
Since the array is reduced by half each time, the overall time complexity is O(logn), where n is the number of elements in nums.

**Space Complexity: **
  
The space complexity is O(1) because we use only a fixed number of variables (start, end, and mid). 
No additional data structures or recursive calls are used, so memory usage remains constant regardless of the input size.
