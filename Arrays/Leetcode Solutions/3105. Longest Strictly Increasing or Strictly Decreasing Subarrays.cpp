** Leetcode Problem 3105 :- **

You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing .

Example 1:
Input: nums = [1,4,3,3,2]
Output: 2
Explanation:
The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
Hence, we return 2.

Example 2:
Input: nums = [3,3,3,3]
Output: 1
Explanation:
The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
Hence, we return 1.

Example 3:
Input: nums = [3,2,1]
Output: 3
Explanation:
The strictly increasing subarrays of nums are [3], [2], and [1].
The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
Hence, we return 3.

** Code :- **

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;
        int maxLen = 1, incLen = 1, decLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1; 
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }
            maxLen = max(maxLen, max(incLen, decLen));
        }
        return maxLen;
    }
};

** Time Complexity :- **
    
Iterating Through the Array :
The algorithm iterates over the nums array once using a single for loop that runs from i = 1 to n - 1.
Let n be the length of the input array. The loop runs (n - 1) times, which simplifies to O(n).
Updating Length Counters :
At each iteration, the algorithm compares the current element (nums[i]) with the previous element (nums[i - 1]).
Depending on whether the sequence is increasing or decreasing, it updates either incLen (increasing length) or decLen (decreasing length).
The max() function is used to keep track of the longest monotonic subarray found so far, but this operation runs in O(1) time.
Total Time Complexity :
Since we only perform O(1) operations for each element in the array and iterate through it once, the overall time complexity is O(n).

** Space Complexity :- **
    
In-Place Computation :
The algorithm does not use any extra data structures.
It only uses three integer variables: maxLen, incLen, and decLen, each requiring O(1) space.
Total Space Complexity :
Since the function does not allocate additional memory proportional to the input size, the overall space complexity is O(1).
