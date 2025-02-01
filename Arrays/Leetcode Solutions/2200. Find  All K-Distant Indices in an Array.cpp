** Leetcode Problem 2200 :- **

You are given a 0-indexed integer array nums and two integers key and k.
A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.
Return a list of all k-distant indices sorted in increasing order.

Example 1:
Input: nums = [3,4,9,1,3,9,5], key = 9, k = 1
Output: [1,2,3,4,5,6]
Explanation: Here, nums[2] == key and nums[5] == key.
- For index 0, |0 - 2| > k and |0 - 5| > k, so there is no j where |0 - j| <= k and nums[j] == key. Thus, 0 is not a k-distant index.
- For index 1, |1 - 2| <= k and nums[2] == key, so 1 is a k-distant index.
- For index 2, |2 - 2| <= k and nums[2] == key, so 2 is a k-distant index.
- For index 3, |3 - 2| <= k and nums[2] == key, so 3 is a k-distant index.
- For index 4, |4 - 5| <= k and nums[5] == key, so 4 is a k-distant index.
- For index 5, |5 - 5| <= k and nums[5] == key, so 5 is a k-distant index.
- For index 6, |6 - 5| <= k and nums[5] == key, so 6 is a k-distant index.
Thus, we return [1,2,3,4,5,6] which is sorted in increasing order. 

Example 2:
Input: nums = [2,2,2,2,2], key = 2, k = 2
Output: [0,1,2,3,4]
Explanation: For all indices i in nums, there exists some index j such that |i - j| <= k and nums[j] == key, so every index is a k-distant index. 
Hence, we return [0,1,2,3,4].

** Code :- **

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> idx;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) 
                idx.push_back(i);
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int target : idx) {
                if (target - k <= i && i <= target + k) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

** Time Complexity :- **
    
Finding Key Indices :
The first for loop iterates through nums once, storing indices where nums[i] == key. O(n)
Checking Each Element for k-Distance :
The second for loop iterates through nums, and for each element, it checks against every stored index in idx.
If there are m occurrences of key, the worst case is: O(n⋅m) where m ≤ n.
Sorting the Result :
The final sorting operation is O(nlogn) in the worst case.

Total Time Complexity :
Best Case: O(n) if key is rare and minimal comparisons are needed.
Worst Case: O(n2) if key appears frequently, leading to many checks in the second loop.

** Space Complexity :- **
    
Storing Key Indices :
The idx vector stores at most m indices, where m is the number of times key appears. O(m)
Result Storage :
The ans vector stores at most n elements in the worst case. O(n)
Total Space Complexity :
Best Case: O(m) if m is small.
Worst Case: O(n) when most indices are included in ans.
