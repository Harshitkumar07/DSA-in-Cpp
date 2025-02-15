** Leetcode Problem 628 :- **

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6

** Code :- **

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), p1 = nums[n - 1], p2 = 1, j = n - 1, i = 0;
        while (i < 3) {
            p2 *= nums[j];
            if (i < 2) {
                p1 *= nums[i];
            }
            j--; i++;
        }
        return max(p1, p2);
    }
};

** Time Complexity :- **
    
Sorting the Array :
The function first sorts the array nums using the sort() function, which has a time complexity of O(n log n). Sorting is the most expensive step in this algorithm.
Finding the Maximum Product :
The algorithm computes two potential maximum products:
p1 considers the product of the largest element and the two smallest elements (for handling negative numbers).
p2 considers the product of the three largest elements.
This involves iterating over at most three elements, which takes O(1) time.
Total Time Complexity :
Best Case: O(n log n) → Sorting dominates the complexity, while subsequent calculations run in O(1) time.
Worst Case: O(n log n) → Sorting is always performed before the product calculations.

** Space Complexity :- **
    
Sorting Overhead :
If sort() is implemented using QuickSort, it may require O(log n) space due to recursive function calls.
If HeapSort is used, it operates in O(1) space, as it sorts the array in place.
Auxiliary Variables (p1, p2, i, j, n) :
The function uses a few integer variables, which require O(1) space.
Total Space Complexity :
Best Case: O(1) → If sorting is performed in-place, no additional memory is used beyond the input array.
Worst Case: O(log n) → If QuickSort is used, the recursive calls may take up to O(log n) space in the function call stack.
