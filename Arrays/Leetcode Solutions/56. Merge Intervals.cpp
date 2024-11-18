** Leetcode Problem 56:- **

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals. 
Return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

** Code :- **

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

** Time Complexity :- **
Sorting Intervals: Sorting the intervals by their start times takes O(nlogn), where n is the number of intervals.
Merging Process: Iterating through the intervals to merge them takes O(n), as each interval is visited once.
Overall: The sorting step dominates, so the total time complexity is: O(nlogn)

** Space Complexity :- **
Sorting: The sorting algorithm may use O(logn) extra space for recursion in Timsort (or other sorting methods).
Result Storage: The merged intervals are stored in a separate list, which in the worst case can hold all n intervals, leading to O(n) space.
Overall: Space complexity is: O(n)
