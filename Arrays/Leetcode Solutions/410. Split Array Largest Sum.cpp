** Leetcode problem 410:- **

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

** Code :- **

class Solution {
public:
    bool isValid(vector<int>& arr, int n, int m, int maxAllowed) {
        int s = 1, p = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxAllowed)
                return false;
            if (p + arr[i] <= maxAllowed) {
                p += arr[i];
            } else {
                s++;
                p = arr[i];
            }
        }
        return s <= m;
    }
    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();
        if (m > n)
            return -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        int ans = -1, st = 0, end = sum;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(arr, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};

** Time Complexity: **
Binary Search: The binary search on the maxAllowed sum range has a time complexity of O(logS), where S is the sum of all elements in arr.
This is because the range for binary search goes from 0 to sum, and it requires O(logS) steps.
Feasibility Check (isValid function): Each time we call isValid, we iterate through the array arr to determine if a given maxAllowed sum allows for a valid split into m subarrays.
This check takes O(n), where n is the number of elements in arr.
Overall Complexity: Since isValid is called in each step of the binary search, the overall time complexity is O(nlogS).

** Space Complexity: **
The space complexity is O(1) because the function only uses a fixed number of variables (sum, ans, st, end, mid, s, and p) without requiring any additional data structures.
