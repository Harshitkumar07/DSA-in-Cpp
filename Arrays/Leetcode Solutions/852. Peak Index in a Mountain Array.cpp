** Leetcode Problem 852:- **

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1

** Code :- **

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1, end = arr.size() - 2;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) {
                start = mid = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

** Time Complexity: **
The time complexity is O(logn), where n is the number of elements in arr.

The function employs binary search, which halves the search space in each iteration by adjusting either start or end.
Since binary search operates in O(logn) time, this function completes in O(logn).

** Space Complexity: **
The space complexity is O(1) because the function only uses a fixed number of variables (start, end, and mid) and no additional data structures.
