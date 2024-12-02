** Leetocde problem 560:- **

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

** Code :- 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        unordered_map<int, int> map;
        for (int j = 0; j < nums.size(); j++) {
            int val = prefixSum[j] - k;
            if (prefixSum[j] == k)
                cnt++;
            if (map.find(val) != map.end()) {
                cnt += map[val];
            }
            if (map.find(prefixSum[j]) == map.end()) {
                map[prefixSum[j]] == 0;
            }
            map[prefixSum[j]]++;
        }
        return cnt;
    }
};

** Time Complexity :- **
    
Prefix Sum Computation:
The algorithm computes the prefix sum for the array in a single pass using a for loop.
This operation takes O(n), where n is the size of the input array nums.
Second Loop for Counting Subarrays:
The second loop iterates through the nums array to count subarrays whose sum equals k.
For each element, the algorithm performs constant-time operations such as map lookups, updates, and arithmetic.
This loop also takes O(n).

Overall Time Complexity:
The total time complexity is: O(n)+O(n)=O(n)

** Space Complexity :- **
    
Prefix Sum Array:
A separate prefixSum array of size n is created, which requires O(n) space.
Hash Map for Storing Prefix Sums:
The unordered map stores prefix sums and their counts. In the worst case, all prefix sums are unique, requiring space proportional to the size of the array.
This takes O(n) space.

Overall Space Complexity:
The total space complexity is: O(n)+O(n)=O(n)
