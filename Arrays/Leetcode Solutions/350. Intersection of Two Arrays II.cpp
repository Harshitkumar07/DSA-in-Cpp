** Leetcode Problem 350 :- **

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

** Code :- **

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int num : nums1) {
            map[num]++;
        }
        for (int num : nums2) {
            if (map[num] > 0) {
                ans.push_back(num);
                map[num]--;
            }
        }
        return ans;
    }
};

** Time Complexity :- **

Building the Hash Map:
For each element in nums1 (of size n), its frequency is stored in an unordered_map.
This operation takes O(n), as inserting into or updating an unordered_map is O(1) on average.
Iterating Over nums2:
For each element in nums2 (of size m), the algorithm checks its presence in the unordered_map and decrements the frequency if it exists.
This lookup and update operation also takes O(1) on average, resulting in O(m) total for iterating through nums2.
Overall Time Complexity: O(n+m)

** Space Complexity :- **

Storage for the unordered_map:
The unordered_map stores all unique elements from nums1, with their frequencies. In the worst case, this requires O(n) space.
Result Storage:
The ans vector stores the intersection of the two arrays, which may hold up to min(n,m) elements in the worst case. This requires O(min(n,m)) space.
Overall Space Complexity: O(n+min(n,m))
