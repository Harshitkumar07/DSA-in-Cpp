** Leetcode Problem 349 :- **

Given two integer arrays nums1 and nums2, return an array of their intersection. 
The intersection of two arrays is defined as the set of elements that are present in both arrays.
Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

** Code :- **

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto num : nums2) {
            if (set.count(num)) {
                ans.push_back(num);
                set.erase(num);
            }
        }
        return ans;
    }
};

** Time Complexity :- **
    
Constructing the Set:
The unordered_set is created from nums1, which takes O(n), where n is the size of nums1.
Iterating Over nums2:
The algorithm iterates through each element in nums2 (of size m), checking if it exists in the set and erasing it when found.
Checking membership and erasing an element in an unordered_set both operate in O(1) on average.
Overall Time Complexity: O(n+m)
Where n is the size of nums1 and m is the size of nums2.

** Space Complexity :- **
    
Storage for the unordered_set:
The unordered_set stores all unique elements from nums1, which requires O(n) space in the worst case.
Result Storage:
The ans vector stores the intersection of the two arrays. In the worst case, it may hold up to min(n,m) elements, requiring O(min(n,m)) space.
Overall Space Complexity: O(n+min(n,m))
Where n is the size of nums1, and m is the size of nums2.
