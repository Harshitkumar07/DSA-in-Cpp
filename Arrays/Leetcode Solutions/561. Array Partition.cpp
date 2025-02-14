** Leetcode Problem 561 :- **

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized.
Return the maximized sum. 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.

Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.

** Code :- **

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                ans += nums[i];
        }
        return ans;
    }
};

** Time Complexity :- **
    
Sorting the Array :
The function first sorts the array nums using the sort() function, which has a time complexity of O(n log n). Sorting is the most time-consuming operation in this function and dominates the overall complexity.
Iterating Over the Array :
After sorting, the function iterates over nums using a for-loop that runs O(n) times. This step only contributes a linear time complexity.
Total Time Complexity :
Best Case: O(n log n) → The sorting operation is the most expensive, and the subsequent iteration does not change the overall complexity.
Worst Case: O(n log n) → Even in the worst case, the function still sorts the array first, leading to the same O(n log n) complexity.

** Space Complexity :- **
    
Sorting Overhead :
If sort() is implemented using QuickSort, it may require O(log n) additional space for recursive function calls in the worst case.
If HeapSort is used, it operates in O(1) space, as it sorts the array in place without extra memory.
Auxiliary Variables (ans, i) :
The function uses a few integer variables (ans, i), which require O(1) space.
Total Space Complexity :
Best Case: O(1) → If sorting is performed in-place, no additional memory is required beyond the input array.
Worst Case: O(log n) → If QuickSort is used, the recursive calls may take up to O(log n) space in the function call stack.
