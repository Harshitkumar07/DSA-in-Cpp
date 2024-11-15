** Leetcode Problem 40:- **

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[ [1,1,6], [1,2,5], [1,7], [2,6] ]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[ [1,2,2], [5] ]

** Code :- **

class Solution {
public:
    void combSum(vector<vector<int>>& ans, vector<int>& arr,
                 vector<int>& candidates, int target, int ind) {
        if (target == 0) {
            ans.push_back(arr);
            return;
        }
        for (int i = ind; i < candidates.size() && target >= candidates[i];
             i++) {
            if (i == ind || candidates[i] != candidates[i - 1]) {
                arr.push_back(candidates[i]);
                combSum(ans, arr, candidates, target - candidates[i], i + 1);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        combSum(ans, arr, candidates, target, 0);
        return ans;
    }
};

** Time Complexity: **
The time complexity of this solution is O(2^n), where n is the size of candidates:

Recursive Calls: The combSum function recursively explores two paths for each index i:
Include the candidate: Adds candidates[i] to the current combination if it doesn’t duplicate the previous element.
Exclude the candidate: Moves to the next index.
Since this solution avoids duplicates by checking the condition candidates[i] != candidates[i - 1], it efficiently reduces redundant calls but still results in a time complexity of O(2^n) in the worst case due to the need to explore subsets.
Sorting: The sort function initially sorts candidates, which takes O(nlogn) time. 
However, since O(2^n) is generally larger, the sorting step doesn’t affect the overall complexity significantly.

** Space Complexity: **
The space complexity is O(n) for the recursion stack and additional storage for the combinations:

Recursion Stack: The recursion depth is at most n, as the function explores subsets of candidates.
Combination Storage: The arr vector holds up to n elements, and ans stores the final combinations.
Although each combination can use up to n space, the total space for combinations depends on the output size, which is limited by the unique subsets that meet target.
