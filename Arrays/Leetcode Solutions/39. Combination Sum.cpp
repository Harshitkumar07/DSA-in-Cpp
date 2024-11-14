** Leetcode Problem 39 :- **

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

** Code :- **

class Solution {
public:
    void combSum(int i, int target, vector<int>& arr, vector<int>& comb,
                 vector<vector<int>>& ans, int n) {
        if (i == n) {
            return;
        }
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        if (arr[i] <= target) {
            comb.push_back(arr[i]);
            combSum(i, target - arr[i], arr, comb, ans, n);
            comb.pop_back();
        }
        combSum(i + 1, target, arr, comb, ans, n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        int n = candidates.size();
        combSum(0, target, candidates, comb, ans, n);
        return ans;
    }
};

** Time Complexity: **
The time complexity of this solution is O(2^n) , where n is the size of candidates:

Recursive Calls: The combSum function recursively explores two options at each index i:

Include the candidate: Adds candidates[i] to the current combination and reduces target by candidates[i].
Exclude the candidate: Moves to the next index.
Since this can lead to O(2^n) possible combinations in the worst case, the time complexity is O(2^n).
Filtering Valid Combinations: For each valid combination that sums up to target, a copy of the combination is pushed into ans, which also contributes to the overall complexity.
However, this is generally dominated by the recursive exploration of combinations.

** Space Complexity: **
The space complexity is O(n) for the recursion stack and combination storage:

Recursion Stack: The recursion depth is at most n, the length of the candidates array.
Combination Storage: The comb vector grows up to n elements in depth as combinations are built, and results are stored in ans. 
The number of possible combinations could vary depending on the input, but typically each combination is of length up to n, contributing to additional space use.
