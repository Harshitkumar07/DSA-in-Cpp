** Problem :- **

Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

1. Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

2. Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.

3. Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

** Code :- **

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int currSum = 0;
        int maxSum = INT_MIN; 
        for (int n : arr) {
            currSum = currSum + n;
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

** Time Complexity :- **
  
Single Pass through the Array:
The algorithm iterates through the array once, processing each element with constant-time operations such as addition, comparison, and assignment.
This takes O(n), where n is the size of the input array arr.

Overall Time Complexity:
The total time complexity is: O(n)

** Space Complexity :- **
  
Auxiliary Variables:
The algorithm uses a few integer variables: currSum, maxSum, and loop iteration variables.
This requires constant space: O(1).
No Additional Data Structures:
The function operates directly on the input array without using extra memory for data structures.

Overall Space Complexity:
The total space complexity is: O(1)
